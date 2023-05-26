CFLAGS=-Wall -g -lm

all:
	gcc -Wall -Werror -Wextra -pedantic *.c -o monty
run:
	./monty
clean:
	touch monty && rm ./monty && clear
