#include <stdio.h>
#include "termCtrl.h"

void process_key(uint64_t c, void *data){
	//ASCII
	if(c == 'q'){
		tc_echo_on();
		tc_canon_on();
		tc_cursorVisible();
		tc_exit_altScreen();
		restoreConsole();
		exit(0);
	}
	if(c >= ' ' && c <= '~'){
		printf("key ASCII %s%c%s\n", TC_RED, (char) c, TC_RES);
		return;
	}
	switch(c){
	case TC_F1:
	case TC_F1_TTY:
		printf("pressed %sFunction Key 1%s\n", TC_RED, TC_RES);
		break;
	case TC_F2:
	case TC_F2_TTY:
		printf("pressed %sFunction Key 2%s\n", TC_RED, TC_RES);
		break;
	case TC_F3:
	case TC_F3_TTY:
		printf("pressed %sFunction Key 3%s\n", TC_RED, TC_RES);
		break;
	case TC_F4:
	case TC_F4_TTY:
		printf("pressed %sFunction Key 4%s\n", TC_RED, TC_RES);
		break;
	case TC_F5:
	case TC_F5_TTY:
		printf("pressed %sFunction Key 5%s\n", TC_RED, TC_RES);
		break;
	case TC_F6:
		printf("pressed %sFunction Key 6%s\n", TC_RED, TC_RES);
		break;
	case TC_F7:
		printf("pressed %sFunction Key 7%s\n", TC_RED, TC_RES);
		break;
	case TC_F8:
		printf("pressed %sFunction Key 8%s\n", TC_RED, TC_RES);
		break;
	case TC_F9:
		printf("pressed %sFunction Key 9%s\n", TC_RED, TC_RES);
		break;
	case TC_F10:
		printf("pressed %sFunction Key 10%s\n", TC_RED, TC_RES);
		break;
	case TC_F11:
		printf("pressed %sFunction Key 11%s\n", TC_RED, TC_RES);
		break;
	case TC_F12:
		printf("pressed %sFunction Key 12%s\n", TC_RED, TC_RES);
		break;
	case TC_ESCAPE:
		printf("pressed %sescape%s\n", TC_RED, TC_RES);
		break;
	case TC_ARROW_UP:
		printf("pressed %sup arrow%skey\n", TC_RED, TC_RES);
		break;
	case TC_ARROW_DOWN:
		printf("pressed %sdown arrow%skey\n", TC_RED, TC_RES);
		break;
	case TC_ARROW_LEFT:
		printf("pressed %sleft arrow%skey\n", TC_RED, TC_RES);
		break;
	case TC_ARROW_RIGHT:
		printf("pressed %sright arrow%skey\n", TC_RED, TC_RES);
		break;
	case TC_TAB:
		printf("pressed %sTAB%s key\n", TC_RED, TC_RES);
		break;
	case TC_RETURN:
		printf("pressed %sReturn%s key\n", TC_RED, TC_RES);
		break;
	case TC_INSERT:
		printf("pressed %sInsert%s key\n", TC_RED, TC_RES);
		break;
	case TC_HOME:
		printf("pressed %sHome%s key\n", TC_RED, TC_RES);
		break;
	case TC_PAGE_UP:
		printf("pressed %sPage Up%s key\n", TC_RED, TC_RES);
		break;
	case TC_DELETE:
		printf("pressed %sDelete%s key\n", TC_RED, TC_RES);
		break;
	case TC_END:
		printf("pressed %sEnd%s key\n", TC_RED, TC_RES);
		break;
	case TC_PAGE_DOWN:
		printf("pressed %sPage Down%s key\n", TC_RED, TC_RES);
		break;
	case TC_EURO:
		printf("pressed %s€%s key\n", TC_RED, TC_RES);
		break;
	case TC_GBP:
		printf("pressed %s£%s\n", TC_RED, TC_RES);
		break;
	default:
		printf("key pressed %s0x%lx%s\n", TC_RED, c, TC_RES);
		break;
	}
	return;
}

void demo5(){
	tc_echo_off();
	tc_clrScreen();
	tc_mvOrigine();
	printf("Enter %sq%s to exit\n", TC_RED, TC_RES);
	tc_init_input( &process_key, NULL);
	while(1){ }
	tc_echo_on();
}
