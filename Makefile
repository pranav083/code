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
