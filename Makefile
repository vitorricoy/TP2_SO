CC=g++
CFLAGS=-std=c++11 -Wall -Wextra -Wno-unused-parameter
EXEC=tp2virtual

$(EXEC): src/main.cpp tabela_paginas.o entrada_tabela.o memoria_fisica.o algoritmo_substituicao.o fifo.o lru.o novo.o segunda_chance.o
	$(CC) $(CFLAGS) src/main.cpp tabela_paginas.o entrada_tabela.o memoria_fisica.o algoritmo_substituicao.o fifo.o lru.o novo.o segunda_chance.o -o $(EXEC)

tabela_paginas.o: src/headers/tabela_paginas.cpp
	$(CC) $(CFLAGS) -c src/headers/tabela_paginas.cpp -o tabela_paginas.o

entrada_tabela.o: src/headers/entrada_tabela.cpp
	$(CC) $(CFLAGS) -c src/headers/entrada_tabela.cpp -o entrada_tabela.o

memoria_fisica.o: src/headers/memoria_fisica.cpp
	$(CC) $(CFLAGS) -c src/headers/memoria_fisica.cpp -o memoria_fisica.o

algoritmo_substituicao.o: src/headers/algoritmo_substituicao.cpp
	$(CC) $(CFLAGS) -c src/headers/algoritmo_substituicao.cpp -o algoritmo_substituicao.o

fifo.o: src/headers/impl_algoritmos_substituicao/fifo.cpp
	$(CC) $(CFLAGS) -c src/headers/impl_algoritmos_substituicao/fifo.cpp -o fifo.o

lru.o: src/headers/impl_algoritmos_substituicao/lru.cpp
	$(CC) $(CFLAGS) -c src/headers/impl_algoritmos_substituicao/lru.cpp -o lru.o

novo.o: src/headers/impl_algoritmos_substituicao/novo.cpp
	$(CC) $(CFLAGS) -c src/headers/impl_algoritmos_substituicao/novo.cpp -o novo.o

segunda_chance.o: src/headers/impl_algoritmos_substituicao/segunda_chance.cpp
	$(CC) $(CFLAGS) -c src/headers/impl_algoritmos_substituicao/segunda_chance.cpp -o segunda_chance.o

clean:
	rm -rf *.o