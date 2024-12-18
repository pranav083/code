so I have a new “chipyard-clean” cloned and setup in a new directory.
Then, I have a “code” directory that is separate. The code directory contains:
- rsort.c
- ⁠Makefile
- ⁠hpm.h (to print counters, lab3 has this file)
- ⁠trap.c (lab3 has this file)

Then, when I run “make” I get the rsort.riscv file. I run this file from my chipyard-clean/sim/verilator directory

make CONFIG=RocketConfig -j4 run-binary BINARY=~/project/code/rsort.riscv

```bash
########################################################################
# CODE ....
########################################################################

CC := riscv64-unknown-elf-gcc
OBJDUMP := riscv64-unknown-elf-objdump

CFLAGS := -O2 -std=gnu11 -Wall -specs=htif_nano.specs


.PHONY: fft sha-256
fft: fft.riscv
sha-256: sha-256.riscv

.PRECIOUS: %.riscv
%.riscv: %.c trap.c
	$(CC) $(CFLAGS) -DSIZE=32 -o $@ $< trap.c 

%.riscv: %.c trap.c
	$(CC) $(CFLAGS) -DSIZE=32 -o $@ $< trap.c -lm

#.dump: %.riscv
#	$(OBJDUMP) -d -M no-aliases $< > $@

.PHONY: clean
clean:
	rm -f -- *.riscv *.o *.dump

.SUFFIXES: # Disable built-in suffix rules
```

This is my edited Makefile - run “make rsort” or “make vvadd” - change for yourself