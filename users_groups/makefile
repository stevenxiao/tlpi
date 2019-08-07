VPATH=../include:../lib
LLIB=../lib/

objects=check_passwd.o ${LLIB}/error_functions.o

check_passwd: ${objects}
	cc $(objects) -o check_passwd -lcrypt

$(objects): tlpi_hdr.h
error_functions.o: error_functions.h

.PHONY:clean

clean:
	-rm -rf check_passwd *.o
