#
# Specifiy the target
all:	program2

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
program2:	program2.o minheap.o
	g++ -std=c++11 program2.o minheap.o -o program2

# Specify how the object files should be created from source files
program2.o:	program2.cpp
	g++ -std=c++11 -g -c program2.cpp -o program2.o

# Specify how the object files should be created from source files
minheap.o:	minheap.cpp
	g++ -std=c++11 -g -c minheap.cpp -o minheap.o

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o *~ program2
