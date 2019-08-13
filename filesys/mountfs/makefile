VPATH=../../include:../../lib
LLIB=../../lib


objects=t_mount.o $(LLIB)/error_functions.o

t_mount: $(objects)
	cc -o t_mount $(objects)

$(objects): tlpi_hdr.h

$(LLIB)/error_functions.o: error_functions.h

.PHNOY:
	clean

clean:
	-rm -rf t_mount *.o
