VPATH=../../include:../../lib
LLIB=../../lib

objects=procfs_pidmax.o $(LLIB)/error_functions.o

procfs_pidmax: $(objects)
	cc -o procfs_pidmax $(objects)

$(objects): tlpi_hdr.h
$(LLIB)/error_functions.o: error_functions.h

.PHONY:
	clean

clean:
	-rm -rf procfs_pidmax *.o

