/* AiKernel share mem functions
 * Author Prof1983 <prof1983@ya.ru>
 * Created 06.06.2012
 * LastMod 24.12.2012
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

#include "AiKernelShareMem.h"

// --- Defines ---

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\AiKernelFileMappingObject");
TCHAR szMsg[] = TEXT("Message from first process.");

// --- Var ---

HANDLE hMapFile;
PVOID/*LPCTSTR*/ pBuf;

// --- Functions ---

PVOID
func ShareMem_At(HANDLE hMapFile, AUInt BufSize)
{
	return (PVOID)MapViewOfFile(hMapFile,   // handle to map object
						FILE_MAP_ALL_ACCESS, // read/write permission
						0,
						0,
						BufSize);

	// Unix: use shmat()
}

AError
func ShareMem_Close(HANDLE hMapFile)
{
	if (CloseHandle(hMapFile) == TRUE)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

AError
func ShareMem_Free(PVOID pBuf)
{
	UnmapViewOfFile(pBuf);
	return 0;
}

HANDLE
func ShareMem_Get(AUInt Size, LPCSTR Name)
{
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
	// Unix: use semget()
	return 0;
}

int
func ShareMem()
{
	hMapFile = ShareMem_Get(BUF_SIZE, szName);

	if (hMapFile == NULL)
	{
		return -2;
	}

	pBuf = ShareMem_At(hMapFile, BUF_SIZE);

	if (pBuf == NULL)
	{
		CloseHandle(hMapFile);
		return -3;
	}

	CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));

	return 0;
}

func UnShareMem()
{
	ShareMem_Free(pBuf);
	ShareMem_Close(hMapFile);

	// Unix: use shmctl()

	return 0;
}
