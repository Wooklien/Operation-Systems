/* Quoc Lien (816097211)
*  Masc1434
*  CS570, Summer 2014
*  Assignment #3, Time Viewer with Processes.
*  A3.h 
*/

#include "A3.h"

A3::A3(string runtime) {
	this->runtime = string_to_int(runtime);
	sleep(1);
}

void A3::timers() {
	pid_t pid;
	int status;

	for(int i = 0; i < NUM_PROC; i++) {
		pid = fork();
		if(pid == 0) {
			time_functions(i);
		}
		else if(pid == -1) {
			perror("An error has occured while using fork().");
			exit(-1);
		}
		pids.push_back(pid); // Adds the child pid into the vector.
	}

	if(pid > 0){
		wait(&status); //Waits for count down process to end.
		cout << "Countdown process has ended. Killing all child processes." << endl;
		kill_switch();
		cout << "Terminating Parent Process. Since parent is gone, go get some ice cream and enjoy a job well done :)" << endl;
	}
}

void A3::p_localtime() {
	while(1) {
		current_time = time(0);
		lcl_tm = localtime(&current_time);
		cout << getpid() << " - Current Time - " << padding(lcl_tm->tm_hour,2) << ":" << padding(lcl_tm->tm_min,2) << ":" << padding(lcl_tm->tm_sec,2) << endl;
		sleep(1);
	}
}

void A3::p_uptime() {
	while(1) {
		pid_t pid;
		pid = fork();
		if(pid == 0) {
			execl("/usr/bin/uptime", "uptime", NULL); 
		}
		sleep(5);
	}
}

void A3::p_countdown() {
	int min;
	int seconds;

	while(runtime >= 0) {
		seconds = runtime % 60;
		min = (runtime / 60) % 60;
		cout << getpid() << " - Countdown Timer - " << padding(min, 2) << ":" << padding(seconds, 2) << endl;
		runtime--;
		sleep(1);
	}
}

int A3::string_to_int(string n) {
	stringstream s(n);
	int i;
	s >> i;
	return i;
}

string A3::padding(int num, int width){
	stringstream out;
	out << setw(width) << setfill('0') << num;
	return out.str();
}

void A3::time_functions(int i) {
	switch(i) {
		case 0:
			p_localtime();
			break;
		case 1:
			p_uptime();
			break;
		case 2:
			p_countdown();
			break;
	}
}

void A3::kill_switch() {
	for(unsigned int i = 0; i < pids.size(); i++) {
		cout << "KILLLING PID: " << pids[i] << endl;
		kill(pids[i], SIGKILL); // Sends a kill signal to all child processes.
	}
}

int main(int argc, char* argv[]) {
	string runtime;
	/* Checks for valid number of arguments passed in. */
	if(argc < 2) {
		runtime = "10";
	}
	else {
		runtime = argv[1];
	}

	A3 processor(runtime);
	processor.timers();
}
