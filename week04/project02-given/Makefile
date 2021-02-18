PROG = project02
OBJS = scan.o parse.o project02.o eval.o convert.o
CFLAGS = -g

%.o : %.c project02.h
	gcc $(CFLAGS) -c -o $@ $<

$(PROG) : $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)

