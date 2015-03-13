# CPP
Project in C++, general puzzle solving algorithm used to solve various puzzles


ABSTRACTION:

The framework for the whole project is based on solving the puzzles by searching the tree. To search the tree we use a queue, breadth first search. The algorithm that has been used for the framework to solve different types of puzzles.By passing different classes to this function we can make it solve different problems.
Sure there may be some limitations now but we will make changes to the solution.h file 
as we work on newer problems. Final goal is to make it work with all 4 problems.
The approach used by the generateMoves() is following:

Create an initially empty queue of configurations.
    Insert the initial configuration into the queue.
    While
      the queue is not empty and
      the first configuration in the queue does not meet the goal,
    loop:
        Remove the first configuration from the queue and call it C.
        For each move applicable to C, loop:
          Make the move and enqueue the resulting
          configuration if it has not already been seen.
        end-loop.
    end-loop.
    The acceptable configuration is now at the head of the queue;
    but if the queue is empty, there is no solution to the problem.

    The algorithm has been used from the project page.


We are using a map to store the moves from one state to another. In tree’s perspective a child will be represented by the key and the its parent by the value, as one child can have only one parent node and a key value has be only unique. The solution is finally generated by traversing the map from the goal to the initial configuration. This is done by the displaySol() Method in the solver which return a generic list containing moves from the initial configuration to the final goal configuration. A node can be reached by multiple paths but the shortest path will reach first so once we get to the desired goal we are sure that its the shortest path. 

Apart from the algorithm to solve the puzzle every problem would have it’s own representation of the configurations. But these puzzles have to return similar kind of data structure like vector to represent the configurations and list to represent the final solution. The puzzle.h class is the  abstract interface class of all the puzzles and has methods as follows

virtual	vector<T> getNextConfiguration(T currentConfiguration ):

This method returns the configuration specific to the problem.
e.g in case of clock it would be the next and previous hours in time,
in case of water it would be the moves produced by emptying the container, filling the container and transferring the contents from one container to another etc.


virtual	void displayPaths(std::list<T> temp)

This method displays the list which contains the solution path from the initial configuration to the goal.


virtual	bool isGoal(T configuration)

This function returns true if the configuration found represents the goal.

Clock puzzle:

This is used to get the next configurations. and display the solution. The next configuration would be either incrementing (rotating clockwise) by one or decrementing (rotating anti clockwise by one).

water puzzle:

 For each configuration the next configurations would be either by emptying the containers, filling the containers or by transferring the contents from one container to another.


lloyd puzzle:

For each configuration the next configuration would be exchanging the position of the blank with pieces around it. There can be maximum of four different direction for the blank to move. 

variable clock:

For each configuration the next configuration would have all the different positions achieved by moving the clock by the specified amount of hours it can be increment if possible move is positive and decrement if move is negative. e.g. if current time is 3 and possible changes are 3, -2, 1 then the configuration would return 6, 1, 4 respectively. 



Submission v1.2 Changes made after initial feedback.
The clock puzzle was abstracted using the class puzzle.h
The file puzzle.h represents a general puzzle. We plan to implement each puzzle making them a derived class of puzzle.
The solution.h now takes a puzzle. Using polymorphism we make it behave like a particular puzzle.


 v1.3
The solution and the clock puzzle have been separated and the water puzzle is implemented on same lines.

 v1.4
There displaySol function has been moved to the solution.h which is now generic and returns the list of the path from the initial configuration to the goal for the specific puzzle to display.

v 1.5

The changes in the clock puzzle have been made for zero hour clock it doesn’t show any output instead if checks in the start itself and displays that you cannot have such clock. The clock also displays the solution if the initial configuration is the goal itself.
 The water puzzle gives the solution if goal is zero itself.
lloyd name has been corrected and now it does output to external file, as the reference to output stream has been passed to the variable ‘ostream &os’ which is used in the displayPath function to display on console or onto the external file depending upon the 
options selected.

if there is no solution to any puzzle it just shows an empty string.




Compile using:
g++ -o clock clock.cpp
g++ -o water water.cpp
g++ -o lloyd lloyd.cpp 
g++ -o vclock vclock.cpp
Run using:
./clock 12 (Hours on Clock) 1 (Current Time on clock) 4(Actual Time) 
./water 11(goal) 3 5 7 13 (the rest are the arguments of the capacities of the container in this example it has four containers of 3,5,7,13 )
./lloyd - - (input and output both on the console)
./lloyd - filename (input from console and output to external file)
./lloyd Inputfilename Outputfilename (input from the file e.g.lloyd1.in, lloyd2.in, lloyd3.in and output to any file e.g output.txt, output.in etc )
./vclock 6(hours on the clock can be any value u desire) 3 (current) 7(goal) 2 -2 1 -1 (rest are the values by which you can rotate the clock if its positive then clockwise negative : anti clockwise ) 
