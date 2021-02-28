# paths
MODULES = ../modules
INCLUDE = ../include
FILES = ../Input

# Compile options. Το -I<dir> λέει στον compiler να αναζητήσει εκεί include files
CFLAGS = -Wall -no-pie -fPIE -g -I$(INCLUDE)

# Αρχεία .o
INCL = $(INCLUDE)/sorting.h $(INCLUDE)/selection.h $(INCLUDE)/colors.h
OBJS = mapcol.o $(MODULES)/sorting.o $(MODULES)/selection.o
OBJS1 = genmap.o

# the executable program
EXEC = mapcol
EXEC1 = genmap

# parameters
ARGS =

$(EXEC): $(OBJS) $(INCL)
	gcc $(OBJS) -o $(EXEC)

$(EXEC1): $(OBJS1)
	gcc $(OBJS1) -o $(EXEC1)

clean:
	rm -f $(OBJS) $(EXEC)


run: $(EXEC)
	./$(EXEC) $(ARGS) < $(FILES)/Balkans.txt

gdb: $(OBJS)
	g++ $(OBJS) -g3 -o $(EXEC)
	gdb $(EXEC)