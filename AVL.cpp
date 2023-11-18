#include <iostream>
#include <locale.h>

using namespace std;

typedef struct elemento Tarvore;

struct elemento{
int dado;
Tarvore *esquerda;
Tarvore *direita;
};

//Função do tipo inteiro que calcula a altura da
árvore, onde é passado por [
//referência a árvore, com variáveis de altura a
direita e esquerda que vão
//servir para estipular qual a maior altura.
Primeiro, verifico se a árvore é
//nula, pois se for retornará 0, caso contrário será
feita uma recurssão para
//receber a altura passando o ponteiro da esquerda e
da direita.
//Por fim, verifica se a direita é maior que a
esquerda, se for retorna
//a altura da direita + 1, se não retorna a altura da
esquerda +1

int altura(Tarvore *arvore)
{

int altura_direita;
int altura_esquerda;

if( arvore == NULL){
return 0;
} else
{
altura_esquerda = altura(arvore->esquerda);
altura_direita = altura(arvore->direita);
if (altura_direita > altura_esquerda) return
altura_direita+1;

else return altura_esquerda+1;

}
}

//Função que rotaciona a direita, nela é passado por
parâmetro e referência o nó
//desregulado e dois ponteiros do tipo Tarvore filho
e nó_inserido, onde o filho
//vai receber o ponteiro do nó_desregulado a
esquerda, o nó_inserido vai rece-
//ber o ponteiro do filho a direita, o ponteiro do
filho a direita vai receber
//o nó_desregulado, o ponteiro do nó_desregulado a
esquerda recebe o nó_inserido
//e o nó_desregulado recebe o filho, tornando o filho
a nova raiz.

//explicação mais lixo kk que ue já dei na minha
vida, juro que eu tentei kkkk

void rotacao_direita(Tarvore *&no_desregulado)
{

Tarvore *filho, *no_inserido;
filho = no_desregulado->esquerda;
no_inserido = filho->direita;
filho->direita = no_desregulado;
no_desregulado->esquerda = no_inserido;

no_desregulado = filho;

}

//Função que rotaciona a esquerda, funciona com a
mesma lógica da direita só que
//ao contrário

void rotacao_esquerda(Tarvore *&no_desregulado)
{

Tarvore *filho, *no_inserido;

filho = no_desregulado->direita;
no_inserido = filho->esquerda;
filho->esquerda = no_desregulado;
no_desregulado->direita = no_inserido;

no_desregulado = filho;

}

// Função de rotação dupla a direita, nela é chamada
a rotação a esquerda
// para o filho, depois a direita para o pai

void rotacao_dupla_direita(Tarvore *&arvore)
{

rotacao_esquerda(arvore->esquerda);
rotacao_direita(arvore);
}

// A mesma coisa da função anterior, só que ao
contrário, ou seja, vou chamar
//a rotação a direita para o filho e a esquerda para
o pai

void rotacao_dupla_esquerda(Tarvore *&arvore)
{

rotacao_direita(arvore->direita);
rotacao_esquerda(arvore);
}

void balancear(Tarvore*&arvore, int valor){

int altura_direita, altura_esquerda;
altura_esquerda = altura(arvore->esquerda);
altura_direita = altura(arvore->direita);

// será verificado qual nó está desbalanceado,
se está desbalanceado
// para esquerda ou pra direita

if((altura_direita - altura_esquerda) > 1){
// esse primeiro if é auto explicativo

if
(altura(arvore->direita->direita)>altura(arvore->dire
ita->esquerda)){

//se a altura da direita a direita for

maior

// ele vai chamar a rotação a esquerda,

passando a árvore e se for

// menor vai chamar a rotação dupla a

esquerda

rotacao_esquerda(arvore);
}
else{

// caso contrário faz uma rde

rotacao_dupla_esquerda(arvore);
}
}
// a mesma coisa ideia
else if((altura_esquerda - altura_direita) > 1){
if
(altura(arvore->esquerda->esquerda)>altura(arvore->es
querda->direita)){

rotacao_direita(arvore);
}
else{

rotacao_dupla_direita(arvore);
}
}
}

int insere(Tarvore *&arvore, int valor)
{
if(arvore == NULL)
{
arvore = new(Tarvore);
arvore->dado = valor;

arvore->direita = NULL;
arvore->esquerda = NULL;

// se a árvore for nula vamos alocar um espaço de
memória, além de fazer
//receber o valor e colocar os ponteiros para null

return 0;

}
else
{ // se for menor ou igual insere a esquerda, se
não a direita
if(valor >= arvore->dado)
{
insere(arvore->direita,valor);
}
else
{
insere(arvore->esquerda,valor);
}
balancear(arvore,valor);
}
}

void ordem_simetrica(Tarvore *arvore){

if(arvore != NULL){

ordem_simetrica(arvore->esquerda);
cout << arvore->dado << " ";

ordem_simetrica(arvore->direita);
}
}

int main()
{
setlocale(LC_ALL, "portuguese");

Tarvore *arv = NULL;

insere(arv,9);
insere(arv,13);
insere(arv,19);
insere(arv,2);
insere(arv,1);

cout << endl << " Informações da AVL
" << endl;
cout << endl << endl;
cout << "Percursso simétrico: ";
cout << endl;
cout << endl;
ordem_simetrica(arv);

cout << endl << endl;

cout << "Valor a esquerda: " << arv->esquerda->dado
<< endl;
cout << "Valor da Raiz : " << arv->dado << endl;
cout << "Valor a direita : " << arv->direita->dado
<< endl;

cout << "Altura da árvore : " << altura(arv) <<
endl;

cout << endl << endl;

return 0;
}