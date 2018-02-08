# Environment
CC = gcc
CFLAGS = -m64 -g ${EXTRA_FLAGS}
TARGETS = dtime
OBJS = dtime.o
INCLS =
LIBS =

all: ${TARGETS}

dtime: ${OBJS}
	${CC} ${CFLAGS} -o $@ $? ${LIBS}

clean:
	rm -f *.o
	rm -f $(TARGETS)

clobber:
	rm -f *.o

strip:
	strip $(TARGETS)

.c.o:
	$(CC) $(CFLAGS) $(INCLS) -c $<
