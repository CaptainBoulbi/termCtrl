#include <stdio.h>
#include "termCtrl.h"

void demo5(){
	tc_clrScreen();
	tc_cursorVisible();
	tc_mvOrigine();

	printf("%s%sTIZ%s\n", TC_BOLD, TC_RED, TC_DEF);

	printf("\n%sEntrez q pour quitter : ", TC_lGRN);
	while (getchar() != 'q');
	tc_cursorInvisible();
}
