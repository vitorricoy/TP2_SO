CC=gcc
CFLAGS=-Wall -Wextra -Wno-unused-parameter
EXEC=tp2virtual

$(EXEC): src/main.c tabela_paginas.o mmu.o fifo.o lru.o novo.o segunda_chance.o algoritmo_substituicao.o
	$(CC) $(CFLAGS) src/main.c tabela_paginas.o mmu.o fifo.o lru.o novo.o segunda_chance.o algoritmo_substituicao.o -o $(EXEC)

mmu.o: src/headers/mmu.c
	$(CC) $(CFLAGS) -c src/headers/mmu.c -o mmu.o

tabela_paginas.o: src/headers/tabela_paginas.c
	$(CC) $(CFLAGS) -c src/headers/tabela_paginas.c -o tabela_paginas.o

algoritmo_substituicao.o: src/headers/algoritmo_substituicao.c fifo.o
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
