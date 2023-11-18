#include <iostream>
#include <locale.h>
using namespace std;

typedef struct arvore Tarvore;

struct arvore
{
int dado;
Tarvore * direita;
Tarvore * esquerda;
};

void insere(Tarvore *&arvore, int valor)
// função de inserir que recebe como parâmetro a
árvore e referência, já que

// vamos alterar, verificamos se a arvore está vazia,
pois se estiver alocamos
// um espaço de memória, então arvore no campo dado
vai receber o valor que
// estou passando e os ponteiros da direita e
esquerda vão receber null
// ao inserir mais um valor vamos verificar se ele é
maior ou menor que a raiz.
// ex: se for maior, vamos fazer uma chamada
recurssiva passando o ponteiro
// a direita e o valor.
// o mesmo será feito para a esquerda, mas sendo
menor.

// é interessante ressaltar que: sempre vai estar
caindo no primeiro if, pois
//estimulamos que os filhos serão nulos
{
if(arvore == NULL)
{
arvore = new(Tarvore);
arvore->dado = valor;
arvore->esquerda = NULL;
arvore->direita = NULL;
}
else
{
if (valor > arvore->dado)
{
insere(arvore->direita, valor);
}

else if (valor < arvore->dado) //para evitar
repetições
{
insere(arvore->esquerda, valor);
}
}
}

void ordem_simetrica(Tarvore *arvore)

// função de ordem simétrica que exibe os valores da
esquerda, o visita e
//depois a direita, colocando os números de maneira
crescente

{
if(arvore != NULL)
{
ordem_simetrica(arvore->esquerda);
cout << endl << arvore->dado << " ";
ordem_simetrica(arvore->direita);
}
}

Tarvore* busca(Tarvore *arvore,int valor )

// função de busca que retorna um ponteiro do tipo
Tárvore, passando
// a arvore por parâmetro e o valor que iremos
procurar, nada vai ser alterado.

// Adiante, verificamos se a árvore está vazia, pq se
não tiver ninguém ela vai
// retornar que o ponteiro é nulo. Depois verificamos
se o valor que buscamos
// está na raiz, se sim retornamos ele, para ai
procurar na esquerda se for
// menor ou na direita se for maior

{

if(arvore == NULL){

return NULL;
}
else{

if(valor == arvore -> dado){
return arvore;
}
else if (valor < arvore->dado) {
busca(arvore ->direita, valor);
}
else if (valor > arvore -> dado){
busca(arvore ->esquerda, valor);
}
}
}
int main()
{

setlocale(LC_ALL, "portuguese");

Tarvore* arv = NULL;

Tarvore *valor;

insere(arv, 9);
insere(arv, 12);
insere(arv, 10);
cout << endl << " Valores em ordem simétrica: "
<< endl;
cout << endl;
ordem_simetrica(arv);
cout << endl;
cout << endl;
cout << endl <<
"----------------------------------------------------
----------------" << endl;
cout << endl << " Mais
Informações " << endl;
valor = busca(arv,9);
cout << endl;
cout << endl << " O valor encontrado na busca é:
" << valor -> dado << endl;
cout << endl;
cout << endl <<
"----------------------------------------------------
----------------" << endl;

return 0;
}