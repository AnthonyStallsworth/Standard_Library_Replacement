#include <windows.h>

#ifndef EXIT
#define EXIT

/* Get the Current Process information and EXIT! */
void exit()
{
	ExitProcess(0);
}

#endif