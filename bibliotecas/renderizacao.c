#include "renderizacao.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//opengl
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//definicoes
#define LARGURA_UNIVERSO 50
#define ALTURA_UNIVERSO 50

//variaveis globais
float g_angulo_ponteiro_horas = 0.0;
float g_angulo_ponteiro_minutos = 0.0;
float g_angulo_ponteiro_segundos = 0.0;

char horario_digital[9];

//desenha eixos 2D
void desenharEixos2D() {
    printf("[LOG] Desenhando eixos 2D...\n");
    glBegin(GL_LINES);
        //eixo X
        glColor3f(1.0, 0.0, 0.0); //rgb
        glVertex2f(-LARGURA_UNIVERSO, 0);
        glVertex2f(LARGURA_UNIVERSO, 0);
        //eixo Y
        glColor3f(0.0, 1.0, 0.0); //rgb
        glVertex2f(0, -ALTURA_UNIVERSO);
        glVertex2f(0, ALTURA_UNIVERSO);
    glEnd();
}

//funcao que desenha um circulo preenchido
void desenharCirculoPreenchido(float raio, int definicao, float r, float g, float b) {
    printf("[LOG] Desenhando circulo preenchido...\n");
    int i;
    float angulo = 0;
    float radianos = 0.0;

    glBegin(GL_POLYGON);
        //cor do preenchimento
        glColor3f(r, g, b);
        //marcando os pontos
        for (i = 0; i < definicao; i++) {
            radianos = (angulo * M_PI)/180.0;
            glVertex2f(raio * cos(radianos), raio * sin(radianos));
            angulo += (360.00/definicao);
        }
    glEnd();
}

//funcao que desenha um circulo vazado
void desenharCirculoVazado(float raio, int definicao, float r, float g, float b, float espessura) {
    printf("[LOG] Desenhando circulo vazado...\n");
    int i;
    float angulo = 0;
    float radianos = 0.0;

    //espessura da linha
    glLineWidth(espessura);

    glBegin(GL_LINE_LOOP);
        //cor do preenchimento
        glColor3f(r, g, b);
        //marcando os pontos
        for (i = 0; i < definicao; i++) {
            radianos = (angulo * M_PI)/180.0;
            glVertex2f(raio * cos(radianos), raio * sin(radianos));
            angulo += (360.00/definicao);
        }
    glEnd();

    //espessura padrao
    glLineWidth(1.0);
}

//funcao que desenha os pontos
void desenharPontos(float raio, int qtd_pontos, float r, float g, float b, float espessura) {
    printf("[LOG] Desenhando pontos...\n");
    int i;
    float angulo = 0;
    float radianos = 0.0;

    //espessura da linha
    glPointSize(espessura);

    glBegin(GL_POINTS);
        //cor do preenchimento
        glColor3f(r, g, b);
        //marcando os pontos
        for (i = 0; i < qtd_pontos; i++) {
            radianos = (angulo * M_PI)/180.0;
            glVertex2f(raio * cos(radianos), raio * sin(radianos));
            angulo += (360.00/qtd_pontos);
        }
    glEnd();

    //espessura padrao
    glPointSize(1.0);
}

void desenharPonteiro(int raio, float angulo, float r, float g, float b, float espessura) {
    printf("[LOG] Desenhando ponteiro...\n");
    float radianos = (angulo * M_PI)/180.0;

    //define a espessura
    glLineWidth(espessura);

    glBegin(GL_LINES);
        glColor3f(r, g, b);
        glVertex2f(0.0, 0.0);
        glVertex2f(raio * cos(radianos), raio * sin(radianos));
    glEnd();

    //largura padrao
    glLineWidth(1.0);
}

void desenharTexto(const char* texto, float x, float y) {
    printf("[LOG] Desenhando texto...\n");

    int i, tamanho_texto = strlen(texto);

    //cor do texto
    glColor3f(0.0, 0.0, 0.0);

    //posicionar o texto
    glRasterPos2f(x, y);

    //desenha o texto
    for (i = 0; i < tamanho_texto; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, texto[i]);
}

void desenharAlgarismosRomanos() {
    //desenha as horas
    desenharTexto("XII", -2, 33);
    desenharTexto("I", 16, 28);
    desenharTexto("II", 27, 16);
    desenharTexto("III", 30, -0.7);
    desenharTexto("IV", 27, -18);
    desenharTexto("V", 17, -30);
    desenharTexto("VI", -1.5, -35);
    desenharTexto("VII", -18, -30);
    desenharTexto("VIII", -30, -18);
    desenharTexto("IX", -35, -0.7);
    desenharTexto("X", -30, 16);
    desenharTexto("XI", -19, 28);
}

//funcoes de desenho
void renderizar() {
    printf("[LOG] Renderizando...\n");

    //limpa buffer
    glClear(GL_COLOR_BUFFER_BIT);

    //lista de desenhos
    //desenharEixos2D();
    desenharCirculoPreenchido(40, 60, 1.0, 1.0, 1.0); //fundo do relogio
    desenharCirculoVazado(40, 60, 0.0, 0.0, 0.0, 10.0); //borda do relogio
    desenharCirculoPreenchido(2, 60, 0.0, 0.0, 0.0); //centro do ponteiros
    desenharPontos(37, 60, 1.0, 0.0, 0.0, 5); //pontos dos segundos
    desenharPontos(37, 12, 0.0, 0.0, 0.0, 10); //pontos das horas
    desenharPonteiro(20, g_angulo_ponteiro_horas, 0.0, 0.0, 0.0, 10); //ponteiro das horas
    desenharPonteiro(30, g_angulo_ponteiro_minutos, 0.0, 0.0, 0.0, 5); //ponteiro dos minutos
    desenharAlgarismosRomanos(); //desenha os algarismos romanos
    desenharPonteiro(35, g_angulo_ponteiro_segundos, 1.0, 0.0, 0.0, 5); //ponteiro dos segundos
    desenharTexto(horario_digital, -20, -0.7); //desenhar o relogio digital

    //ordem para desenhar o que ta na lista
    glFlush();
}

void atualizar() {
    //pega data e hora atual
    struct tm *data_hora_atual;

    //tempo em segundos
    time_t time_segundos;

    //obtendo o tempo em time_segundos
    time(&time_segundos);

    //convertendo time_segundos para o tempo local
    data_hora_atual = localtime(&time_segundos);

    //log
    printf("[LOG] Atualizando [Hora: %d:%d:%d]...\n", data_hora_atual->tm_hour,
                                                      data_hora_atual->tm_min,
                                                      data_hora_atual->tm_sec);
    
    //calcula os angulos
    g_angulo_ponteiro_segundos = -(data_hora_atual->tm_sec * 6) + 90;
    g_angulo_ponteiro_minutos = -(data_hora_atual->tm_min * 6) + 90;
    g_angulo_ponteiro_horas = -(data_hora_atual->tm_hour * 30) + 90;

    //atualiza o horario digital
    sprintf(horario_digital, "%02d:%02d:%02d", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);

    //finalizando
    glutPostRedisplay();
    glutTimerFunc(1000, atualizar, 1);
}

//funcao de redimensionamento
void redimensionar(int largura, int altura) {
    printf("[LOG] Redimensionando...\n");

    double aspecto;

    //evita divisao por zero
    if (altura == 0)
        altura = 1;
    
    //atualiza o view port da janela
    glViewport(0, 0, largura, altura);

    //carrega matrix de projecao
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //atualiza o aspecto de visualizacao da camera
    aspecto = (double) largura/altura;

    if (largura >= altura)
        gluOrtho2D(-LARGURA_UNIVERSO * aspecto, LARGURA_UNIVERSO * aspecto, -ALTURA_UNIVERSO, ALTURA_UNIVERSO);
    else
        gluOrtho2D(-LARGURA_UNIVERSO, LARGURA_UNIVERSO, -ALTURA_UNIVERSO/aspecto, ALTURA_UNIVERSO/aspecto);
    
    //altera o a matrix utilizada
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}