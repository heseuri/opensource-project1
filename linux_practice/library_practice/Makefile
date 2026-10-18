CC = gcc
CFLAGS = -fPIC
LIBDIR = lib

OBJS = $(LIBDIR)/add.o $(LIBDIR)/sub.o $(LIBDIR)/mul.o $(LIBDIR)/div.o

all: static_main shared_main dynamic_main

$(LIBDIR)/%.o: $(LIBDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBDIR)/libarithmetic.a: $(OBJS)
	ar rcs $@ $(OBJS)

$(LIBDIR)/libarithmetic.so: $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

static_main: main.c arithmetic.h $(LIBDIR)/libarithmetic.a
	$(CC) main.c $(LIBDIR)/libarithmetic.a -o static_main

shared_main: main.c arithmetic.h $(LIBDIR)/libarithmetic.so
	$(CC) main.c -L./lib -larithmetic -Wl,-rpath,'$$ORIGIN/lib' -o shared_main

dynamic_main: dynamic_main.c $(LIBDIR)/libarithmetic.so
	$(CC) dynamic_main.c -o dynamic_main -ldl

run: all
	./static_main
	./shared_main
	./dynamic_main

clean:
	rm -f $(LIBDIR)/*.o $(LIBDIR)/*.a $(LIBDIR)/*.so
	rm -f static_main shared_main dynamic_main

.PHONY: all run clean
.PHONY: profile valgrind

profile:
	gcc -pg -g -O0 main.c lib/add.c lib/sub.c lib/mul.c lib/div.c -o profile_main
	./profile_main
	gprof ./profile_main gmon.out > gprof_result.txt

valgrind:
	gcc -g -O0 main.c lib/add.c lib/sub.c lib/mul.c lib/div.c -o valgrind_main
	valgrind --leak-check=full --show-leak-kinds=all ./valgrind_main