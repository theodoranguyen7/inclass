PROGS = lab03 
OBJS = scan.o parse.o lab03.o

CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

all : ${PROGS}

lab03 : lab03.h $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean :
	rm -rf $(PROGS) $(OBJS)

