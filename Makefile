obj = build/main.o build/demo1.o build/demo2.o build/demo3.o build/demo4.o

build/main : $(obj)
	gcc -o build/main $(obj)

build/main.o : demo/main.c src/termCtrl.h include/demo1.h include/demo2.h include/demo3.h include/demo4.h
	gcc -c demo/main.c -I include -I src -o build/main.o

build/demo1.o : demo/demo1.c src/termCtrl.h
	gcc -c demo/demo1.c -I include -I src -o build/demo1.o

build/demo2.o : demo/demo2.c src/termCtrl.h
	gcc -c demo/demo2.c -I include -I src -o build/demo2.o

build/demo3.o : demo/demo3.c src/termCtrl.h
	gcc -c demo/demo3.c -I include -I src -o build/demo3.o

build/demo4.o : demo/demo4.c src/termCtrl.h
	gcc -c demo/demo4.c -I include -I src -o build/demo4.o

clean :
	rm build/*

run : build/main
	./build/main

dev : build/main
	cppcheck --enable=all --suppress=missingIncludeSystem -I include/ .
	flawfinder .
