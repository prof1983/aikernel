/* AiKernel main
 * Author Prof1983 <prof1983@ya.ru>
 * Created 06.06.2012
 * LastMod 12.11.2012
 */

//#pragma argsused

#include "A.h"
#include "AiKernel"

// ----

AError
func Agenda_Init()
{
	return 0;
}

// ----

AError
func AiKernel_Init()
{
	if (Agenda_Init() < 0) return -2;
	return 0;
}

// ---

typedef struct {
    AEnviroment Enviroment;
    ARunner Runner;
} AEngine_Type;

typedef struct {
    AInt Agents;
} AEnviroment_Type;

AEnviroment
func AiKernel_GetEngineEnviroment(AEngine Engine)
{
    return 0;
}

ARunner
func AiKernel_GetEngineRunner(AEngine Engine)
{
    return 0;
}

// ----

int _libmain(unsigned long reason) {
	return 1;
}
