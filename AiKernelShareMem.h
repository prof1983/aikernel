/*  AiKernel share mem functions
Author(Prof1983 prof1983@ya.ru)
Created(06.06.2012)
LastMod(06.06.2012)
Version(0.0)
*/

#ifndef AiKernelShareMem_H
#define AiKernelShareMem_H

#include "ABase2.h"

#ifdef __cplusplus
extern "C" {
#endif

PVOID
func ShareMem_At(HANDLE hMapFile, AUInt BufSize);

AError
func ShareMem_Close(HANDLE hMapFile);

AError
func ShareMem_Free(PVOID pBuf);

HANDLE
func ShareMem_Get(AUInt Size, LPCSTR Name);

#ifdef __cplusplus
}
#endif

#endif
