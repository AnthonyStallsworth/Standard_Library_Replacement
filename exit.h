#include <windows.h>

#ifndef EXIT
#define EXIT

/* Exit the current process */
void exit()
{
	ExitProcess(0);
}

#endif