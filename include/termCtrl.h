/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * the code of termCtrl is ispired by Gregg Ink                    *
 * you can code see his code here :                                *
 * https://gitlab.com/greggink/youtube_episode_control_terminal    *
 * https://gitlab.com/greggink/youtube_episode_terminal_control_2  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef TERMINAL_CONTROL_H
#define TERMINAL_CONTROL_H
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

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

	if(stdoutHandle == INVALID_HANDLE_VALUE) {
		exit(GetLastError());
	}
	
	if(!GetConsoleMode(stdoutHandle, &outMode)) {
		exit(GetLastError());
	}

	outModeInit = outMode;
	
    // Enable ANSI escape codes
	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

	if(!SetConsoleMode(stdoutHandle, outMode)) {
		exit(GetLastError());
	}	

	printf("[ \033[1,32mColor Setuped\033[0m ]\n");
}

static void restoreConsole(void) {
    // Reset colors
    printf("\x1b[0m");	
	
    // Reset console mode
	if(!SetConsoleMode(stdoutHandle, outModeInit)) {
		exit(GetLastError());
	}
}
#else
static void setupConsole(void) {}

static void restoreConsole(void) {
    // Reset colors
    printf("\x1b[0m");
}
#endif // activate ANSI escape codes on windows

#define TC_BOLD  "\033[0m"

#define TC_NRM  "\x1B[0m"
#define TC_RED  "\x1B[1;31m"
#define TC_GRN  "\x1B[1;32m"
#define TC_YEL  "\x1B[1;33m"
#define TC_BLU  "\x1B[1;34m"
#define TC_MAG  "\x1B[1;35m"
#define TC_CYN  "\x1B[1;36m"
#define TC_WHT  "\x1B[1;37m"

#define TC_BG_NRM "\x1B[40m"
#define TC_BG_RED " \x1B[41m"
#define TC_BG_GRN "\x1B[42m"
#define TC_BG_YEL "\x1B[43m"
#define TC_BG_BLU "\x1B[44m"
#define TC_BG_MAG "\x1B[45m"
#define TC_BG_CYN "\x1B[46m"
#define TC_BG_WHT "\x1B[47m"

#define tc_clear_screen() puts("\x1B[2J")

#define tc_move_cursor(X, Y) printf("\033[%d;%dH", Y, X)

#define tc_enter_alt_screen() puts("\033[?1049h\033[H")
#define tc_exit_alt_screen() puts("\033[?1049l")

static void tc_get_cols_rows(int *cols, int *rows){
	struct winsize size;
	ioctl(1, TIOCGWINSZ, &size);
	*cols = size.ws_col;
	*rows = size.ws_row;
}

static void tc_echo_off(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(1, TCSANOW, &term);
}

static void tc_echo_on(){

	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ECHO;
	tcsetattr(1, TCSANOW, &term);
}
#endif // TERMINAL_CONTROL_H
