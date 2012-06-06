/*  AiKernel main
Author(Prof1983 prof1983@ya.ru)
Created(06.06.2012)
LastMod(06.06.2012)
Version(0.0)
*/

#pragma argsused

#define A_BUILD_DLL

#include "AiKernel.h"

func Agenda_Init()
{
	return 0;
}

// ----

func AiKernel_Init()
{
	if (Agenda_Init() < 0) return -2;
	return 0;
}

// ----

int _libmain(unsigned long reason) {
	return 1;
}
