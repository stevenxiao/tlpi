VPATH=../../include:../../lib

LPATH=../../lib

objects = show_time.o ${LPATH}/error_functions.o


show_time:$(objects)
	cc -o show_time $(objects)

$(objects):tlpi_hdr.h


.PHONY:
	clean

clean:
	-rm show_time *.o
