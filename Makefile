CC = gcc
CFLAGS = -g -Wall -Wshadow -L.
TAR = driver
DEPS = driver.c liblog.a
LIBDEPS = log.h #log.c
OBJ = driver.o
LIBOBJS = addmsg.o clearlog.o getlog.o savelog.o

# main program executable
$(TAR): $(OBJ)
	gcc $(CFLAGS) -o $@ $^

# generate obj files from c files
$(OBJ): %.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

# generate library function objs
$(LIBOBJS): %.o: %.c $(LIBDEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

# create library archive
liblog.a: $(LIBOBJS)
	ar rcs $@ $^

# remove all previously generated files
.PHONY: clean
clean:
	rm -f $(TAR) *.o *.a

