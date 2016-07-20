# parallel-execution-of-behat-command

This is console application wich provides functionality for parallel execution of Behat commands for UNIX based operation systems.

Aplication executes Behat command - bin/behat -p {profile} features/{folder/file.feature}.

{profile} and {folder/file.feature} are entered from the user alongside with the number of process he/she wants to run with the command.

For compilation of the program should be used one of the following command line.

* When using process to handle command execution:
  g++ -std=c++11 ParallelExecutionOfCommands.cpp

* When using threads to handle command execution:
  g++ -std=c++11 ParallelExecutionOfCommands.cpp -pthread

Threre is possibility for parallel and successivly execution of command multiple times.
