CC=gcc
CFLAGS=-I. -lm -ansi -std=c11 -Wall -pedantic  -Ofast
DEPS = types.h calculo.h arquivo.h data_base.h data_mining.h util.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: calculo.o arquivo.o data_base.o data_mining.o util.o main.o 
	$(CC) -o main calculo.o arquivo.o data_base.o data_mining.o util.o  main.o $(CFLAGS)

clean: 
	# Removendo os arquivos de saída
	rm -rf *.o main *.data
