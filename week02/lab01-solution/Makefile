PROG = replace
OBJS = map.o replace.o
HDRS = map.h

%.o: %.c $(HDRS)
	gcc -g -c -o $@ $^

$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -f $(PROG) $(OBJS)
