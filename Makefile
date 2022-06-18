all:
	gcc -c ./bibliotecas/configuracoes.c
	gcc -c ./bibliotecas/renderizacao.c
	gcc main.c -o relogio configuracoes.o renderizacao.o -lGL -lGLU -lglut -lm
	rm *.o
	./relogio