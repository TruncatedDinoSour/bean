bean: cmdmgr.o cmds.o
	cc src/main.c $^ -o "$@" $(CFLAGS)

cmdmgr.o: src/cmdmgr.c
	cc -c $^ -o $@ -DCMDMGR_IMPL $(CFLAGS)

cmds.o: src/cmds.c
	cc -c $^ -o $@ -DCMDS_IMPL $(CFLAGS)

clean:
	rm -f bean *.o
