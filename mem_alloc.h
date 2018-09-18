#include "stdio.h"
#include "exit.h"
#include <windows.h>
#include <strsafe.h>


#ifndef MEM_ALLOC
#define MEM_ALLOC

/************************************
* This is the helper variables that *
* are needed for virtualAlloc       *
************************************/

/* Address of the next page to ask for */
LPTSTR lpNxtPage;

/* Count of pages allocated */
DWORD dwPages = 0;

/* Page size on this computer */
DWORD dwPageSize;

// Base address of the test memory
LPVOID lpvBase;				

/************************************
* This function allocates another   *
* page to memory.                   *
************************************/
void* allocate_page()
{
	SYSTEM_INFO sSysInfo;		// useful information about the system

	GetSystemInfo(&sSysInfo);	// Initialize the structure

	dwPageSize = sSysInfo.dwPageSize;

		lpvBase = VirtualAlloc(
			(LPVOID)lpNxtPage,
			dwPageSize,
			MEM_RESERVE,
			PAGE_READWRITE);

    if (lpvBase == NULL)
    {
    	/* Page allocation failed */
		DWORD error = GetLastError();

		/* Stuff needed for FormatMessage call */
		LPVOID lpMsgBuf;
		LPVOID lpDisplayBuf;
		DWORD dw = GetLastError();
		LPCTSTR lpszFunction = TEXT("VirtualAlloc");

		error = FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dw,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&lpMsgBuf,
			0, NULL);
		
		lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
			(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
		StringCchPrintf((LPTSTR)lpDisplayBuf,
			LocalSize(lpDisplayBuf) / sizeof(TCHAR),
			TEXT("%s failed with error %d: %s"),
			lpszFunction, dw, lpMsgBuf);
		MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
		
		exit();
    }
    else
    {
		/* Increment the page count, and advance lpNxtPage to the next page */
    	dwPages++;
		printf("%d\n", dwPages);
    	lpNxtPage = (LPTSTR) ((PCHAR) lpNxtPage + dwPageSize);
    }

}

#endif