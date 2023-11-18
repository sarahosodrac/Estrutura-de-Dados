#include <iostream>
#include <stdlib.h> // Srand, rand
#include <time.h>
// Srand, rand

using namespace std;

int const TAM = 100;
// Tamanho do vetor
int comparacao;
int troca;

typedef struct bubble Tlista;

struct bubble
{
int valor;
Tlista *proximo;

};

// COMENTE AS FUNÇÕES PARA RODAR

/*
void aleatorio(Tlista *&listap)
{
Tlista *auxiliar;

for(int c=0; c<TAM; c++)
{
if(listap == NULL)
{
auxiliar = new(Tlista);
auxiliar->valor = rand()%TAM;
auxiliar->proximo = NULL;
listap = auxiliar;
}
else
{
auxiliar = new(Tlista);
auxiliar->valor = rand()%TAM;
auxiliar->proximo = listap;
listap = auxiliar;
}
}
}/*
void decrescente(Tlista *&listap)

{
Tlista *auxiliar;

for(int i=0; i<TAM; i++)
{
if(listap == NULL)
{
auxiliar = new(Tlista);
auxiliar->valor = i;
auxiliar->proximo = NULL;
listap = auxiliar;
}
else
{
auxiliar = new(Tlista);
auxiliar->valor = i;
auxiliar->proximo = listap;
listap = auxiliar;
}
}
}*/
void crescente(Tlista *&listap)
{
Tlista *auxiliar;

for(int i=TAM; i>0; i--)

{
if(listap == NULL)
{
auxiliar = new(Tlista);
auxiliar->valor = i;
auxiliar->proximo = NULL;
listap = auxiliar;
}
else
{
auxiliar = new(Tlista);
auxiliar->valor = i;
auxiliar->proximo = listap;
listap = auxiliar;
}
}
}
void exibir(Tlista *listap)
{
Tlista*auxiliar;
auxiliar = listap;

while(auxiliar != NULL)
{

cout << auxiliar->valor << " - ";

auxiliar = auxiliar->proximo;

}

cout << endl;
}
void bubblesort(Tlista*listap)
{
Tlista *auxiliar, *segundo_auxiliar;
int j;

for(int i=0; i<TAM-1; i++)
{

auxiliar = listap;
// auxiliazr recebe a lista
segundo_auxiliar = listap->proximo;
// recebe o próximo da lista

for(int t=0; t<TAM-1; t++)
// verifica a troca
{
comparacao = comparacao + 1;
if(auxiliar->valor > segundo_auxiliar->valor)

{

j = segundo_auxiliar->valor;

segundo_auxiliar->valor = auxiliar->valor;
auxiliar->valor = j;
troca = troca + 1;

}
auxiliar = auxiliar->proximo;
segundo_auxiliar = segundo_auxiliar->proximo;
}
}
}
int main()
{

setlocale(LC_ALL,"portuguese");

srand(time(NULL));

Tlista *lista = NULL;

crescente(lista);
exibir(lista);
cout << endl;

bubblesort(lista);
exibir(lista);

cout << endl << "O número de trocas é: " << troca;
cout << endl << "O número de comparações foi: " << comparacao;

return 0;
}