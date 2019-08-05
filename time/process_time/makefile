VPATH=../../include:../../lib
LLIB=../../lib

objects=process_time.o ${LLIB}/get_num.o ${LLIB}/error_functions.o

process_time: $(objects)
	cc -o process_time $(objects)


process_time.o ${LLIB}/get_num.o: get_num.h
process_time.o ${LLIB}/error_functions.o: error_functions.h

clean: rm -rf process_time *.o
