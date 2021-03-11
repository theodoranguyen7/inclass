PROG = emu1
OBJS = add2_s.o emu1.o
CFLAGS = -g

%.o: %.s
	as $(CFLAGS) -o $@ $<

$(PROG): $(OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
