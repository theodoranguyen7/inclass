PROG = lab03
OBJS = scan.o parse.o lab03.o

CFLAGS = -g

%.o : %.c lab03.h
	gcc $(CFLAGS) -c -o $@ $<

$(PROG) : $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)

