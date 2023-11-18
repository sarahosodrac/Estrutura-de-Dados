#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
// Aleatório

using namespace std;

int const TAM = 100;
int vetor[TAM];
int comparacao;
int troca;

void valores_aleatorios (int vetor_[TAM])
{
for(int a=0; a<TAM; a++)
{
vetor_[a] = rand() % TAM + 1;

}
}

void decrescente ( int vetor_[TAM] )
{

for ( int d = 0; d < TAM; d++ )
{

vetor_[d] = TAM - d;

}

}

void crescente(int vetor_[TAM])
{

for (int c = 0; c < TAM; c++)
{

vetor_[c] = c;

}

}

void exibe(int vetor_[TAM])
{

for (int e=0; e<TAM; e++)
{

cout << vetor_[e] << " - ";

}
cout << endl;
}

void shellsort(int vetor_[TAM]){

int gap, c;
//pode chamar de h ou gap, por isso a conta do erthal h = h * 3 + 1;
// c == controle

int valor;
//guarda o valor para fazer a troca

// GAPS UTILIZADOS:
// comente para trocar de gap

//gap = 1;
//gap = TAM/2;
gap = TAM/3;

while(gap < TAM)
{

gap = gap * 2 + 3; //gap inicial

//TESTES ALEATÓRIOS PARA EU VER SE ORDENA:
//gap = gap * 3 + 1;
// Padrão
//gap = gap * 2 + 1;

// também ordena
} //gap = gap * 2 + 3;
//também ordena

while(gap > 1){

gap = gap/10;

for(int i = gap; i < TAM; i++){

valor = vetor_[i];
c = i - gap;
//comparação
comparacao = comparacao + 1;

while((c>=0) && (valor <=vetor_[c] ))
{// verificação

vetor_[c+gap] = vetor_[c];
// troca

c = c - gap;
troca = troca + 1;
}
vetor_[c+gap] = valor;
// troca

}
}

}

int main()
{

setlocale(LC_ALL,"portuguese");
srand (time(NULL));

crescente(vetor);
exibe(vetor);
cout << endl;
shellsort(vetor);
exibe(vetor);
cout << endl;

cout << endl << "O número de comparações foi: " << comparacao << endl;
cout << endl << "O número de trocas foi: " << troca << endl;

return 0;

}