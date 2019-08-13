VPATH=../../include:../../lib:../

LLIB=../../lib

objects=../file_perms.o t_stat.o $(LLIB)/error_functions.o

t_stat: $(objects)
	cc -o t_stat $(objects)

#$(objects): tlpi_hdr.h
t_stat.o $(LLIB)/error_functions.o: tlpi_hdr.h error_functions.h
../file_perms.o t_stat.o: file_perms.h


.PHNOY:
	clean

clean:
	-rm -rf t_stat *.o

