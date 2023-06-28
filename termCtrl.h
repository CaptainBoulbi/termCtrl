// Thanks to :
// https://www.youtube.com/watch?v=31p6xsjqehM
// https://www.youtube.com/watch?v=WcN7ryZYUeQ&t=1020s

#ifndef TERMINAL_CONTROL_H
#define TERMINAL_CONTROL_H
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

static HANDLE stdoutHandle;
static DWORD outModeInit;

void setupConsole(void) {
	DWORD outMode = 0;
	stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if(stdoutHandle == INVALID_HANDLE_VALUE){
		exit(GetLastError());
	}
	if(!GetConsoleMode(stdoutHandle, &outMode)){
		exit(GetLastError());
	}
	outModeInit = outMode;
	
	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if(!SetConsoleMode(stdoutHandle, outMode)){
		exit(GetLastError());
	}	
}

void restoreConsole(void){
    printf("\x1b[0m");	
	if(!SetConsoleMode(stdoutHandle, outModeInit)){
		exit(GetLastError());
	}
} 

#include <stdio.h>
#include <unistd.h>

// TODO
void tc_getCoord(int *cols, int *rows);
void tc_echo_off();
void tc_echo_on();
void tc_canon_on();
void tc_canon_on();

#else

#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

void setupConsole(void){}
void restoreConsole(void){
printf("\x1b[0m");
}

void tc_getCoord(int *cols, int *rows){
	struct winsize size;
	ioctl(1, TIOCGWINSZ, &size);
	*cols = size.ws_col;
	*rows = size.ws_row;
}
void tc_echo_off(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(1, TCSANOW, &term);
}
void tc_echo_on(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ECHO;
	tcsetattr(1, TCSANOW, &term);
}

#endif

// COLOR

#define TC_RES "\033[0m"
#define TC_BOLD "\033[1m"
#define TC_ITA "\033[3m"
#define TC_UDL "\033[4m"
#define TC_BIK "\033[5m"
#define TC_SWAP "\033[7m"
#define TC_HID "\033[8m"
#define TC_STR "\033[9m"
#define TC_DEF "\033[39m"
#define TC_nBOLD "\033[22m"
#define TC_nITA "\033[23m"
#define TC_nUDL "\033[24m"
#define TC_nBIK "\033[25m"
#define TC_nSWAP "\033[27m"
#define TC_nHID "\033[28m"
#define TC_nSTR "\033[29m"
#define TC_bDEF "\033[49m"

#define TC_BLK "\033[30m"
#define TC_RED "\033[31m"
#define TC_GRN "\033[32m"
#define TC_YEL "\033[33m"
#define TC_BLU "\033[34m"
#define TC_MAG "\033[35m"
#define TC_CYA "\033[36m"
#define TC_WHI "\033[37m"

#define TC_lBLK "\033[90m"
#define TC_lRED "\033[91m"
#define TC_lGRN "\033[92m"
#define TC_lYEL "\033[93m"
#define TC_lBLU "\033[94m"
#define TC_lMAG "\033[95m"
#define TC_lCYA "\033[96m"
#define TC_lWHI "\033[97m"

#define TC_bBLK "\033[40m"
#define TC_bRED "\033[41m"
#define TC_bGRN "\033[42m"
#define TC_bYEL "\033[43m"
#define TC_bBLU "\033[44m"
#define TC_bMAG "\033[45m"
#define TC_bCYA "\033[46m"
#define TC_bWHI "\033[47m"

#define TC_blBLK "\033[100m"
#define TC_blRED "\033[101m"
#define TC_blGRN "\033[102m"
#define TC_blYEL "\033[103m"
#define TC_blBLU "\033[104m"
#define TC_blMAG "\033[105m"
#define TC_blCYA "\033[106m"
#define TC_blWHI "\033[107m"

#define tc_f8(X) printf("\033[38;5;%dm", X)
#define tc_b8(X) printf("\033[48;5;%dm", X)
#define tc_fRGB(R,G,B) printf("\033[38;2;%d;%d;%dm", R, G, B)
#define tc_bRGB(R,G,B) printf("\033[48;2;%d;%d;%dm", R, G, B)

#define tc_clrScreen() puts("\033[2J")
#define tc_clrToEnd() puts("\033[0J")
#define tc_clrToBeg() puts("\033[1J")
#define tc_clrLine() puts("\033[2K")
#define tc_clrToEndLine() puts("\033[0K")
#define tc_clrToBegLine() puts("\033[1K")

#define tc_mvOrigine() tc_mvPos(0, 0)
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

#define tc_altScreen() puts("\033[?1049h\033[H")
#define tc_exit_altScreen() puts("\033[?1049l")
#define tc_saveScreen() puts("\033[?47h")
#define tc_loadScreen() puts("\033[?47l")

// KEY

#include <stdint.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
//#include <time.h>

#ifndef NULL
#define NULL '\0'
#endif

#define TC_ESCAPE 0x1b
#define TC_F1 0x1b4f50
#define TC_F1_TTY 0x1b5b5b41
#define TC_F2 0x1b4f51
#define TC_F2_TTY 0x1b5b5b42
#define TC_F3 0x1b4f52
#define TC_F3_TTY 0x1b5b5b43
#define TC_F4 0x1b4f53
#define TC_F4_TTY 0x1b5b5b44
#define TC_F5 0x1b5b31357e
#define TC_F5_TTY 0x1b5b5b45
#define TC_F6 0x1b5b31377e
#define TC_F7 0x1b5b31387e
#define TC_F8 0x1b5b31397e
#define TC_F9 0x1b5b32307e
#define TC_F10 0x1b5b32317e
#define TC_F11 0x1b5b32337e
#define TC_F12 0x1b5b32347e

#define TC_ARROW_UP 0x1b5b41
#define TC_ARROW_DOWN 0x1b5b42
#define TC_ARROW_LEFT 0x1b5b44
#define TC_ARROW_RIGHT 0x1b5b43

#define TC_TAB 0x9
#define TC_RETURN 0xa
#define TC_ENTER 0xa

#define TC_INSERT 0x1b5b327e
#define TC_HOME 0x1b5b48
#define TC_PAGE_UP 0x1b5b357e
#define TC_DELETE 0x1b5b337e
#define TC_END 0x1b5b46
#define TC_PAGE_DOWN 0x1b5b367e

#define TC_EURO 0xffffffffffe181ac
#define TC_GBP 0xffffffffffffc1a3

#define RAW_INPUT_SIZE 120

void tc_canon_on(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ICANON;
	tcsetattr(1, TCSANOW, &term);
}

void tc_canon_off(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ICANON;
	tcsetattr(1, TCSANOW, &term);
}

typedef struct _raw_input raw_input;
typedef struct _tc_inp ti;

struct _raw_input{
	struct timespec tp;
	char c;
};

struct _tc_inp{
	raw_input ri[RAW_INPUT_SIZE];
	void (*key_cb) (uint64_t key, void *data);
	void *data;
};

static void t_process_thread(ti *t){
	//if we get two bytes within 100,000 nanosecs, it is part of the same keystroke
	//every keystroke, up to 6 scan codes
	int ri_index = 0;
	int n = 1;
	while(n){
		//is there non-blocking version of fread or read?
		n = fread( &((t->ri[ri_index]).c) , 1, 1, stdin);
		clock_gettime(CLOCK_MONOTONIC, &((t->ri[ri_index]).tp) );
		ri_index += 1;
		if(ri_index >= RAW_INPUT_SIZE){
			ri_index = 0;
		}
	}
}

static void t_process_keycode(ti *t){
	int i = 0;
	uint64_t key = 0;
	uint64_t time;
	uint64_t next_time;
	void (*key_cb) (uint64_t c, void *data);
	while(1){
		while( !((t->ri[i]).tp.tv_nsec) ) {
			usleep(10000);
			//nanosleep(10000);
		}
		usleep(100);
		//nanosleep(10000);
		key = (t->ri[i]).c;
		time = ((t->ri[i]).tp.tv_sec) * 1000000000;
		time += ((t->ri[i]).tp.tv_nsec);
		(t->ri[i]).tp.tv_nsec = 0;
		i += 1;
		if(i >= RAW_INPUT_SIZE){
			i = 0;
		}
		if( (t->ri[i]).tp.tv_nsec ){
			next_time = ((t->ri[i]).tp.tv_sec) * 1000000000;
			next_time += ((t->ri[i]).tp.tv_nsec);
			while(next_time - time < 100000){	//100,000 nanoseconds
				key <<= 8;
				key += (t->ri[i]).c;
				time = next_time;
				(t->ri[i]).tp.tv_nsec = 0;
				i += 1;
				if(i >= RAW_INPUT_SIZE){
					i = 0;
				}
				next_time = ((t->ri[i]).tp.tv_sec) * 1000000000;
				next_time += ((t->ri[i]).tp.tv_nsec);
			}
		}
		key_cb = t->key_cb;
		if(key_cb){
			(*key_cb)(key, t->data);
		}
		key = 0;
	}
}

ti* tc_init_input( void (*func)(), void *data){
	ti *t = (ti *) malloc(sizeof(ti));
	memset(t, 0, sizeof(ti));
	tc_canon_off();
	t->key_cb = func;
	t->data = data;
	pthread_t thid, thid2;
	pthread_create(&thid, NULL, (void *) &t_process_thread, (void *) t);
	pthread_create(&thid2, NULL, (void *) &t_process_keycode, (void *) t);
	return t;
}

#endif
