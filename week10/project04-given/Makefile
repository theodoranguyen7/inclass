PROG = project04
OBJS = armemu.o cache.o verbose.o max3_c.o max3_s.o find_max_c.o find_max_s.o\
       fib_rec_c.o fib_rec_s.o quadratic_c.o quadratic_s.o \
       matches_c.o matches_s.o mergesort_c.o mergesort_s.o
       
HEADERS = armemu.h

DEBUG = -g
CFLAGS = -Wall $(DEBUG)

# Pattern rules to avoid explicit rules

%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

%.o : %.s
	as $(DEBUG) -o $@ $<

all : $(PROG)

$(PROG) : $(PROG).c $(HEADERS) $(OBJS)
	gcc $(CFLAGS) -o $@ $< $(OBJS) -lm

clean :
	rm -rf $(PROG) $(OBJS)
