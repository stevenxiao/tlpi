VPATH=../../include:../../lib

LLIB=../../lib

objects=list_files.o $(LLIB)/error_functions.o

list_files:$(objects)
	cc -o list_files $(objects)

$(objects):tlpi_hdr.h

$(LLIB)/error_functions.o: error_functions.h


.PHONY:
	clean


clean:
	-rm -rf list_files *.o
