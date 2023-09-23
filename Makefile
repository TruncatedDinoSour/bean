bean: cmdmgr.o cmds.o chroot.o
	$(CC) src/main.c $^ -o "$@" $(CFLAGS)

cmdmgr.o: src/cmdmgr.c
	$(CC) -c $^ -o $@ -DCMDMGR_IMPL $(CFLAGS)

cmds.o: src/cmds.c
	$(CC) -c $^ -o $@ -DCMDS_IMPL $(CFLAGS)

chroot.o: src/chroot.c
	$(CC) -c $^ -o $@ -DCHROOT_IMPL $(CFLAGS)

clean:
	rm -f bean *.o
