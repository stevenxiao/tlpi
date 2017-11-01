VPATH = ../lib:../include
objects=tmpfile.o get_num.o error_functions.o

tmpfile.out : $(objects)
	cc -o tmpfile.out $(objects)

#$(objects) : tlpi_hdr.h
#	get_num.o : get_num.h
#	error_functions.o : error_functions.h

clean:
	rm -r *.out *.o

