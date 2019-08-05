VPATH=../../include:../../lib
LIBRARY_PATH=../../lib
	
object = calendar_time.o ${LIBRARY_PATH}/error_functions.o

calendar_time: ${object}
	cc -o calendar_time ${object}

${object} : error_functions.h

calendar_time.o :tlpi_hdr.h
clean:
	rm -r *.o calendar_time
