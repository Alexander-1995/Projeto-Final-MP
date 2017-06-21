IDIR =../include
CC=gcc
CFLAGS=-g -I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = grafo.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = grafo.o testa_grafo.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testa_grafo: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 