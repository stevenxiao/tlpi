VPATH=../../include:../../lib
LPATH=../../lib
objects=${LPATH}/error_functions.o strtime.o


strtime: $(objects)
	cc -o strtime $(objects)

$(objects): tlpi_hdr.h

.PHONY : clean

clean:
	-rm strtime *.o
