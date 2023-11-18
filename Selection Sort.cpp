#include <iostream>
#include <stdlib.h>
#include <time.h>
// Aleatório
using namespace std;
const int TAM = 100;
// Para mudar o tamanho do vetor fácilmente, para rodar com 100.
int vetor[TAM];
int trocap = 0;
int comparacao = 0;

void iniciar(int vetor_[TAM])
{
for(int v =0; v < TAM; v++)
{
vetor_[v] = TAM - v;
}
}
void valores_aleatorios (int vetor_[TAM])
{
for(int a=0; a<TAM; a++){
vetor_[a] = rand() % TAM + 1;
}
}
void exibir(int vetor_[TAM])
// exibe e também é o vetor decrescente
{
for(int v = 0; v < TAM; v++)
{
cout << vetor_[v] << " - ";
}
cout << endl;
}
void crescente(int vetor_[TAM])
{
for(int v = 0; v < TAM; v++)
{
vetor_[v] = v;
cout << vetor[v]<< " - ";
}
}

void selectionsort(int vetor_[TAM])
{
int posicao_m;
int troca;
//auxiliar de troca
int v;
int p;
// Posições

for(p = TAM-1; p >= 0 ; p--)
{
posicao_m = p;
for(v = p ; v >= 0 ; v--)
{ comparacao = comparacao + 1;
// Contagem de comparação em cima do if, pois ele compara

mesmo que não entre no if

if(vetor_[posicao_m] <= vetor_[v])
{
posicao_m = v;
trocap = trocap + 1;
}
}
troca = vetor_[p];
vetor_[p] = vetor_[posicao_m];
vetor_[posicao_m] = troca;
}
}
int main()
{
setlocale(LC_ALL,"portuguese");

srand (time(NULL));

// Comente para utilizar cada vetor, ou seja, se for usar um comente os demais!

//aleatório
/**iniciar(vetor);
valores_aleatorios(vetor);
exibir(vetor);
cout << endl;
cout << endl;
selectionsort(vetor);
cout << endl;

exibir(vetor);
cout << endl;
cout << endl << " o número de trocas foi: " << trocap << endl;
cout << endl << " o número de comparações foi: " << comparacao << endl;

//decrescente
iniciar(vetor);
exibir(vetor);
cout << endl;
cout << endl;
selectionsort(vetor);
cout << endl;
exibir(vetor);
cout << endl;
cout << endl;
cout << endl << " O número de trocas foi: " << trocap;
cout << endl;
cout << endl;
cout << " O número de comparações foi: " << comparacao << endl;**/

// crescente
iniciar(vetor);
crescente(vetor);
cout << endl;
cout << endl;
selectionsort(vetor);
cout << endl;
exibir(vetor);
cout << endl << " o número de trocas foi: " << trocap << endl;
cout << endl << " o número de comparações foi: " << comparacao <<
endl;

return 0;
}