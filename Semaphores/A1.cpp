/* Quoc Lien (816097211)
*  Masc1434
*  CS570, Summer 2014
*  Assignment #1, Process/Thread Manager with Semaphore.
*  A1.cpp 
*/

#include "A1.h"

using namespace std;

/* Our write function, opens a file and writes its TID (thread ID) to the file */
static void* write(void* arg) {
	int tid = (int) pthread_self();
	char *filename = (char*) arg;
	for(int i = 0; i < 10; i++) {
		if(tid%2==0) {
			sleep(2); // Sleeping Even threads.
		}
		else {
			sleep(3); // Sleeping Odd threads.
		}
		sem_wait(&SEM); // Down

		/* CRITICAL SECTION */
		ofs.open(filename, ios::app);
		if(ofs.is_open()) {
			ofs << "Thread ID: " << tid << endl;
			cout << "Thread " << tid << " is running..." << endl;
			ofs.close();
		}
		else {
			perror("Unable to open file.");
			exit(-3);
		}
		/* END CRITICAL SECTION */
		sem_post(&SEM); // Up
	}
}

/* Instantiating our semaphore for mutex. */
A1::A1() {
	if(sem_init(&SEM, 0, 1) == -1) {
		perror("Failed to initialize semaphore.");
	}
}

// Creates a file with the filename.
void A1::create(char *filename) {
	if(!ofs.is_open()) {
		ofs.open(filename);
		ofs << "Process ID: " << getpid() << endl;
		ofs.close();
	}
	else {
		perror("Unable to open file.");
		exit(-3);
	}
}

/* Creates Threads equal to the number of THREAD_SIZE using the write function and filename as an argument. */
void A1::create_sauce(char *filename) {
	int rc;
    for(int i = 0; i < THREAD_SIZE; i++) {
    	rc = pthread_create(&threads[i], NULL, write, (void *) filename);

    	if (rc){
         printf("An Error has occurred. Return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
    }
}

/* Joins threads after complete. */
void A1::join() {
	for(int i = 0; i < THREAD_SIZE; i++) {
		pthread_join(threads[i], NULL);
	}
	sem_destroy(&SEM);
}

// Our main function. 
int main(int argc, char* argv[]) {

	/* Checks for valid number of arguments passed in. */
	if(argc < 2) {
		perror("Invalid command line arguments! <FILENAME.txt> ");
		exit(-2);
	}

	char *filename = argv[1];

	A1 sauce;
	sauce.create(filename);
	sauce.create_sauce(filename);
	sauce.join();

	exit(0);
}
