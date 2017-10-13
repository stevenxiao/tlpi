VPATH = ../lib:../include
objects=copy.o get_num.o error_functions.o

copy.out : $(objects)
	cc -o copy.out $(objects)

#$(objects) : tlpi_hdr.h
#	get_num.o : get_num.h
#	error_functions.o : error_functions.h

clean:
	rm -r copy.out $(objects)

