#include <iostream>
#include <stdlib.h> //
Srand, rand
#include <time.h> //
Tempo
#include <conio.h>

using namespace std;

const int TAM = 10;
// mude o tamanho pela constante
int vetor[TAM];
int troca = 0;
int comparacao = 0;
void subir(int vetor[TAM], int tam)
// controle de tamanho
{
int auxiliar;
// Auxilia na troca
int pai=tam/2;

if(pai>=1)
{
if(vetor[tam] > vetor[pai])
{
// se tiver maior ptioridade faz a troca
troca = troca + 1;
auxiliar=vetor[tam];
vetor[tam]=vetor[pai];
vetor[pai]=auxiliar;
subir(vetor,pai);
// Atualiza o tam

}
comparacao = comparacao + 1;
// Contagem da comparação
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

if((esquerda <=tam) && (vetor[esquerda] > vetor[posicao]
))
{
maior = esquerda;

}
if((direita <= tam) && (vetor[direita] > vetor[maior]))
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
void aleatorios(int vetor[TAM])
{
for(int a=1; a<=TAM; a++)
{
vetor[a] = rand() % TAM + 1;
subir(vetor,a);
}
}
void exibe (int vetor[TAM])
{
for(int c=1;c<=TAM;c++){
cout << vetor[c] << " - ";
}
cout << endl;
}
void crescente(int vetor[TAM])
{
for(int c=1; c<=TAM; c++)
{
vetor[c]=c;
subir(vetor,c);
}
}
void decrescente(int vetor[TAM])
{
for(int d=1; d<=TAM; d++)

{
vetor[d]= TAM - d;
subir(vetor,d);
}
}
int main()
{

setlocale(LC_ALL,"portuguese");
srand(time(NULL));
//Para alterar o vetor só mudar a chamada da função!
aleatorios(vetor);
exibe(vetor);
cout << endl << " O número de trocas é: " << troca;
cout << endl << " O número de comprações é: " <<
comparacao;
cout << endl;
return 0;
}