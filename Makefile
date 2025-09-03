CFLAGS=-Wall -Werror

build:
	gcc tema1.c $(CFLAGS) -o tema1

clean:
	-rm -f tema1