# TERMINAL CONTROL

termCtrl is a small library that lets you take control of the terminal for your applications.
it allows you to display text in color, bold, italic and more.
it lets you move the cursor, so you can modify text already displayed.
it lets you take keyboard input without hitting enter.
if you want demo, checkout the dev branch and the code is in demo/, make run to execute.

## how to use it

always setupConsole(); and restoreConsole(); at the beginning and end of the program,
tc_getCoord(&cols, &rows); to get terminal size.
tc_echo_off(); / tc_echo_on(); enables / disables user input display

## color

here's how to add color :
printf("%sHello %s%sWorld%s\n", TC_RED, TC_CYA, TC_BOLD, TC_RES);

will display Hello in red and World in cyan and bold, then reset the colors.
each color has its light version (TC_lRED), its background version (TC_bRED) and the combination of the two light backgrounds (TC_lbRED)

similarly, for each text format there's a variable that resets the specified format (TC_BOLD -> TC_nBOLD) 

to have more colors than defined, you can use their 8-bit version with the function tc_f8(color-code); and tc_b8(color-code); for the background, to see all available color codes: https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit

if you want more freedom on your colors, you can make them in RGB: tc_fRGB(R, G, B); and tc_bRGB(R, G, B); for the background.

## cursor

Here is a list of existing functions that do exactly what they say:
- tc_clrScreen()
- tc_clrToEnd()
- tc_clrToBeg()
- tc_clrLine()
- tc_clrToEndLine()
- tc_clrToBegLine()
- tc_mvOrigine()
- tc_mvPos(X, Y)
- tc_mvUp(X)
- tc_mvDown(X)
- tc_mvRight(X)
- tc_mvLeft(X)
- tc_mvBeginDown(X)
- tc_mvBeginUp(X)
- tc_mvCol(X)
- tc_savePos()
- tc_loadPos()
- tc_cursorInvisible()
- tc_cursorVisible()
- tc_altScreen()
- tc_exit_altScreen() 
- tc_saveScreen()
- tc_loadScreen()

## key

tc_canon_off(); tc_canon_on(); disables / enables the need to press enter for the application to receive the information

tc_init_input( &process_key, NULL);
to initialize the reception of keys enter this line with process_key a function with this header :
process_key(uint64_t c, void *data);
with c the character collected.
