#include "threads.h"
#include "linked_list.h"
#include "../dynamic_libs/os_functions.h"
#include "../utils/logger.h"

struct node *getAllThreads() {
	struct node *threads = NULL;
	OSThread * currentThread = OSGetCurrentThread();
	log_printf("Thread address: %08x\n", currentThread);
	OSThread * iterationThread = currentThread;
	OSThread * temporaryThread;

	// Follow "previous thread" pointers back to the beginning
	while ((temporaryThread = iterationThread->linkActive.prev) != 0) {
		log_printf("Temporary thread address going backwards: %08x\n", temporaryThread);
		iterationThread = temporaryThread;
	}

	// Now iterate over all threads
	while ((temporaryThread = iterationThread->linkActive.next) != 0) {
		// Grab the thread's address
		log_printf("Temporary thread address going forward: %08x\n", temporaryThread);
		threads = insert(threads, (void *) iterationThread);
		log_printf("Inserted: %08x\n", iterationThread);
		iterationThread = temporaryThread;
	}

	// The previous while would skip the last thread so add it as well
	threads = insert(threads, (void *) iterationThread);
	log_printf("Inserted: %08x\n", iterationThread);

	// The list still has to be reversed to be in correct order
	reverse(&threads);

	return threads;
}