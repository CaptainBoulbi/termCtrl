#include <stdio.h>
#include <signal.h>
#include "termCtrl.h"

//int EndOfLine(int w){
//	int col;
//	tc_getCoord(&col, NULL);
//	return (w == col);
//}

void drawHor(int n, char c){
	for (int i=0; i<n; i++){
		printf("%c", c);
	}
}

void drawVer(int n, char c){
	for (int i=0; i<n; i++){
		printf("%c", c);
		tc_mvDown(1);
		tc_mvLeft(1);
	}
}

void drawVerEOF(int n, char c){
	for (int i=0; i<n; i++){
		printf("%c", c);
		tc_mvDown(1);
	}
}

void drawFrame(){
	tc_clrScreen();

	int col = 0;
	int row = 0;
	tc_getCoord(&col, &row);
	tc_mvOrigine();

	printf("%s+%s", TC_lYEL, TC_DEF);
	printf("%s", TC_lGRN);

	drawHor(col-2, '-');
	printf("%s+%s", TC_lYEL, TC_DEF);

	printf("%s", TC_lGRN);
 	drawVer(row-3, '|');

	tc_mvPos(col, 2);
 	drawVerEOF(row-3, '|');
 	
 	tc_mvPos(1, row-1);
	printf("%s+%s", TC_lYEL, TC_DEF);

	printf("%s", TC_GRN);
 	drawHor(col-2, '-');

	printf("%s+%s\n", TC_lYEL, TC_DEF);
 	printf("[ %s%sSTATUS%s ] %sPress q to close%s", TC_BOLD, TC_YEL, TC_RES, TC_MAG, TC_RES);
 
 	tc_mvPos((col-14)/2, row/2);
 	printf("[ %sDICK%s ] %s%s8====D%s",TC_RED, TC_RES, TC_BOLD, TC_YEL, TC_RES);

	fflush(stdout);
}

void demo1(){
	tc_echo_off();

	signal(SIGWINCH, &drawFrame);
	drawFrame();

	while (getchar() != 'q');

	tc_echo_on();
}
