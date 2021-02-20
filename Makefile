CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -Wno-unused-parameter
EXEC=tp2virtual

$(EXEC): src/main.cpp tabela.o memoria.o algoritmo_substituicao.o fifo.o lru.o novo.o segunda_chance.o
	$(CC) $(CFLAGS) src/main.cpp tabela.o memoria.o algoritmo_substituicao.o fifo.o lru.o novo.o segunda_chance.o -o $(EXEC)

tabela.o: src/headers/tabela.cpp
	$(CC) $(CFLAGS) -c src/headers/tabela.cpp -o tabela.o

memoria.o: src/headers/memoria.cpp
	$(CC) $(CFLAGS) -c src/headers/memoria.cpp -o memoria.o

algoritmo_substituicao.o: src/headers/algoritmo_substituicao.cpp
	$(CC) $(CFLAGS) -c src/headers/algoritmo_substituicao.cpp -o algoritmo_substituicao.o

fifo.o: src/headers/fifo.cpp
	$(CC) $(CFLAGS) -c src/headers/fifo.cpp -o fifo.o

lru.o: src/headers/lru.cpp
	$(CC) $(CFLAGS) -c src/headers/lru.cpp -o lru.o

novo.o: src/headers/novo.cpp
	$(CC) $(CFLAGS) -c src/headers/novo.cpp -o novo.o

segunda_chance.o: src/headers/segunda_chance.cpp
	$(CC) $(CFLAGS) -c src/headers/segunda_chance.cpp -o segunda_chance.o

clean:
	rm -rf *.o