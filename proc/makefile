VPATH = ../lib:../include
objects = get_num.o error_functions.o display_env.o

display_env.out : $(objects)
	cc -o display_env.out $(objects)

$(objects): tlpi_hdr.h

get_num.o: get_num.h


error_functions.o: error_functions.h


clean:
	rm -r *.o *.out
