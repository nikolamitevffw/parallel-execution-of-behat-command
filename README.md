# parallel-execution-of-behat-command

This is console application wich provides functionality for parallel execution of Behat commands for UNIX based operation systems.

Aplication executes Behat command - bin/behat -p {profile} features/{folder/file.feature}.

{profile} and {folder/file.feature} are entered from the user alongside with the number of process he/she wants to run with the command.

For compilation of the program should be used the following command line:

g++ -std=c++11 ParallelExecutionOfCommands.cpp

