//
// Created by lucas on 02.11.23.
//

#include "FunctionTree.h"
#include <functional>
#include <numeric>
#include <utility>

void function_format_checker(std::string_view& func, std::string_view& operators)
{

    unsigned int n_open_braces{0};
    unsigned int n_close_braces{0};
    unsigned int n_operators{0};

    bool encountered_operator{true};

    for (const char& c : func)
    {
        if (c == '(')
        {
            n_open_braces += 1;
        }
        else if (c == ')')
        {
            n_close_braces += 1;
        }
        else if (operators.find(c) != std::string::npos)
        {
            if (encountered_operator)
            {
                throw std::invalid_argument("At least one operator has either no left or no right side!");
            }
            n_operators += 1;
            encountered_operator = true;
        }
        else if (c == ' ')
        {}
        else
        {
            encountered_operator = false;
        }
    }

    if (n_close_braces != n_open_braces)
    {
        throw std::invalid_argument("Different number of open and close brackets!");
    }
    if (n_open_braces < n_operators)
    {
        throw std::invalid_argument("Not every operator is assigned to a pair of braces ()!");
    }
    if (n_open_braces > n_operators)
    {
        throw std::invalid_argument("More braces than operators were given, please only use functional braces!");
    }

}

//This function computes the height of a tree, if you enter the root of the tree.
int compute_height(struct node * root){

    //Breadth-first stepping procedure.
    //current_lvl stores always the children of the previous lvl.
    std::vector<struct node *> current_lvl;

    //Initialize first lvl with the root. If root is not nullptr.
    //root == nullptr leads to height 0.
    //This is intended since a tree of one node is assumed to have height 1.
    if (root != nullptr) {
        current_lvl.push_back(root);
    }

    //Initialize the height with 0.
    int height = 0;

    //Compute the height of the tree.
    while (!current_lvl.empty()){

        //Since we initialized height with 0, increment has to be at the start of the loop.
        height++;

        //tmp stores the next lvl.
        std::vector<struct node *> tmp;

        //iterate over all nodes in current lvl. And add their children, if they exist, to the next lvl (tmp).
        for (const auto & node : current_lvl){
            if(node->left != nullptr){
                tmp.push_back(node->left);
            }
            if(node->right != nullptr){
                tmp.push_back(node->right);
            }
        }

        //override old lvl (current_lvl) with next lvl(tmp).
        current_lvl = tmp;
    }

    return height;
}


// The block size is only intended for visualization purposes.
// This function calculates the block size. The block sie is the number of adjacent "-"-symbols
// in a specific line(lvl).

// very high complexity, because I am too dumb to come up with an analytic formula.
// but please only touch this function, if you are 100% sure, you know what you are doing.
int compute_block_size(int height){

    // If the height is smaller one, the tree is empty. Entering an empty tree for visualization should result
    // in an error.
    // If height is one, the tree only contains the root, which means there are no children -> no blocks are needed.
    if (height < 1){
        return -1;
    } else if (height == 1){
        return 0;
    }

    // The block size of a line corresponds to the sum over all the previous (smaller) block sizes
    // plus one for every lower lvl. The one represents this guy "|".

    // The block_size_v vector stores all the previous block sizes.
    // The vector is initialized with 1 since this is the block-size at height 2.
    std::vector<int> block_size_v = {1};
    for(int i = 2; i < height; i++){
        int block_size = 0;
        for (const auto & el : block_size_v){
            block_size += el +1;
        }
        block_size_v.push_back(block_size);
    }

    // return the last entry of the block-size vector, since this contains the block size corresponding
    // to the desired height.
    return block_size_v[block_size_v.size()-1];
}


node::node(const std::string &symbol) {
    this->symbol = symbol;
    this->left = nullptr;
    this->right = nullptr;
    this->predecessor = nullptr;
}


// Constructor from existing tree.
FunctionTree::FunctionTree(struct node *root, int& height) {
    this->root = root;
    this->height = height;
}


// Constructor from string.
// It is assumed that every operation/expression is encapsulated in braces (a+b).
// The Innermost braces are executed first.
// The requirement of braces makes prioritization of certain operations meaningless.
// -> there is no need to check, which math operation will be performed.

FunctionTree::FunctionTree(std::string_view& func) {

    // The allowed math operations are defined:
    // +: summation (x+y)
    // -: subtraction (x-y)
    // *: multiplication (x*y)
    // /: division (x/y)
    // ^: exponent (x^y)

    // TODO: unify in one symbols sv.
    const std::string m_symbols = "+-*/^";

    const std::string apply_symbols = "<>";

    std::string_view symbols {m_symbols+apply_symbols};

    try {
        function_format_checker(func, symbols);
    } catch (std::invalid_argument &e)
    {
        throw e;
    }

    // Create root and initialize it with the unnamed symbol '~'.
    root = new node("~");

    // current, describes the node, that is currently being modified.
    // set current to root.
    struct node *current = root;

    // word stores the variable names,
    // even-though the tree can only work with chars, strings are theoretically allowed as input,
    // but will be deprecated to their first char.
    std::string word;

    // loop over every char in func-string.
    for (auto& c : func){

        // ignore spaces.
        if(c == ' '){

        }

        // If we encounter a math symbol this means, we were just looking at the left side of that operation.
        //
        // Further this means current still sits at the left side
        // and word might still contain the name of the left variable. (Only if left side is not an expression itself.)
        else if (m_symbols.find(c) != std::string::npos || apply_symbols.find(c) != std::string::npos) {

            // check if word still stores a name (left side is a variable)
            if (!word.empty()) {

                // current still sits at left side so name left side (current) accordingly.
                current->symbol = word;

                // reset word.
                word = "";
            }

            // move current from left to its parent
            current = current->predecessor;

            // name the parent with the math operator
            current->symbol = c;

            // now move to the right side of the parent
            // because next the right side of the expression will be found in the text.
            current = current->right;

        }


        // If we encounter an '(' we know, that we are going to encounter an expression with a left side,
        // a math operator and a right side.
        //
        // Further we know that, the expression itself is either the root or an already existing left or
        // right side. -> a node for the operator itself was already created.
        //
        // Further we know, that we are going to encounter the left side first.
        else if (c == '('){

            // Create a node for the right side.
            current->right = new node("~");

            // Create a node for the left side.
            current->left = new node("~");

            // Set the parent of the left and right side to the current node (later math operator)
            current->left->predecessor = current;
            current->right->predecessor = current;

            // Set current to left, since the left is going to be encountered first in the string.
            current = current->left;

        }


        // If we encounter a ')' we know, that we just finished with a right side. Either this right-side
        // was a variable then we still need to set the name of the right side and then move to the parent,
        // since this expression is finished. Or this right-side was an expression itself, then we just have
        // to move to the parent.
        else if(c == ')') {

            // check if right-side was variable.
            if (!word.empty()) {

                // deprecate string
                current->symbol = word;

                // reset word
                word = "";
            }

            // move out to parent.
            current = current->predecessor;
        }

        // If the char is neither a brace nor a space nor a math symbol it is assumed to be part
        // of a variable name.
        else {
            word += c;
        }
    }

    // at the end compute the height of the tree.
    height = compute_height(root);

}


// Visualize-tree is a function, that prints a tree with at most two children per node to the
// command line.
// Use this method to check if your function was interpreted correctly.
void FunctionTree::visualize_tree() {

    // If tree does not exist, don't visualize it.
    if (root != nullptr){

        // overall width of the tree.
        int width = 0;

        // This variable stores the block-size.
        // block-size will decrease the further we go down in the tree.
        int block_size = 0;

        // If height is 1, the tree consists only of the root.
        if(height == 1){
            std::cout << root->symbol << std::endl;
            return;
        }

        // If tree is an actual tree, with branches,
        // compute the initial block-size and also the resulting overall width.
        else if (height >= 2){
            block_size = compute_block_size(height);
            width = 4 * block_size + 3;
        }


        // The tree will be passed through depth first.
        // current_lvl stores the current lvl.
        std::vector<struct node *> current_lvl;

        // The first lvl only contains the root.
        current_lvl.push_back(root);

        // To draw the symbols at the right positions, we always store the position
        // of all variables and math symbols of a lvl and also use those positions
        // and the block-size to determine the positions of the symbols in the next lvl.
        std::vector<int> current_lvl_pos;

        // The root sits in the middle of the whole tree.
        current_lvl_pos.push_back((width - 1) / 2);

        // The lines store the output line by line.
        std::vector<std::string> lines;

        // To compute the block-size correctly for all lvls we store the current height.
        int current_height = height;


        // Iterate through tree breadth-first.
        while (!current_lvl.empty()) {

            // Initialize line and next line with only spaces with correct size.
            // line contains the blocks ("-"), and the symbols ("a", "+").
            // next_line only contains the branches "|".
            std::string line(width, ' ');
            std::string next_line(width, ' ');

            // tmp stores all node of the next lvl of the tree
            // and tmp_pos stores the corresponding positions in the visualization.
            std::vector<struct node *> tmp;
            std::vector<int> tmp_pos;


            // iterate over all nodes in the current lvl.
            for (int i = 0; i < current_lvl.size(); i++) {

                // c_node just stores the node we are currently working with
                // and pos stores the corresponding position of the node in the visualization.
                struct node *c_node = current_lvl.at(i);
                int pos = current_lvl_pos.at(i);


                // TODO: replace below by : line[pos] = c_node->symbol[0]; OR make an extension.
                //  Actually i dont like using only one char string would be better
                //  but tree width and branch width needs to be calculated differently
                line[pos] = c_node->symbol[0];

                // check if left node exists.
                if (c_node->left != nullptr) {

                    // only if left node exists draw block (horizontal branch)
                    // of size block-size.
                    std::string block(block_size, '-');
                    line.replace(pos - block_size, block_size, block);

                    // don't forget those '|' in the next line.
                    // (positioned one position further outwards for better looks.
                    next_line[pos - block_size - 1] = '|';

                    // add the left child with position to the next lvl of the breadth-first
                    // procedure.
                    tmp.push_back(c_node->left);
                    tmp_pos.push_back(pos - block_size - 1);

                }

                // check if right node exists.
                // analogous to left.
                if (c_node->right != nullptr) {

                    std::string block(block_size, '-');
                    line.replace(pos + 1, block_size, block);

                    next_line[pos + block_size + 1] = '|';

                    tmp.push_back(c_node->right);
                    tmp_pos.push_back(pos + block_size + 1);

                }

            }

            // overwrite current_lvl + pos with next tree lvl (breadth-first)
            current_lvl = tmp;
            current_lvl_pos = tmp_pos;

            // add written lines to the output.
            lines.push_back(line);
            lines.push_back(next_line);

            current_height--;

            // compute new block-size.
            block_size = compute_block_size(current_height);

        }

        // actually print the output.
        for (auto & line: lines){
            std::cout << line << std::endl;
        }
    }
}

// Destructor of FunctionTree.
// Frees the used memory in a breadth-first manner.
FunctionTree::~FunctionTree() {

    if (root != nullptr){

        // current lvl in breadth-first procedure.
        // initialized with root.
        std::vector<struct node *> current_lvl;
        current_lvl.push_back(root);


        // iterate through tree in breadth-first manner.
        // until lvl is empty.
        while(!current_lvl.empty()) {

            // next lvl in breadth-first procedure.
            std::vector<struct node *> tmp;

            // first add children to next lvl then free node.
            for (auto &node: current_lvl) {

                if (node->right != nullptr) {
                    tmp.push_back(node->right);
                }
                if (node->left != nullptr) {
                    tmp.push_back(node->left);
                }

                delete node;
            }

            // overwrite current lvl with next lvl.
            current_lvl = tmp;

        }
    }
}


// solves the function defined in the tree for the variable initializations as given in the name-value map.
double FunctionTree::solve(std::map<std::string, double> &name_value, struct node * node) {

    // REMARK: not ideal use of math symbols.
    std::string m_symbols = "+-*/^";

    std::string apply_symbols = "<>";

    double num{};

    auto [ptr, ec] = std::from_chars(node->symbol.data(), node->symbol.data() + node->symbol.size(), num);


    // Check if symbol is a math symbol:
    if (m_symbols.find(node->symbol) != std::string::npos){

        // Case 1: math symbol is plus.
        if (node->symbol.size() == 1 && node->symbol[0] == '+'){
            return solve(name_value, node->left) + solve(name_value, node->right);
        }

        // Case 2: math symbol is minus.
        else if (node->symbol.size() == 1 && node->symbol[0] == '-'){
            return solve(name_value, node->left) - solve(name_value, node->right);
        }

        // Case 3: math symbol is multiplication.
        else if (node->symbol.size() == 1 && node->symbol[0] == '*'){
            return solve(name_value, node->left) * solve(name_value, node->right);
        }

        // Case 4: math symbol is division.
        else if (node->symbol.size() == 1 && node->symbol[0] == '/'){
            return solve(name_value, node->left) / solve(name_value, node->right);
        }

        // Case 5: math symbol is exponent.
        // ATTENTION: order matters here!
        else {
            return std::pow(solve(name_value, node->left), solve(name_value, node->right));
        }
    }

    // Case: applying a trigonometric function.
    else if (apply_symbols.find(node->symbol) != std::string::npos){

        // In this case the geometric function is on the right (always at the big end of arrow).
        if (node->symbol.size() == 1 && node->symbol[0] == '<'){
            try
            {
                std::function<double(double)> tri_f = FunctionTree::trigonometric_functions.at(node->right->symbol);
                return tri_f(solve(name_value, node->left));
            }
            catch (std::out_of_range & ex)
            {
                throw;
            }
        }

        // In this case the geometric function is on the left.
        else
        {
            try
            {
                std::function<double(double)> tri_f = FunctionTree::trigonometric_functions.at(node->left->symbol);
                return tri_f(solve(name_value, node->right));
            }
            catch (std::out_of_range & ex)
            {
                throw;
            }
        }
    }

    else if (ec == std::errc() && ptr == (node->symbol.data() + node->symbol.size()))
    {
        return num;
    }
    // If symbol is not math symbol it has to be a variable name.
    else {
        if (auto search = name_value.find(node->symbol); search != name_value.end()) {
            return search->second;
        }
        else
        {
            throw std::out_of_range("Variable " + node->symbol + " is not part of the map. (Cant be initialized)");
        }
    }
}

double FunctionTree::solve(std::map<std::string, double> & name_value) {
    return solve(name_value, root);
}
