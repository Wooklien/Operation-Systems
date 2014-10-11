/* Quoc Lien (816097211)
*  Masc1434
*  CS570, Summer 2014
*  Assignment #1, Process/Thread Manager with Semaphore.
*  A1.h 
*/

#define THREAD_SIZE 6

#include <pthread.h>
#include <semaphore.h>
#include <fstream>
#include <iostream>

using namespace std;

/* Declaring shared Variables */
sem_t SEM; // Semaphore for blocking and queuing.
ofstream ofs; // Our shared resource. 

class A1 {    
public:
    A1(); /*Default Constructor*/
    /* Creates a file, writes the PID (process id) of the current process
    into the file. */
    void create(char *filename);
    /* Creates Threads, equal to the number of THREAD_SIZE,
    that uses the static write function. */
    void create_sauce(char *filename);
    /* Joins the thread after completing its task. */
    void join();
private:
	pthread_t threads[THREAD_SIZE];
}; 
