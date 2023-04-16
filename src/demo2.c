#include <stdio.h>
#include "termCtrl.h"

void demo2(){
	tc_clrScreen();
	tc_echoOFF();
	tc_mvCursor(0, 0);

	printf("%s[ %sLIST%s ] color :%s\n\n", TC_blBLK, TC_lCYA, TC_DEF, TC_RES);

	printf("[ %sTC_BLK%s ]\n", TC_BLK, TC_DEF);
	printf("[ %sTC_RED%s ]\n", TC_RED, TC_DEF);
	printf("[ %sTC_GRN%s ]\n", TC_GRN, TC_DEF);
	printf("[ %sTC_YEL%s ]\n", TC_YEL, TC_DEF);
	printf("[ %sTC_BLU%s ]\n", TC_BLU, TC_DEF);
	printf("[ %sTC_MAG%s ]\n", TC_MAG, TC_DEF);
	printf("[ %sTC_CYA%s ]\n", TC_CYA, TC_DEF);
	printf("[ %sTC_WHI%s ]\n", TC_WHI, TC_DEF);

	printf("[ %sTC_lBLK%s ]\n", TC_lBLK, TC_DEF);
	printf("[ %sTC_lRED%s ]\n", TC_lRED, TC_DEF);
	printf("[ %sTC_lGRN%s ]\n", TC_lGRN, TC_DEF);
	printf("[ %sTC_lYEL%s ]\n", TC_lYEL, TC_DEF);
	printf("[ %sTC_lBLU%s ]\n", TC_lBLU, TC_DEF);
	printf("[ %sTC_lMAG%s ]\n", TC_lMAG, TC_DEF);
	printf("[ %sTC_lCYA%s ]\n", TC_lCYA, TC_DEF);
	printf("[ %sTC_lWHI%s ]\n", TC_lWHI, TC_DEF);

	printf("[ %sTC_bBLK%s ]\n", TC_bBLK, TC_bDEF);
	printf("[ %sTC_bRED%s ]\n", TC_bRED, TC_bDEF);
	printf("[ %sTC_bGRN%s ]\n", TC_bGRN, TC_bDEF);
	printf("[ %sTC_bYEL%s ]\n", TC_bYEL, TC_bDEF);
	printf("[ %sTC_bBLU%s ]\n", TC_bBLU, TC_bDEF);
	printf("[ %sTC_bMAG%s ]\n", TC_bMAG, TC_bDEF);
	printf("[ %sTC_bCYA%s ]\n", TC_bCYA, TC_bDEF);
	printf("[ %sTC_bWHI%s ]\n", TC_bWHI, TC_bDEF);

	printf("[ %sTC_blBLK%s ]\n", TC_blBLK, TC_RES);
	printf("[ %sTC_blRED%s ]\n", TC_blRED, TC_RES);
	printf("[ %sTC_blGRN%s ]\n", TC_blGRN, TC_RES);
	printf("[ %sTC_blYEL%s ]\n", TC_blYEL, TC_RES);
	printf("[ %sTC_blBLU%s ]\n", TC_blBLU, TC_RES);
	printf("[ %sTC_blMAG%s ]\n", TC_blMAG, TC_RES);
	printf("[ %sTC_blCYA%s ]\n", TC_blCYA, TC_RES);
	printf("[ %sTC_blWHI%s ]\n", TC_blWHI, TC_RES);

	printf("\n%s[ %sLIST%s ] style :%s\n\n", TC_blBLK, TC_lCYA, TC_DEF, TC_RES);

	printf("[ %sTC_BOLD%s ]\n", TC_BOLD, TC_nBOLD);
	printf("[ %sTC_ITA%s ]\n", TC_ITA, TC_nITA);
	printf("[ %sTC_UDL%s ]\n", TC_UDL, TC_nUDL);
	printf("[ %sTC_BIK%s ]\n", TC_BIK, TC_nBIK);
	printf("[ %s%scolor %sTC_SWAP%s ]%s\n", TC_RED, TC_bBLU, TC_SWAP, TC_nSWAP, TC_RES);
	printf("[ %sforground %sbackground %sdefault forground %sdefault background re%sZet ]\n", TC_RED, TC_bBLU, TC_DEF, TC_bDEF, TC_RES);

	printf("\n%s[ %sLIST%s ] more color :%s\n\n", TC_blBLK, TC_lCYA, TC_DEF, TC_RES);

	printf("[ ");
	tc_f8(5);
	printf("8 bit%s ] couleur ", TC_DEF);
	tc_b8(202);
	printf("8 bit%s\n", TC_bDEF);

	printf("[ ");
	tc_fRGB(0, 255, 128);
	printf("RGB%s ] couleur ", TC_DEF);
	tc_bRGB(255, 128, 0);
	printf("RGB%s\n", TC_bDEF);

	printf("\n%s[ %sQUIT%s ] Press q to quit %s", TC_blBLK, TC_lRED, TC_DEF, TC_RES);
	while (getchar() != 'q');

	tc_echoON();
}
