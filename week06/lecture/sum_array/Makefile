PROG = sum_array
OBJS = sum_array_c.o sum_array_s.o sum_array.o
CFLAGS = -g

%.o : %.s
	as $(CFLAGS) -o $@ $<

$(PROG) : $(OBJS)
	gcc $(CFLAGS) -o $(PROG) $^

clean:
	rm -rf $(PROG) $(OBJS)
