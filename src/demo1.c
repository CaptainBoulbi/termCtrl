#include <stdio.h>
#include <signal.h>
#include "demo1.h"
#include "termCtrl.h"

void drawFrame(){
	tc_clear_screen();

	int col = 0;
	int row = 0;
	tc_get_cols_rows(&col, &row);

	int crow = 1;
	tc_move_cursor(1, crow);

	printf("+");
	for (int i=2; i<col; i++){
		printf("-");
	}
	printf("+");

	for (int y=3; y<row; y++){
		tc_move_cursor(1, ++crow);
		printf("|");
		for (int i=2; i<col; i++){
			printf(" ");
		}
		printf("|");
	}

	tc_move_cursor(1, ++crow);
	printf("+");
	for (int i=2; i<col; i++){
		printf("-");
	}
	printf("+\n");
	printf("[ %s%sSTATUS%s ] %sPress q to close%s", TC_BOLD, TC_YEL, TC_NRM, TC_MAG, TC_NRM);

	tc_move_cursor((col-15)/2, row/2);
	printf("[ %sDICK%s ] %s%s8====D%s",TC_RED, TC_NRM, TC_BOLD, TC_YEL, TC_NRM);

	fflush(stdout);
}

void demo1(){
	setupConsole();
	tc_echo_off();

	signal(SIGWINCH, &drawFrame);
	drawFrame();

	while (getchar() != 'q');

	tc_echo_on();
	restoreConsole();
}
