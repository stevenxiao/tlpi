VPATH=../../include:../../lib

LLIB=../../lib

objects=nftw_dir_tree.o

nftw_dir_tree: $(objects)
	cc -o nftw_dir_tree $(objects)

$(objects): tlpi_hdr.h

.PHONY:
	clean

clean:
	-rm -rf nftw_dir_tree *.o
