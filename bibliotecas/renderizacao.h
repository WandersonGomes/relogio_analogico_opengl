#ifndef _RENDERIZACAO_H
#define _RENDERIZACAO_H

//funcoes de desenho
void desenharEixos2D();
void desenharCirculoPreenchido(float raio, int definicao, float r, float g, float b);
void desenharCirculoVazado(float raio, int definicao, float r, float g, float b, float espessura);
void desenharPontos(float raio, int qtd_pontos, float r, float g, float b, float espessura);
void desenharPonteiro(int raio, float angulo, float r, float g, float b, float espessura);
void desenharTexto(const char* texto, float x, float y);
void desenharAlgarismosRomanos();

void renderizar();

//funcao de redimensionamento
void redimensionar(int largura, int altura);

//funcao de atualizacao
void atualizar();

#endif