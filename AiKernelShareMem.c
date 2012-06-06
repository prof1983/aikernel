/*  AiKernel share mem functions
Author(Prof1983 prof1983@ya.ru)
Created(06.06.2012)
LastMod(06.06.2012)
Version(0.0)
*/

/*
--- ShareMem ---

http://exec.h1.ru/docs/tppcu/4.htm

Problem with Shared Memory (Linux)
http://www.cplusplus.com/forum/unices/5161/

Creating Named Shared Memory
http://msdn.microsoft.com/en-us/library/windows/desktop/aa366551%28v=vs.85%29.aspx
*/

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

#include "ABase2.h"

func ShareMem_At()
{
	// Unix: use shmat()
}

func ShareMem_Get()
{
	// Unix: use shmget()
	return 0;
}

func Semaphore_New()
{
	//CreateFileMapping();

	// Unix: use semget()
	return 0;
}
