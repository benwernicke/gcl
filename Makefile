DEBUG_FLAGS := -g -Wall -pedantic -fsanitize=leak -fsanitize=address -fsanitize=undefined

TARGETS := test_a.out

.PHONY: all clean

all: debug

debug: CFLAGS = ${DEBUG_FLAGS}
debug: ${TARGETS}

test_a.out: maps/a.h test.c
	${CC} ${CFLAGS} -o $@ test.c -D'MAP="maps/a.h"'

clean:
	rm -f *.o *.out
