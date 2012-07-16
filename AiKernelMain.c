/* AiKernel main
 * Author Prof1983 <prof1983@ya.ru>
 * Created 06.06.2012
 * LastMod 16.07.2012
 * Version 0.0
 */

//#pragma argsused

#include "A.h"
#include "AiKernel"

// ----

/** Initializes agenda
 *  @return AError value
 */
AError
func Agenda_Init()
{
	return 0;
}

// ----

/** Initializes AiKernel
 *  @return AError value
 */
AError
func AiKernel_Init()
{
	if (Agenda_Init() < 0) return -2;
	return 0;
}

// ----

int _libmain(unsigned long reason) {
	return 1;
}
