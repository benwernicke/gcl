DEBUG_FLAGS := -g -Wall -pedantic -fsanitize=leak -fsanitize=address -fsanitize=undefined
RELEASE_FLAGS := -O3 -march=native -mtune=native -flto -DNDEBUG

TARGETS := test_a.out b0_a.out

.PHONY: all clean

all: debug

debug: CFLAGS = ${DEBUG_FLAGS}
debug: ${TARGETS}

bench: CFLAGS = ${RELEASE_FLAGS}
bench: ${TARGETS}
	hyperfine -N \
		'./b0_a.out lorem'

test_a.out: maps/a.h test.c
	${CC} ${CFLAGS} -o $@ test.c -D'MAP="maps/a.h"'

b0_a.out: maps/a.h b0.c
	${CC} ${CFLAGS} -o $@ b0.c -D'MAP="maps/a.h"'

clean:
	rm -f *.o *.out
