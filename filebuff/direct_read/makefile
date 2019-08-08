VPATH=../../include:../../lib
LLIB=../../lib

objects=direct_read.o $(LLIB)/error_functions.o $(LLIB)/get_num.o

direct_read: $(objects)
	cc -o direct_read $(objects)


$(objects):tlpi_hdr.h
$(LLIB)/error_functions.o: error_functions.h
$(LLIB)/get_num.o: get_num.o

.PHONY:
	clean

clean:
	-rm -rf direct_read *.o
