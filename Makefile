CC=g++
CFLAGS=-Wall -Wextra -Wno-unused-parameter
EXEC=tp2virtual

$(EXEC): src/main.c mmu.o entrada_tabela.o memoria_fisica.o algoritmo_substituicao.o fifo.o lru.o novo.o segunda_chance.o
	$(CC) $(CFLAGS) src/main.c mmu.o entrada_tabela.o memoria_fisica.o algoritmo_substituicao.o fifo.o lru.o novo.o segunda_chance.o -o $(EXEC)

mmu.o: src/headers/mmu.c
	$(CC) $(CFLAGS) -c src/headers/mmu.c -o mmu.o

entrada_tabela.o: src/headers/entrada_tabela.c
	$(CC) $(CFLAGS) -c src/headers/entrada_tabela.c -o entrada_tabela.o

memoria_fisica.o: src/headers/memoria_fisica.c
	$(CC) $(CFLAGS) -c src/headers/memoria_fisica.c -o memoria_fisica.o

algoritmo_substituicao.o: src/headers/algoritmo_substituicao.c
	$(CC) $(CFLAGS) -c src/headers/algoritmo_substituicao.c -o algoritmo_substituicao.o

fifo.o: src/headers/impl_algoritmos_substituicao/fifo.c
	$(CC) $(CFLAGS) -c src/headers/impl_algoritmos_substituicao/fifo.c -o fifo.o

lru.o: src/headers/impl_algoritmos_substituicao/lru.c
	$(CC) $(CFLAGS) -c src/headers/impl_algoritmos_substituicao/lru.c -o lru.o

novo.o: src/headers/impl_algoritmos_substituicao/novo.c
	$(CC) $(CFLAGS) -c src/headers/impl_algoritmos_substituicao/novo.c -o novo.o

segunda_chance.o: src/headers/impl_algoritmos_substituicao/segunda_chance.c
	$(CC) $(CFLAGS) -c src/headers/impl_algoritmos_substituicao/segunda_chance.c -o segunda_chance.o

clean:
	rm -rf *.o