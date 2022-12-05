#include <SDL.h>

#include "system.h"
#include "input.h"

#include "program_main.h"



int main(
	int		argc,
	char**	argv
)
{
	if (!SystemInit()) return 1;

	if (!ProgramInit(argc, argv)) return 1;



	while (!(systeminputs & SYSTEMPINPUT_EXIT))
	{

		UpdateInputs();

		ProgramLoop();

		UpdateWindow();

		framecount++;
	}



	ProgramQuit();

	SystemQuit();

	return 0;
}
