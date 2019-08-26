VPATH=../../include:../../lib

LLIB=../../lib

objects=view_symlink.o $(LLIB)/error_functions.o

view_symlink:$(objects)
	cc -o view_symlink $(objects)

$(objects): tlpi_hdr.h

$(LLIB)/error_functions.o: error_functions.h


.PHONY:
	clean


clean:
	-rm -rf view_symlink *.o
