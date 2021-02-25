PROGS = replace map_test

all : $(PROGS)

map_test : map_test.c map.c map.h
	gcc -g -o $@ map_test.c map.c

replace : replace.c map.c map.h
	gcc -g -o $@ replace.c map.c

clean:
	rm -rf $(PROGS)
