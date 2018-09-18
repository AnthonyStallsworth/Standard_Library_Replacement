#include "stdio.h"
#include "exit.h"
#include <windows.h>
#include <strsafe.h>


#ifndef MEM_ALLOC
#define MEM_ALLOC

/************************************
* Returns the last error produced   *
* by the windows API                *
************************************/
DWORD get_error(LPTSTR lpszFunction)
{
	DWORD dw = GetLastError();
	return dw;
}

/************************************
* This is the helper variables that *
* are needed for virtualAlloc       *
************************************/

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
		NULL,
		page_size,
		MEM_RESERVE | MEM_COMMIT,
		PAGE_READWRITE);

    if (page_base == NULL)
    {	
		DWORD dw = get_error((LPTSTR) TEXT("VirtualAlloc"));
		ExitProcess(dw);

    } else {
		
		/* Increment the page count, and advance lpNxtPage to the next page */
    	page_count++;
		printf("%d\n", page_count);
		return page_base;
	}

}

#endif