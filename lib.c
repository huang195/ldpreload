#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

typedef ssize_t (*orig_write_f_type)(int fd, const void* buf, size_t nbyte);

ssize_t write(int fd, const void *buf, size_t nbyte) {
	orig_write_f_type orig_write;
	orig_write = (orig_write_f_type)dlsym(RTLD_NEXT, "write");
	printf("my write was called\n");
	return orig_write(fd, buf, nbyte);
}
