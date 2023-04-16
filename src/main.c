#include <stdio.h>
#include "termCtrl.h"
#include "demo1.h"

int main(){
	setupConsole();
	tc_enter_alt_screen();

	char c = ' ';
	while (c != '1' && c != 'q'){
		tc_clear_screen();
		tc_move_cursor(0, 0);

		printf("Quelle demo voulez vous lancé :  \n\n");
		printf("[%s1%s] %scadre recadrer%s\n", TC_GRN, TC_NRM, TC_CYN, TC_NRM);
		printf("[%sq%s] %squitter%s\n", TC_YEL, TC_NRM, TC_RED, TC_NRM);

		tc_move_cursor(33, 0);
		c = getchar();
	}

	switch(c){
		case 'q':
			break;
		case '1':
			demo1();
		default:
			break;
	}

	tc_exit_alt_screen();
	restoreConsole();
	return 0;
}
