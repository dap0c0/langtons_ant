CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic -D_FORTIFY_SOURCE=3 -g
LIBS = -lSDL3
.PHONY: clean

build:
	gcc -Wall -std=c99 ./src/*.c $(LIBS) -Wl,-rpath,/usr/local/lib -o langtons_ant

run:
	# install_name_tool -add_rpath /usr/local/lib ./game
	./langtons_ant

clean:
	rm langtons_ant
