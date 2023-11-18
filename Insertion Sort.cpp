#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
// Aleatório

using namespace std;

int const TAM = 100;
// para alterar facilmente o tamanho do vetor
int comparacao = 0;
int troca = 0;
int vetor[TAM];

void insertion_sort(int vetor_[TAM])
{
int anterior;
int agora;
int auxiliar;

for(agora=1; agora<TAM; agora++)
{

comparacao++;
//Conta as comparações

auxiliar = vetor_[agora];
anterior = agora - 1;

while((anterior>=0)&&(auxiliar<vetor_[anterior]))
// compara e vê se é menor
{

troca++;
vetor_[anterior+1] = vetor_[anterior];
anterior--;
//decremento

}
vetor_[anterior+1] = auxiliar;
// Termina a troca se houver
}
}

void exibir(int vetor_[TAM])
{
cout << endl;

for(int i=0; i<TAM; i++){

cout << vetor_[i] << " - ";

}

}

void valores_aleatorios (int vetor_[TAM])
{
for(int a=0; a<TAM; a++){
vetor_[a] = rand() % TAM + 1;

}
}
void crescente(int vetor_[TAM])
{

for(int i = 0; i < TAM; i++)
{
vetor_[i] = i;
cout << vetor[i]<< " - ";
}

}
void decrescente ( int vetor_[TAM] )

{

for ( int i = 0; i < TAM; i++ ) {
vetor_ [i] = TAM - i;
cout << vetor[i] << " - " ;
}

}
int main()
{

setlocale(LC_ALL,"portuguese");
srand (time(NULL));
// comando de valores aleatórios

//Comente para rodar cada vetor

/**valores_aleatorios(vetor);
cout << endl << "Os valores aleatório são: " << endl;
exibir(vetor);
insertion_sort(vetor);
cout << endl;
cout << endl;
exibir(vetor);
cout << endl;

cout << endl << "Número de trocas: " << troca;
cout << endl;
cout << endl << "Número de comparações: " << comparacao;
cout << endl;
cout << endl;**/

cout << endl << " Os valores crescentes são:" << endl;
crescente(vetor);
insertion_sort(vetor);
cout << endl;
cout << endl;
exibir(vetor);
cout << endl;
cout << endl << "Número de trocas: " << troca;
cout << endl;
cout << endl << "Número de comparações: " << comparacao;
cout << endl;
cout << endl;

/*cout << endl << "Os valores decrescentes são: " << endl;
cout << endl;
cout << endl;
decrescente(vetor);
insertion_sort(vetor);
cout << endl;

cout << endl;
exibir(vetor);
cout << endl;
cout << endl << "Número de trocas: " << troca;
cout << endl;
cout << endl << "Número de comparações: " << comparacao;
cout << endl;
cout << endl;*/
return 0;
}