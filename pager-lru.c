/*
 * File: pager-lru.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains an lru pageit
 *      implmentation.
 */

#include <stdio.h>  
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) { 
    
    /* This file contains the stub for an LRU pager */
    /* You may need to add/remove/modify any part of this file */

    /* Static vars */
    static int initialized = 0;
    static int tick = 1; // artificial time
    static int timestamps[MAXPROCESSES][MAXPROCPAGES];

    /* Local vars */
    int proctmp;
    int pagetmp;
    int proc;
    int page;

    /* initialize static vars on first run */
    if(!initialized){
	for(proctmp=0; proctmp < MAXPROCESSES; proctmp++){
	    for(pagetmp=0; pagetmp < MAXPROCPAGES; pagetmp++){
		timestamps[proctmp][pagetmp] = 0; 
	    }
	}
	initialized = 1;
    }

    for(proc=0; proc < MAXPROCESSES; proc++){
        //Updating timestamps table with first column as 1
        page = (q[proc].pc/PAGESIZE);
        timestamps[proc][page] = tick;
        
        /* Is process active? */
        if(!q[proc].active){
            //If not active swap out pages 
            for(page=0; page < MAXPROCPAGES; page++){
                pageout(proc, page);
            }
        }
    }

    for(int i = 0; i < MAXPROCESSES; i++){
        for(int j = 0; j < MAXPROCPAGES; j++){
            printf("%d ", timestamps[i][j]);
        }
        printf("\n");
    }
    
    /* TODO: Implement LRU Paging */

    fprintf(stderr, "pager-lru not yet implemented. Exiting...\n");
    exit(EXIT_FAILURE);

    /* advance time for next pageit iteration */
    tick++;
} 
