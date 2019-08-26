VPATH=../include:../lib

LLIB=../lib

objects=demo_inotify.o $(LLIB)/error_functions.o

demo_inotify: $(objects)
	cc -o demo_inotify $(objects)

$(objects):tlpi_hdr.h

$(LLIB)/error_functions.o: error_functions.h

.PHONY:
	clean

clean:
	-rm -rf demo_inotify *.o
