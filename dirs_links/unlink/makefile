VPATH=../../include:../../lib

LLIB=../../lib

objects=t_unlink.o $(LLIB)/error_functions.o $(LLIB)/get_num.o

t_unlink: $(objects)
	cc -o t_unlink $(objects)

$(objects):tlpi_hdr.h

$(LLIB)/error_functions.o: error_functions.h
$(LLIB)/get_num.o: get_num.h
.PHONY:
	clean

clean:
	-rm -rf t_unlink *.o
