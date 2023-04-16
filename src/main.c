#include <stdio.h>
#include "termCtrl.h"
#include "demo1.h"
#include "demo2.h"
#include "demo3.h"
#include "demo4.h"

int main(){
	setupConsole();
	tc_cursorInvisible();
	tc_altScreen();

	char c = ' ';
	int quit = 0;
	do{
		tc_clrScreen();
		tc_mvOrigine();

		printf("Quelle demo voulez vous lancé :  \n\n");
		printf("[%s1%s] %scadre recadrer%s\n", TC_lGRN, TC_RES, TC_lCYA, TC_RES);
		printf("[%s2%s] %sliste couleur/style%s\n", TC_lGRN, TC_RES, TC_lCYA, TC_RES);
		printf("[%s3%s] %sloading animation%s\n", TC_lGRN, TC_RES, TC_lCYA, TC_RES);
		printf("[%s4%s] %sloading wheel animation%s\n", TC_lGRN, TC_RES, TC_lCYA, TC_RES);
		printf("[%sq%s] %squitter%s\n", TC_lYEL, TC_RES, TC_lRED, TC_RES);

		tc_mvPos(33, 0);
		c = getchar();

		switch(c){
			case 'q':
				quit = 1;
				break;
			case '1':
				demo1();
				break;
			case '2':
				demo2();
				break;
			case '3':
				demo3();
				break;
			case '4':
				demo4();
				break;
			default:
				break;
		}
	}while (!quit);

	tc_exit_altScreen();
	tc_cursorVisible();
	restoreConsole();
	return 0;
}
