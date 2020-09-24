#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
 ******************************************************************************/

/* Created by the course staff of CS223 ULA, Spring 2018.
 * Modified by R. Nicolás Savinelli <rsavinelli@est.frba.utn.edu.ar>
 *
 * Demonstration of common valgrind's memcheck errors.
 * More details can be found at https://valgrind.org/docs/manual/mc-manual.html
 */

/*******************************************************************************
 ******************************************************************************/

/* FROM THE MANUAL:
 * Memcheck is a memory error detector. It can detect the following
 * problems that are common in C and C++ programs.
 *
 * - Accessing memory you shouldn't, e.g. overrunning and underrunning
 *   heap blocks, overrunning the top of the stack, and accessing memory
 *   after it has been freed.
 *
 * - Using undefined values, i.e. values that have not been initialised,
 *   or that have been derived from other undefined values.
 *
 * - Incorrect freeing of heap memory, such as double-freeing heap
 *   blocks, or mismatched use of malloc/new/new[] versus
 *   free/delete/delete[]
 *
 * - Overlapping src and dst pointers in memcpy and related functions.
 *
 * - Passing a fishy (presumably negative) value to the size parameter
 *   of a memory allocation function.
 *
 * - Memory leaks.
 *
 * Problems like these can be difficult to find by other means, often
 * remaining undetected for long periods, then causing occasional,
 * difficult-to-diagnose crashes.
 */

/*******************************************************************************
 ******************************************************************************/

/* HOW TO USE VALGRIND:
 * To get the most out of valgrind's memcheck tool use the following options:
 * --tool=memcheck --leak-check=full
 *
 * It is also highly recommend using the -g3 flag when compiling.
 * This allows valgrind to identify specific lines.
 *
 * COMPILATION EXAMPLE:
 * gcc -Wall -pedantic valgrind_errors.c -g3 -o valgrind_errors.elf
 *
 * VALGRIND USAGE EXAMPLE:
 * valgrind --tool=memcheck --leak-check=full ./valgrind_errors.elf
 */

/*******************************************************************************
 ******************************************************************************/

/* TABLE OF CONTENTS:
 * 1. Memory leak detection
 * 2. Illegal read / Illegal write errors
 * 3. Use of uninitialised values
 * 4. Illegal frees
 */

/*******************************************************************************
 ******************************************************************************/

/* 1. Memory leak detection
 * Memory leaks are from allocating memory for your program but never
 * releasing the memory back to the computer. The computer eventually
 * runs out of RAM to utilize and bad things result.
 *
 * Be warned: valgrind will report where the leaked memory originated
 * from. This is not always where you want to destroy it. For example,
 * if you have a create() function and a destroy() function but forget
 * to pass something to destroy(), valgrind will identify the origin
 * of the leaked memory as create().
 */

void mem_leak() {
	int* i_leak = malloc(5 * sizeof(int));

/* VALGRIND ERROR REPORT -------------------------------------------------
   :
==8655== 20 bytes in 1 blocks are definitely lost in loss record 1 of 1
==8655==    at 0x4C2DB6B: malloc (vg_replace_malloc.c:299)
==8655==    by 0x4005C8: mem_leak (valgrind_errors.c:81) <-- PROBLEM
==8655==    by 0x40071D: main (valgrind_errors.c:238)
   :
----------------------------------------------------------------------- */

    /* SOLUTION: to fix this problem free i_leak at some point */
    
	//free(i_leak);
}

/*******************************************************************************
 ******************************************************************************/

/* 2. Illegal read / Illegal write errors
 * Illegal reads and writes are from trying to read or write to
 * memory that you do not have. This is often an indexing problem, but
 * can also be a problem of attempting to read from an already-freed
 * variable. Since your program attempts to read or write this data in
 * order to utilize it in some way, reading out-of-bounds
 * uninitialized memory will cause the program to take incorrect or
 * unexpected actions and eventually segfault.
 */

void illegal_rdwr () {
    /* Allocates memory for an array of 5 positions: 0 to 4 */
	int* array = malloc(5 * sizeof(int));

	array[5] = 5;			/* Illegal write, there's no array[5] */
	if (array[5] == 5) {	/* Illegal read */
		printf("Hi!\n");
	}

/* VALGRIND ERROR REPORT -------------------------------------------------
==8667== Invalid write of size 4
==8667==    at 0x4005EE: illegal_rdwr (valgrind_errors.c:120) <-- PROBLEM
==8667==    by 0x40071D: main (valgrind_errors.c:241)
==8667==  Address 0x520f054 is 0 bytes after a block of size 20 alloc'd
==8667==    at 0x4C2DB6B: malloc (vg_replace_malloc.c:299)
==8667==    by 0x4005E1: illegal_rdwr (valgrind_errors.c:118)
==8667==    by 0x40071D: main (valgrind_errors.c:241)
==8667== 
==8667== Invalid read of size 4
==8667==    at 0x4005FC: illegal_rdwr (valgrind_errors.c:122) <-- PROBLEM
==8667==    by 0x40071D: main (valgrind_errors.c:241)
==8667==  Address 0x520f054 is 0 bytes after a block of size 20 alloc'd
==8667==    at 0x4C2DB6B: malloc (vg_replace_malloc.c:299)
==8667==    by 0x4005E1: illegal_rdwr (valgrind_errors.c:118)
==8667==    by 0x40071D: main (valgrind_errors.c:241)
==8667== 
Hi			<-- PROGRAM'S OUTPUT
----------------------------------------------------------------------- */

	free(array);
}

/*******************************************************************************
 ******************************************************************************/

/* 3. Use of uninitialised values
 * At some point the program attempts to use a variable that doesn't
 * actually have a value assigned to it. Since it's probably
 * attempting to use the value of the variable, this is bad. The
 * program will sometimes make assumptions in order to continue which
 * results in unexpected behavior.
 */

void uninit0 () {
    /* Allocates memory for an array of 5 positions: 0 to 4 */
	int* array = malloc(5 * sizeof(int));

    //array[2] = 10;

    /* No value was assigned to array[2] */
	if (array[2] > 0) {
		printf("Hi!\n");
	}

/* VALGRIND ERROR REPORT -------------------------------------------------
==8686== Conditional jump or move depends on uninitialised value(s)
==8686==    at 0x40063E: uninit0 (valgrind_errors.c:159) <-- PROBLEM
==8686==    by 0x40071D: main (valgrind_errors.c:246)
----------------------------------------------------------------------- */

/* SOLUTION: Initialize array[2] at some point before the conditional */

/* WHAT'S A CONDITIONAL JUMP?
 * An "if" statement is a type of conditional, in which the computer
 * checks to see if a condition is true or false. For and while loops
 * also do this.
 * In this case, the if statement "jumps" to the then or the else part
 * of the code.
 */

	free(array);
}

void uninit1 () {
    /* Allocates memory for an array of 5 positions: 0 to 4 */    
	int* array = malloc(5 * sizeof(int));

	printf("%d\n", array[2]); /* printf apparently uses a lot of
                               * conditionals. Use gdb if print
                               * statements give you this issue.
                               */

	free(array);
}

void uninit2 () {
	/* If you free an unmalloc'd pointer, you will get this error as well.
     * This ties into error #4. For example:
     */

    /* A pointer named array is declared but not assigned. */
    int* array;

	/* since the pointer doesn't point to any allocated piece of memory 
     * valgrind detects an error when free is called.
     */
    free(array);
}

/*******************************************************************************
 ******************************************************************************/

/* 4. Illegal frees
 * You can only release memory once. Once you've released it, it's
 * gone. Attempting to free that same memory again may cause
 * undefined behavior.
 */

void illegal_free () {
    /* Allocates memory for an array of 5 position: 0 to 4 */    
	int* array = malloc(5 * sizeof(int));
	int* array_1 = array;	/* array_1 points to the same place as array */
	free(array_1);		    /* free the memory that array1 points to */
	free(array);		    /* ... array doesn't point anywhere now! */
						    /* there's nothing to be freed here */

/* VALGRIND ERROR REPORT -------------------------------------------------
==8790== Invalid free() / delete / delete[] / realloc()
==8790==    at 0x4C2ED18: free (vg_replace_malloc.c:530)
==8790==    by 0x40070C: illegal_free (valgrind_errors.c:212) <-- PROBLEM
==8790==    by 0x40071D: main (valgrind_errors.c:251)
==8790==  Address 0x520f040 is 0 bytes inside a block of size 20 free'd
==8790==    at 0x4C2ED18: free (vg_replace_malloc.c:530)
==8790==    by 0x400700: illegal_free (valgrind_errors.c:211)
==8790==    by 0x40071D: main (valgrind_errors.c:251)
==8790==  Block was alloc'd at
==8790==    at 0x4C2DB6B: malloc (vg_replace_malloc.c:299)
==8790==    by 0x4006E8: illegal_free (valgrind_errors.c:209)
==8790==    by 0x40071D: main (valgrind_errors.c:251)
----------------------------------------------------------------------- */

}

/*******************************************************************************
 ******************************************************************************/

int main(void)
{
    printf( ":: Welcome to valgrind_errors.c\n"
            ":: To explore the most common types of valgrind's memcheck errors\n"
            ":: uncomment one by one the function calls on the main function.\n");

	/* 1. Memory leak detection */
	// mem_leak();

	/* 2. Illegal read / Illegal write errors */
	// illegal_rdwr();

	/* 3. Use of uninitialised values */
	//uninit0();
	// uninit1();
	// uninit2();

	/* 4. Illegal frees */
	// illegal_free();
    
    return 0;
}
