VPATH=../../include:../../lib:../

LLIB=../../lib

objects=../file_perms.o $(LLIB)/error_functions.o t_umask.o

t_umask: $(objects)
	cc -o t_umask $(objects)

../file_perms.o t_umask.o: file_perms.h

t_umask.o $(LLIB)/error_functions.o: tlpi_hdr.h

$(LLIB)/error_functions.o: error_functions.h


.PHONY:
	clean

clean:
	-rm -rf t_umask *.o myfile mydir

