CFLAGS := -g

all: treesort selectionsort insertionsort 	

treesort: treesort.o base.o
selectionsort: selectionsort.o base.o
insertionsort: insertionsort.o base.o

clean:
	rm -rf *.o treesort selectionsort insertionsort 	
	rm -rf dados/*.{svg,yml}

.PHONY: all clean
