bean: commands.o
	cc src/main.c "$^" -o "$@" $(CFLAGS)

commands.o: src/commands.c
	cc -c src/commands.c -o commands.o -DCOMMANDS_IMPL $(CFLAGS)

clean:
	rm -f bean commands.o
