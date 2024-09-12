########################################################################
# ECE5504 ....
########################################################################

CC := riscv64-unknown-elf-gcc
OBJDUMP := riscv64-unknown-elf-objdump

CFLAGS := -O2 -std=gnu11 -Wall -specs=htif_nano.specs


.PHONY: multiplication_16 multiplication_32
multiplication_16: multiplication_16.riscv
multiplication_32: multiplication_32.riscv

.PRECIOUS: %.riscv
%_16.riscv: %.c trap.c
	$(CC) $(CFLAGS) -DSIZE=16 -o $@ $< trap.c

%_32.riscv: %.c trap.c
	$(CC) $(CFLAGS) -DSIZE=32 -o $@ $< trap.c

#.dump: %.riscv
#	$(OBJDUMP) -d -M no-aliases $< > $@

.PHONY: clean
clean:
	rm -f -- *.riscv *.o *.dump

.SUFFIXES: # Disable built-in suffix rules
