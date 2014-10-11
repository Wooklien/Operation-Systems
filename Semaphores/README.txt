/* Quoc Lien
*  CS570, Summer 2014
*  Assignment #3, Processes with time viewer.
*  README.txt
*/

Included files: 
A3.h
A3.cpp
Makefile
README.txt

::Compile Instructions::
To compile this project, go to the directory where the source code is located.
It is located in a folder called a3. Change directory to this a3 folder. Once there,
type Make to compile the source code to output a executable called a3

Example.
% Make

Make clean will remove all object files. 

::Operating Instruction::
This program requires one command line argument. 
The Runtime in seconds.
Whwere runtime is the amount of time the processes will be running.

Example.
a2 30

this will run the program for 30 seconds.

::Design decisions::
For this project, I wanted everything to be done within the class so that the main
methods only needs to call one method. The timer method, creates and runs
all the processes for each timer functions. I wanted the whole system to be
based on the runtime, so the program ends when runtime is less than 0.

::Extra::
I added a few private functionality features that the functions needed to use.
string_to_int() - converts the string to an int.
padding() - pads an integer with extra 0s for format purposes.

::Deficiencies/Bugs::
I didnt run into any bugs while testing the project. Everything seems to be working correctly.

::Lessons Learned::
I learned how much of a pain can occur when you have a rogue process thats running
on an infinite loop, I learned how to fork and deal with new processes, how to terminate
a process using the kill function. What I think I value the most is the logic and use of the
fork command, and how parent process and child processes interact. 
