#include "configuracoes.h"

#include <stdio.h>

//opengl
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//inicializa as configuracoes iniciais do ambiente
void inicializarAmbiente() {
    printf("[LOG] Inicializando ambiente...\n");
}

void criarJanela(int largura, int altura, const char* titulo, int x, int y) {
    printf("[LOG] Criando janela...\n");
    //modo de cores
    glutInitDisplayMode(GLUT_RGB);
    //tamanho inicial da tela
    glutInitWindowSize(largura, altura);
    //posicao inicial da tela
    glutInitWindowPosition(x, y);
    //cria a janela e seta o titulo
    glutCreateWindow(titulo);
    //cor de fundo padrao da janela
    glClearColor(0.5, 0.5, 0.5, 1.0); //rgba
}