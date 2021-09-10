CC=gcc
CFLAGS=-I.
TAR=driver
DEPS = driver.c liblog.a
LIBDEPS = log.h log.c
OBJ = driver.o
LIBOBJS = addmsg.o clearlog.o getlog.o savelog.o 

# compile all
all: $(TAR)

# main program executable
$(TAR): $(OBJ)
	gcc -o $@ $^

# generate obj files from c files
$(OBJ): %.o: $%.c $(DEPS)
	$(CC) -c -o $@ $<

# generate library function objs
$(LIBOBJS): %.o: %.c $(LIBDEPS)
	$(CC) -c -o $@ $<

# create library archive
liblog.a: $(LIBOBJS)
	ar rc $@ $^

# remove all previously generated files
.PHONY: clean

clean:
	rm -f $(TAR) *.o *.a
