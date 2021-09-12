CC = gcc
CFLAGS = -g -Wall -Wshadow -L. -llog
TAR = driver
DEPS = driver.c liblog.a log.c
LIBDEPS = log.h log.c
OBJ = driver.o
LIBOBJS = addmsg.o clearlog.o getlog.o savelog.o

# main program executable
$(TAR): $(OBJ)
	gcc $(CFLAGS) -o $@ $^

# generate obj files from c files
$(OBJ): %.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

# create library archive
liblog.a: $(LIBOBJS)
	ar rcs $@ $^

# generate library function objs
$(LIBOBJS): %.o: src/%.c $(LIBDEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

# remove all previously generated files
.PHONY: clean
clean:
	rm -f $(TAR) *.o *.a

