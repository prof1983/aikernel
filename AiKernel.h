/* AiKernel header
 * Author(Prof1983 prof1983@ya.ru)
 * Created(06.06.2012)
 * LastMod(19.06.2012)
 * Version(0.0)
 */

/*! @mainpage AiKernel Main Page
 *
 * @section intro_sec Introduction
 *
 * This is the introduction.
 *
 * @section install_sec Installation
 *
 * @subsection step1 Step 1: Opening the box
 *
 * etc... :)
 */

#ifndef AiKernel_H
#define AiKernel_H

#include "ABase2.h"
#include "AOwlTypes.h"
#include "Model/AOwlOntology.h"

/** Initializes agenda
 *  @return AError value
 */
AError
func Agenda_Init();

/** Initializes AiKernel
 *  @return AError value
 */
AError
func AiKernel_Init();

#endif // AiKernel_H
