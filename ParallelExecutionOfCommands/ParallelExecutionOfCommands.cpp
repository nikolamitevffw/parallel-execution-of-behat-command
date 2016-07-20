// ParallelExecutionOfCommands.cpp : 
// This aplication aims to provide functionality for parallel execution of Behat commands.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
//#include <unistd.h>
#include <thread>

using namespace std;

int main()
{	
	// Declaration of needed variables.
	int processes_Count;
	char command[128];
	string behat_Profile;
	string behat_Feature_Folder;
	string behat_Bin = "bin/behat -p ";
	string result_Command_String;
	thread thread_Array[100];
	bool parallel_Execution = true;
	
	// Entering values for the variables.
	cout << "Enter number of processes you want to execute: ";
	cin >> processes_Count;
	cout << "Enter Behat profile you want to use: ";
	cin >> behat_Profile;
	cout << "Enter Behat feature folder or file location you want to execute: ";
	cin >> behat_Feature_Folder;

	// Creting command for execution.
	result_Command_String = behat_Bin + behat_Profile + " features/" + behat_Feature_Folder;
	strcpy(command, result_Command_String.c_str());

	cout << "You will execute " << processes_Count << " processes with the following command: " << command << ".\n";

	// Creating threads to handle the command execution.
	for (size_t i = 0; i < processes_Count; i++)
	{
		thread_Array[i] = thread(system, command);
		
	}
	for (size_t i = 0; i < processes_Count; i++)
	{
		thread_Array[i].join();
	}


	//// Creating process for execution of the command.
	//pid_t pids[processes_Count];
	//for (size_t i = 0; i < processes_Count; i++)
	//{
	//	if ((pids[i] = fork()) < 0)
	//	{
	//		perror("Process was unable to be created.");
	//		abort();
	//	}
	//	else if (pids[i] == 0)
	//	{
	//		system(command);
	//		exit(0);
	//	}
	//}

    return 0;
}

