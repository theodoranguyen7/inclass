PROG = add4
OBJS = add4_c.o add4_s.o add4.o
CFLAGS = -g

%.o : %.s
	as $(CFLAGS) -o $@ $<

$(PROG) : $(OBJS)
	gcc $(CFLAGS) -o $(PROG) $^

clean:
	rm -rf $(PROG) $(OBJS)
