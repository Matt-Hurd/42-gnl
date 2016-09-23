ifdef ALLOCWRAP
	LDFLAGS += lib/alloc_wrap.c -ldl
endif 

all:
	gcc main.c $(LDFLAGS) -I ../ -L .. -lft && ./a.out
