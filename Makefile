all: lib


lib: lib.c
	gcc -shared -fPIC lib.c -o lib.so -ldl
	gcc -shared -fPIC lib.c -o lib.dylib -ldl
