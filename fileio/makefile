VPATH = ../lib:../include
objects=t_readv.o get_num.o error_functions.o

copy.out : $(objects)
	cc -o t_readv.out $(objects)

#$(objects) : tlpi_hdr.h
#	get_num.o : get_num.h
#	error_functions.o : error_functions.h

clean:
	rm -r *.out $(objects)

