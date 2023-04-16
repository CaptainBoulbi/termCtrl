#include <stdio.h>
#include "termCtrl.h"

void demo2(){
	tc_clrScreen();
	tc_echoOFF();
	tc_mvCursor(0, 0);

	printf("[ %sLIST%s ] color & style :\n\n", TC_lCYA, TC_RES);

	while (getchar() != 'q');

	tc_echoON();
}
