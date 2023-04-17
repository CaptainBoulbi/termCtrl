#include <stdio.h>
#include "termCtrl.h"

void demo3(){
	tc_clrScreen();
	tc_echoOFF();

	while (1){
		tc_clrScreen();

		tc_mvOrigine();
		printf("[ %sCOMPILE%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sTEST%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sRUN%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sLOADING %s|%s ]\n", TC_lYEL, TC_RED, TC_DEF);
		sleep(1);

		tc_mvOrigine();
		printf("[ %sCOMPILE.%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sTEST.%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sRUN.%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sLOADING %s/%s ]\n", TC_lYEL, TC_RED, TC_DEF);
		sleep(1);

		tc_mvOrigine();
		printf("[ %sCOMPILE..%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sTEST..%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sRUN..%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sLOADING %s-%s ]\n", TC_lYEL, TC_RED, TC_DEF);
		sleep(1);

		tc_mvOrigine();
		printf("[ %sCOMPILE...%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sTEST...%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sRUN...%s ]\n", TC_GRN, TC_DEF);
		printf("[ %sLOADING %s\\%s ]\n", TC_lYEL, TC_RED, TC_DEF);
		sleep(1);
	}

	tc_echoON();
}
