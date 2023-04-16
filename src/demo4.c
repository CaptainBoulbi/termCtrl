#include <stdio.h>
#include "termCtrl.h"

void demo4(){
	tc_clrScreen();
	tc_echoOFF();

	while (1){
		tc_clrScreen();

		tc_mvCursor(0, 0);
		printf("[ %s[%s ]\n", TC_RED, TC_DEF);
		sleep(1);

		tc_mvCursor(0, 0);
		printf("[ %s\\%s ]\n", TC_RED, TC_DEF);
		sleep(1);

		tc_mvCursor(0, 0);
		printf("[ %s%s_%s ]\n", TC_BOLD, TC_RED, TC_RES);
		sleep(1);

		tc_mvCursor(0, 0);
		printf("[ %s/%s ]\n", TC_RED, TC_DEF);
		sleep(1);

		tc_mvCursor(0, 0);
		printf("[ %s]%s ]\n", TC_RED, TC_DEF);
		sleep(1);

		tc_mvCursor(0, 0);
		printf("[ %s\\%s ]\n", TC_RED, TC_DEF);
		sleep(1);

		tc_mvCursor(0, 0);
		printf("[ %s%s‾%s ]\n", TC_BOLD, TC_RED, TC_RES);
		sleep(1);

		tc_mvCursor(0, 0);
		printf("[ %s/%s ]\n", TC_RED, TC_DEF);
		sleep(1);

		tc_echoON();
	}

	tc_echoON();
}
