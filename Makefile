DEBUG_FLAGS := -g -Wall -pedantic -fsanitize=leak -fsanitize=address -fsanitize=undefined
RELEASE_FLAGS := -O3 -march=native -mtune=native -flto -DNDEBUG

A := test_a.out b0_a.out b1_a.out b2_a.out b3_a.out b4_a.out  b5_a.out
B := test_b.out b0_b.out b1_b.out b2_b.out b3_b.out b4_b.out  b5_b.out

TARGETS :=  ${A} ${B}
NUM_RUNS := 1000000

.PHONY: all clean release b0 b1 b2 b3 bench bench-to-file

all: debug

debug: CFLAGS = ${DEBUG_FLAGS}
debug: ${TARGETS}

release: CFLAGS = ${RELEASE_FLAGS}
release: ${TARGETS}

bench: b0 b1 b2 b3 b4 b5

bench-to-file: B0_OPTS := --export-asciidoc=b0.log
bench-to-file: B1_OPTS := --export-asciidoc=b1.log
bench-to-file: B2_OPTS := --export-asciidoc=b2.log
bench-to-file: B3_OPTS := --export-asciidoc=b3.log
bench-to-file: B4_OPTS := --export-asciidoc=b4.log
bench-to-file: B5_OPTS := --export-asciidoc=b5.log
bench-to-file: bench
	cat b0.log b1.log b2.log b3.log b4.log b5.log > bench.log

b0: release
	hyperfine ${B0_OPTS} -N \
		'./b0_a.out lorem' \
		'./b0_b.out lorem'

b1: release
	hyperfine ${B1_OPTS} -N \
		'./b1_a.out ${NUM_RUNS}' \
		'./b1_b.out ${NUM_RUNS}'

b2: release
	hyperfine ${B2_OPTS} -N \
		'./b2_a.out lorem' \
		'./b2_b.out lorem'

b3: release
	hyperfine ${B3_OPTS} -N \
		'./b3_a.out ${NUM_RUNS}' \
		'./b3_b.out ${NUM_RUNS}'

b4: release
	hyperfine ${B4_OPTS} -N \
		'./b4_a.out lorem' \
		'./b4_b.out lorem'

b5: release
	hyperfine ${B5_OPTS} -N \
		'./b5_a.out ${NUM_RUNS}' \
		'./b5_b.out ${NUM_RUNS}'

test_a.out: test.c maps/a.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/a.h"'

b0_a.out: b0.c maps/a.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/a.h"'

b1_a.out: b1.c maps/a.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/a.h"'

b2_a.out: b2.c maps/a.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/a.h"'

b3_a.out: b3.c maps/a.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/a.h"'

b4_a.out: b4.c maps/a.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/a.h"'

b5_a.out: b5.c maps/a.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/a.h"'

test_b.out: test.c maps/b.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/b.h"'

b0_b.out: b0.c maps/b.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/b.h"'

b1_b.out: b1.c maps/b.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/b.h"'

b2_b.out: b2.c maps/b.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/b.h"'

b3_b.out: b3.c maps/b.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/b.h"'

b4_b.out: b4.c maps/b.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/b.h"'

b5_b.out: b5.c maps/b.h
	${CC} ${CFLAGS} -o $@ $< -D'MAP="maps/b.h"'

clean:
	rm -f *.o *.out
