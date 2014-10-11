/* Quoc Lien (816097211)
*  Masc1434
*  CS570, Summer 2014
*  Assignment #3, Time Viewer using Processes
*/

#ifndef A3_H
#define A3_H

#define NUM_PROC 3

#include <iomanip>
#include <iostream>
#include <signal.h>
#include <sys/types.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

vector<pid_t> pids;

class A3 {    
public:
	/* Default Constructor, take an argument runtime in seconds as a parameter. */
    A3(string runtime);
    /* Prints the local time every seconds. */
    void p_localtime();
    /* Forks a new process to run, the uptime program. */
    /* This prints out the uptime of the local system that its running on. */
    void p_uptime();
    /* Uses runtime and counts down, until it reaches 0. */
    /* When it reaches zero, it notifys the parent process. */
    void p_countdown();
    /* Creates forks new processes for the time functions. */
    void timers();
private:
	/*PRVIATE VARIABLES*/
	int runtime;
	time_t current_time;
	struct tm * lcl_tm;

	/*PRIVATE ULTILITY FUNCTIONS*/
	/* Converts string to int. */
	int string_to_int(string n);
	/* Pads the number with extra zeros. */
	string padding(int num, int width);
	/* Case switch for the, localtime, uptime and countdown. */
	void time_functions(int i);
	/* Kills all child processes. */
	void kill_switch();
};

#endif
