//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//opengl
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//minhas bibliotecas
#include "bibliotecas/configuracoes.h"
#include "bibliotecas/renderizacao.h"

//PROGRAMA PRINCIPAL
int main(int argc, char** argv) {
    //inicializa a glut
    glutInit(&argc, argv);

    //configuracoes iniciais
    inicializarAmbiente();
    criarJanela(500, 500, "Relogio Analogico", 300, 200);

    //definir funcoes e suas tarefas
    glutDisplayFunc(renderizar);
    glutReshapeFunc(redimensionar);
    glutTimerFunc(33, atualizar, 1);

    //monitorar eventos
    glutMainLoop();

    return 0;
}