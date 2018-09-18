#include "stdio.h"
#include "exit.h"
#include <windows.h>


#ifndef MEM_ALLOC
#define MEM_ALLOC

/************************************
* This is the helper variables that *
* are needed for virtualAlloc       *
************************************/

/* Address of the next page to ask for */
LPVOID next_page;

/* Count of pages allocated */
DWORD page_count = 0;

/* Page size on this computer */
DWORD page_size;

// Base address of the test memory
LPVOID page_base;				

/************************************
* This function allocates another   *
* page to memory.                   *
************************************/
void* allocate_page()
{
	SYSTEM_INFO sys_info;		// useful information about the system

	GetSystemInfo(&sys_info);	// Initialize the structure

	page_size = sys_info.dwPageSize;

	page_base = VirtualAlloc(
		(LPVOID) ((int) next_page * page_count),
		page_size,
		MEM_RESERVE | MEM_COMMIT,
		PAGE_READWRITE);

    if (page_base == NULL)
    {	
		exit();
    }
    else
    {
		/* Increment the page count, and advance lpNxtPage to the next page */
    	page_count++;
		printf("%d\n", page_count);
    	//next_page = (LPVOID) ((PCHAR) next_page + page_size);
    }

}

#endif