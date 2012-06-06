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

// --- Defines ---

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\AiKernelFileMappingObject");
TCHAR szMsg[] = TEXT("Message from first process.");

// --- Var ---

HANDLE hMapFile;
LPCTSTR pBuf;

// --- Functions ---

PVOID ShareMem_At(AUInt BufSize)
{
	return (PVOID)MapViewOfFile(hMapFile,   // handle to map object
						FILE_MAP_ALL_ACCESS, // read/write permission
						0,
						0,
						BufSize);

	// Unix: use shmat()
}

HANDLE ShareMem_Get(AUInt Size, LPCSTR Name)
{
	//DWORD BSize;
	//LPCTSTR pBuf;

	//BSize = BufSize;

	return CreateFileMapping(
				 INVALID_HANDLE_VALUE,    // use paging file
				 NULL,                    // default security
				 PAGE_READWRITE,          // read/write access
				 0,                       // maximum object size (high-order DWORD)
				 Size,                   // maximum object size (low-order DWORD)
				 Name);                 // name of mapping object

	// Unix: use shmget()
}

func Semaphore_New()
{
	//CreateFileMapping();

	// Unix: use semget()
	return 0;
}

int ShareMem()
{
	hMapFile = ShareMem_Get(BUF_SIZE, szName);

	if (hMapFile == NULL)
	{
		return -2;
	}

	pBuf = ShareMem_At(BUF_SIZE);

	if (pBuf == NULL)
	{
		CloseHandle(hMapFile);
		return -3;
	}

	/*
	pBuf = (LPTSTR)ShareMem_Get(BUF_SIZE);
	if (pBuf == NULL)
	{
		return -3;
	}
	*/

	/*
	hMapFile = CreateFileMapping(
				 INVALID_HANDLE_VALUE,    // use paging file
				 NULL,                    // default security
				 PAGE_READWRITE,          // read/write access
				 0,                       // maximum object size (high-order DWORD)
				 BUF_SIZE,                // maximum object size (low-order DWORD)
				 szName);                 // name of mapping object

	if (hMapFile == NULL)
	{
		return -2;
	}
	pBuf = (LPTSTR) MapViewOfFile(hMapFile,   // handle to map object
						FILE_MAP_ALL_ACCESS, // read/write permission
						0,
						0,
						BUF_SIZE);
	if (pBuf == NULL)
	{
		CloseHandle(hMapFile);
		return -3;
	}
	*/


	CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));

	return 0;
}

func UnShareMem()
{
	UnmapViewOfFile(pBuf);
	CloseHandle(hMapFile);

	// Unix: use shmctl()

	return 0;
}
