VPATH=../../include:../../lib

LLIB=../../lib

objects=$(LLIB)/error_functions.o t_statvfs.o

t_statvfs: $(objects)
	cc -o t_statvfs $(objects)

$(objects): tlpi_hdr.h

$(LLIB)/error_functions.o: error_functions.h


.PHONY:
	clean

clean:
	-rm -rf t_statvfs *.o
