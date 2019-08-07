VPATH=../include:../lib
LLIB=../lib

objects=t_fpathconf.o $(LLIB)/error_functions.o

t_fpathconf: $(objects)
	cc -o t_fpathconf $(objects)

$(objects): tlpi_hdr.h
$(LLIB)/error_functions.o: error_functions.h


.PHONY:
	clean

clean:
	-rm -rf t_fpathconf *.o
