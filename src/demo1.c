#include <stdio.h>
#include <signal.h>
#include "termCtrl.h"

void drawFrame(){
	tc_clrScreen();

	int col = 0;
	int row = 0;
	tc_getCoord(&col, &row);

	int crow = 1;
	tc_mvPos(1, crow);

	printf("+");
	for (int i=2; i<col; i++){
		printf("-");
	}
	printf("+");

	for (int y=3; y<row; y++){
		tc_mvPos(1, ++crow);
		printf("|");
		for (int i=2; i<col; i++){
			printf(" ");
		}
		printf("|");
	}

	tc_mvPos(1, ++crow);
	printf("+");
	for (int i=2; i<col; i++){
		printf("-");
	}
	printf("+\n");
	printf("[ %s%sSTATUS%s ] %sPress q to close%s", TC_BOLD, TC_YEL, TC_RES, TC_MAG, TC_RES);

	tc_mvPos((col-15)/2, row/2);
	printf("[ %sDICK%s ] %s%s8====D%s",TC_RED, TC_RES, TC_BOLD, TC_YEL, TC_RES);

	fflush(stdout);
}

void demo1(){
	tc_echoOFF();

	signal(SIGWINCH, &drawFrame);
	drawFrame();

	while (getchar() != 'q');

	tc_echoON();
}
