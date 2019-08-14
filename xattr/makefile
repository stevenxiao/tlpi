VPATH=../include:../lib

LLIB=../lib


objects=$(LLIB)/error_functions.o t_attr.o

t_attr:$(objects)
	cc -o t_attr $(objects)

$(objects):tlpi_hdr.h

$(LLIB)/error_functions.o:error_functions.h

.PHONY:
	clean

clean:
	-rm -rf t_attr *.o
