PROG = lab05
OBJS = max3_c.o max3_s.o find_max_c.o find_max_s.o\
       fib_rec_c.o fib_rec_s.o lab05.o
HEADERS = 

CFLAGS = -g

# Pattern rule for .c files
%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

# Pattern rule for .s files
%.o : %.s
	as $(CFLAGS) -o $@ $<

all : $(PROG)

# Linker rule to combine OBJS into PROG
$(PROG) : $(HEADERS) $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)
