WELCOME TO PROJECT 44

MOTIVATION:
This repository offers users the possibility to solve ODEs with a command line tool.
Of course everybody is welcome to extend the functionalities of this solver.

You can call the executable like this:

	./ODEsolver -f "differential equation" -h stepsize -tn timepoint of solution -v0 "[initial values]" -solver "solver"
	
	
WITH:
	-v0: 	is a vector and its elemnts have to be seperated with ','.
	-h:	is a floating point number.
	-tn: 	is a floating point number.
	-f:	is a string, that contains the function for the highest derivative.
		This function has to given in a special format (please refer INTRICACIES).
    
    
EXAMPLE: 

ODE: y' = y with y0 = 1 and t0 = 0, solve ODE for tn = 5 with stepsize h = 0.1 can be solved with following call:

	./ODEsolver -f "(1*y)" -h 0.1 -tn 5 -v0 "[0, 1]" -solver "Explicit-Euler"
	 
    
MULTI EXECUTION:
It is also possible to execute multiple evaluations with one call, The syntax then looks like this: (The ... are not actually part of the call, they are just a stylistic element to denote you can enter arbitrarily many arguments)

	./ODEsolver -f "diff eq 1; diff eq 2; ..." -h "h1; h2; ..." -tn "t1; t2; ..." -v0 "v1; v2; ..." -solver "solver 1; solver 2; ..."

IMPORTANT: Only the number of evaluation points tn is allowed to differ from the rest. The rest of the arguments will always be interpreted as the specification for one specific solver. 
IF you enter a different number of evaluation points, all evaluation points will be evaluated for each solver.
OTHERWISE each tn belongs to one specific solver.

ME EXAMPLES:

1. Compare the results of Explicit-Euler and Implicit-Euler for t in {1,2,4,8,16}:

		./ODEsolver -f "((0-1)*y);((0-1)*y)" -tn "1;2;4;8;16" -h "0.1;0.1" -v0 "[0,1];[0,1]" -solver "EE;IE"


(INTERESTING, because you can see the property, that EE always underestimates and IE always overestimates the true solution.)

2. Get multiple single results at the same time:

		./ODEsolver -f "(((0-3)*y')-(2*y));((0-1)*y)" -tn "4;3" -h "0.001;0.001" -v0 "[0,2,-3];[0,1]" -solver "EE;IE"
	

This also demonstrates, that higher order ODEs do not pose a problem.
(FOR VERIFICATION: y = e^{-t} + e^{-2t} for the first ODE and y = e^{-t} for the second ODE.)


HELP:

You can also ask for help using the call:
	
	./ODEsolver --help
	
	
INTRICACIES:

Every function (the one that follows the -f option) has to be given in a standardized format.
The standardized format is as follows:

1. There are only pairwise operations:
	- -1 -> (0-1)
	- y -> (1*y)
	
2. Every pairwise operation has to be surrounded by round braces ():
	- a-b -> (a-b)
	
3. Only the braces define the order of execution:
	- a * b+c -> ((a * b)+c)
	- a * b^c -> (a * (b^c))
	
4. Basic functions (like e or ln or the trigonometric functions) have to be applied using the apply-operators "<", ">":
	- sin(a) -> (sin > a) or (a < sin)
	
5. You have access to the following basic functions:
	1. sin
	2. cos
	3. tan
	4. asin
	5. acos
	6. atan
	7. e
	8. ln


FOR THE CODERS:
Of course you can easily extend the ODE-solvers by another ODE solver and you only have to update the ODEsolver file.
Just add another solver, that extends the ODESolver abstract class and overwrite the ()-operator with the desired solver.
ATTENTION: Dont use a constructor that needs different input arguments, this will not work with the make_ODESolver function.
Afterwards just add the solver option to the make_ODESolver function and you are good to go.
	
	
REMARK: The tree visualizer still struggles with node names bigger than one char. So dont be surprised if a y derivative is displayed as y in the tree viz. And dont worry in the background everything works correctly, this affects only the visualization.

BUILD:
Navigate to build directory. Then:

	cmake ../
	make

And execute the executable as explained above.
