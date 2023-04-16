/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * the code of termCtrl is ispired by Gregg Ink                    *
 * you can code see his code here :                                *
 * https://gitlab.com/greggink/youtube_episode_control_terminal    *
 * https://gitlab.com/greggink/youtube_episode_terminal_control_2  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef TERMINAL_CONTROL_H
#define TERMINAL_CONTROL_H
#include <stdio.h>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * this part of the code that enables the ANSI escape codes  *
 * was copied from Paul Silisteanu on his site :             *
 * https://solarianprogrammer.com/contact/                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifdef _WIN32 // activate ANSI escape codes on windows
#include <windows.h>

// Some old MinGW/CYGWIN distributions don't define this:
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

static HANDLE stdoutHandle;
static DWORD outModeInit;

static void setupConsole(void) {
	DWORD outMode = 0;
	stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if(stdoutHandle == INVALID_HANDLE_VALUE){
		exit(GetLastError());
	}
	if(!GetConsoleMode(stdoutHandle, &outMode)){
		exit(GetLastError());
	}
	outModeInit = outMode;
	
    // Enable ANSI escape codes
	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if(!SetConsoleMode(stdoutHandle, outMode)){
		exit(GetLastError());
	}	
}

static void restoreConsole(void){
    // Reset colors
    printf("\x1b[0m");	
    // Reset console mode
	if(!SetConsoleMode(stdoutHandle, outModeInit)){
		exit(GetLastError());
	}
}
#else // now for superior OS
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

static void setupConsole(void){}
static void restoreConsole(void){
    // Reset colors
    printf("\x1b[0m");
}

static void tc_getCoord(int *cols, int *rows){
	struct winsize size;
	ioctl(1, TIOCGWINSZ, &size);
	*cols = size.ws_col;
	*rows = size.ws_row;
}
static void tc_echoOFF(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(1, TCSANOW, &term);
}
static void tc_echoON(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ECHO;
	tcsetattr(1, TCSANOW, &term);
}
#endif // activate ANSI escape codes on windows

// style
#define TC_RES "\033[0m"
#define TC_BOLD "\033[1m"
#define TC_ITA "\033[3m"
#define TC_UDL "\033[4m"
#define TC_BIK "\033[5m"
#define TC_SWAP "\033[7m"
#define TC_nBOLD "\033[22m"
#define TC_nITA "\033[23m"
#define TC_nUDL "\033[24m"
#define TC_nBIK "\033[25m"
#define TC_nSWAP "\033[27m"
#define TC_DEF "\033[39m"
#define TC_bDEF "\033[49m"

// forground color
#define TC_BLK "\033[30m"
#define TC_RED "\033[31m"
#define TC_GRN "\033[32m"
#define TC_YEL "\033[33m"
#define TC_BLU "\033[34m"
#define TC_MAG "\033[35m"
#define TC_CYA "\033[36m"
#define TC_WHI "\033[37m"

// light/bright version forground color
#define TC_lBLK "\033[90m"
#define TC_lRED "\033[91m"
#define TC_lGRN "\033[92m"
#define TC_lYEL "\033[93m"
#define TC_lBLU "\033[94m"
#define TC_lMAG "\033[95m"
#define TC_lCYA "\033[96m"
#define TC_lWHI "\033[97m"

// background color
#define TC_bBLK "\033[40m"
#define TC_bRED "\033[41m"
#define TC_bGRN "\033[42m"
#define TC_bYEL "\033[43m"
#define TC_bBLU "\033[44m"
#define TC_bMAG "\033[45m"
#define TC_bCYA "\033[46m"
#define TC_bWHI "\033[47m"

// light/bright version backgroung color
#define TC_blBLK "\033[100m"
#define TC_blRED "\033[101m"
#define TC_blGRN "\033[102m"
#define TC_blYEL "\033[103m"
#define TC_blBLU "\033[104m"
#define TC_blMAG "\033[105m"
#define TC_blCYA "\033[106m"
#define TC_blWHI "\033[107m"

// more precise color
// 8 bit color (see ANSI escape sequences 8 bit color)
#define tc_f8(X) printf("\033[38;5;%dm", X)
#define tc_b8(X) printf("\033[48;5;%dm", X)
// RGB
#define tc_fRGB(R,G,B) printf("\033[38;2;%d;%d;%dm", R, G, B)
#define tc_bRGB(R,G,B) printf("\033[48;2;%d;%d;%dm", R, G, B)

// erase
#define tc_clrScreen() puts("\033[2J")
#define tc_clrToEnd() puts("\033[0J")
#define tc_clrToBeg() puts("\033[1J")
#define tc_clrLine() puts("\033[2K")
#define tc_clrToEndLine() puts("\033[0K")
#define tc_clrToBegLine() puts("\033[1K")

// cursor
#define tc_mvOrigine() puts("\033[H")
#define tc_mvPos(X, Y) printf("\033[%d;%dH", Y, X)
#define tc_mvUp(X) printf("\033[%dA", X)
#define tc_mvDown(X) printf("\033[%dB", X)
#define tc_mvRight(X) printf("\033[%dC", X)
#define tc_mvLeft(X) printf("\033[%dD", X)
#define tc_mvBeginDown(X) printf("\033[%dE", X)
#define tc_mvBeginUp(X) printf("\033[%dF", X)
#define tc_mvCol(X) printf("\033[%dG", X)
#define tc_savePos() puts("\033 7")
#define tc_loadPos() puts("\033 8")
#define tc_cursorInvisible() puts("\033[?25l")
#define tc_cursorVisible() puts("\033[?25h")

// screen
#define tc_altScreen() puts("\033[?1049h\033[H")
#define tc_exit_altScreen() puts("\033[?1049l")
#define tc_saveScreen() puts("\033[?47h")
#define tc_loadScreen() puts("\033[?47l")

#endif // TERMINAL_CONTROL_H