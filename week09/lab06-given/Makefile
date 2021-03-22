PROG = lab06
OBJS = armemu.o max3_c.o max3_s.o find_max_c.o find_max_s.o\
       fib_rec_c.o fib_rec_s.o
HEADERS = armemu.h

CFLAGS = -g -Wall

%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

%.o : %.s
	as -g -o $@ $<

all : $(PROG)

$(PROG) : $(PROG).c $(HEADERS) $(OBJS)
	gcc $(CFLAGS) -o $@ $< $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)
