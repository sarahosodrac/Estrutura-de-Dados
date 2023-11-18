#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int const TAM = 10;
int vetor[TAM];
int troca = 0;
int comparacao = 0;

void aleatorio (int vetor_[TAM])
{
for(int a=0; a<TAM; a++){
vetor_[a] = rand() % TAM + 1;

}
}
void crescente(int vetor_[TAM])
{
for(int i = 0; i < TAM; i++)
{
vetor_[i]= i;

}

}
void decrescente(int vetor_[TAM])
{

for(int d=0; d<=TAM; d++)
{
vetor[d]= TAM - d;
}
}
int agrupa( int *vetor_,int inicio, int meio, int
fim)
{
int auxiliar[TAM];
// auxiliar é uma lista vazia onde serão colocados
os elementos
int esquerda = inicio;
//começo da primeira lista
int direita = meio;
// começo da segunda lista

for( int a = inicio; a < fim; a++)
{

if((esquerda < meio) && ((direita >= fim) ||
(vetor_[esquerda] < vetor_[direita]))){

auxiliar[a] = vetor_[esquerda];
esquerda++;

}
else{

auxiliar[a] = vetor_[direita];
direita++;

}

comparacao = comparacao + 1;
}
for(int c = inicio; c < fim; c++){

vetor_[c] = auxiliar[c];
// recebe o auxiliar pois ele que está recebendo
os valores ordenados, então eu passo para o vetor
principal

}

}
void mergesort(int *vetor_, int inicio, int fim)

{

int meio;
meio = ((inicio + fim) / 2);
// para pegar o meio

if(inicio < meio)
// se for menor a lista da esquerda vai ter
terminado
{
mergesort( vetor, inicio, meio);
// lista da direita
mergesort( vetor, meio, fim);
// lista da esquerda
troca = troca + 1;
agrupa(vetor_, inicio, meio, fim);
// agrupa os valores novamente

}

}
void exibe (int vetor_[TAM])
{

for(int e = 0; e < TAM; e++)
{
cout << vetor_[e] << " - ";

}
cout << endl;
}

int main()
{

aleatorio(vetor);
exibe(vetor);
mergesort(vetor, 0, TAM);
exibe(vetor);

cout << endl << " Foram realizadas " << troca <<
" trocas " << endl;
cout << endl << " Foram realizadas " <<
comparacao << " comparações " << endl;

return 0;
}