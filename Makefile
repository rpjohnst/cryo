.PHONY: all clean

all: main

clean:
	$(RM) main *.o *.d

CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic -pedantic-errors -MMD -MF $*.d

main: main.o sprite.o

-include main.d sprite.d
