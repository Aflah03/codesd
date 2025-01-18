obj-m += hello.o

all: 
	gcc pr12.c -o pr12

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
