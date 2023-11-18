#include <iostream>
#include <stdlib.h>
// Srand, rand
#include <time.h>
// Tempo
#include <conio.h>

using namespace std;

const int TAM = 10;
int vetor[TAM];
int p = 1;
int tam;

void subir(int vetor[TAM], int tam)//controle de
tamanho
{
int auxiliar;
// Auxilia na troca
int pai=tam/2;

if(pai>=1)
{

if(vetor[tam] > vetor[pai])
{
// se tiver maior ptioridade faz a troca

auxiliar=vetor[tam];
vetor[tam]=vetor[pai];
vetor[pai]=auxiliar;
subir(vetor,pai);
// Atualiza o tam

}

}
}
void descer(int vetor[TAM], int tam, int posicao)
{
int auxiliar;
//troca
int esquerda = 2 * posicao;
// filho esquerdo
int direita = 2 * posicao + 1;
// filho direito
int maior = posicao;

if((esquerda <=tam) && (vetor[esquerda] >
vetor[posicao] ))
{

maior = esquerda;

}
if((direita <= tam) && (vetor[direita] >
vetor[maior]))
{

maior = direita;

}
if(maior != posicao)
{
auxiliar = vetor[posicao];
vetor[posicao] = vetor[maior];
vetor[maior] = auxiliar;
descer(vetor, tam, maior);
}
}

void inserir(int *vetor,int elemento){

tam = tam + 1;
vetor[tam]=elemento;
subir(vetor,tam);

}

void excluir(int *vetor){
vetor[p]= vetor[tam];
tam = tam - 1;
descer(vetor, tam, p);

}
void exibir(int vetor[TAM])
{
for(int e=1;e<=tam;e++){

cout << vetor[e] << " - ";

}

cout << endl;

}

int main(){

inserir(vetor,15);
inserir(vetor,6);
inserir(vetor,8);
inserir(vetor,2);
inserir(vetor,3);
exibir(vetor);
excluir(vetor);

exibir(vetor);
excluir(vetor);
exibir(vetor);
return 0;
}