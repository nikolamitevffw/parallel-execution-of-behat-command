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

int menu()
{
	// Creting application menu so the user can chose between parallel and successively execution.
	int option;
	cout << "Select one of the following options:" << endl;
	cout << "1 - Parallel execution." << endl;
	cout << "2 - Successively execution." << endl;
	cout << "Selection: ";
	cin >> option;
	if (option<1 || option>2)
	{
		cout << "You have entered incorect option." << endl;
		menu();
	}
	return option;
}

int main()
{	

	// Declaration of needed variables.
	int processes_Count;
	int menu_Option;
	char command[128];
	string behat_Profile;
	string behat_Feature_Folder;
	string behat_Bin = "bin/behat -p ";
	string result_Command_String;
	thread thread_Array[100];
	
	//Getting users prefert execution type.
	menu_Option = menu();

	// Entering values for the variables.
	cout << "Enter number of processes/threads you want to execute: ";
	cin >> processes_Count;
	cout << "Enter Behat profile you want to use: ";
	cin >> behat_Profile;
	cout << "Enter Behat feature folder or file location you want to execute: ";
	cin >> behat_Feature_Folder;

	// Creting command for execution.
	result_Command_String = behat_Bin + behat_Profile + " features/" + behat_Feature_Folder;
	strcpy(command, result_Command_String.c_str());

	cout << "You will execute " << processes_Count << " processes/threads with the following command: " << command << ".\n";

	// Creating threads to handle the command execution.
	if (menu_Option = 1)
	{
		// Parallel execution mode.
		for (size_t i = 0; i < processes_Count; i++)
		{
			thread_Array[i] = thread(system, command);
		}
		for (size_t i = 0; i < sizeof(thread_Array); i++)
		{
			thread_Array[i].join();
			thread_Array[i].detach();
		}
	}
	else
	{	// Successively execution mode.
		for (size_t i = 0; i < processes_Count; i++)
		{
			thread_Array[i] = thread(system, command);
			thread_Array[i].join();
		}
		for (size_t i = 0; i < sizeof(thread_Array); i++)
		{
			thread_Array[i].detach();
		}
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

