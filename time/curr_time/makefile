objects = main.o curr_time.o

curr_time: $(objects)
		cc $(objects) -o curr_time

$(objects): curr_time.h

.PHONY:clean

clean:
	-rm curr_time  *.o
