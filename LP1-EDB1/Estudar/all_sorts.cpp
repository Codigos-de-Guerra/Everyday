#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>

using value_type = int;
using Compare = std::function< bool(value_type, value_type) >;

bool comp( value_type a, value_type b )
{
    return a < b;
}

value_type * partition( value_type *first, value_type *last, value_type * pivot, Compare comp ){
    std::swap(*pivot, *(last - 1));
    pivot = last - 1;

    value_type *left_last = first; //left_last 

    while(first != last - 1){
        if(comp(*first, *pivot)){
            std::swap(*first, *(left_last++));
        }first++;
    }std::swap(*pivot, *left_last);

    return ans;
}

void merge( value_type *l_first, value_type *l_last, // [l_first; l_last)
            value_type *r_first, value_type *r_last, // [r_ first; r_last)
            value_type *a_first, Compare comp= std::less<value_type>() ){

    while(l_first != l_last){
        if(r_first == r_last){
            std::copy(l_first, l_last, a_first);
            return;
        }
        if(comp(*r_first, *l_first)){
            *(a_first++) = *(r_first++);
        }else{
            *(a_first++) = *(l_first++);
        }
    }std::copy(r_first, r_last, a_first);
}

void insertionSort(value_type *first, value_type *last, Compare comp){
    /**
    Descricao
    O vetor vai ser dividido em dois subvetores: um ordenado seguido de outro nao
    ordenado. A parte ordenada ira crescer 1 elemento em cada iteracao.
    Serao realizadas n iteracoes, cada iteracao se baseia nos seguintes passos:
    1. Pegue o primeiro elemento da parte nao ordenada
    2. ENCONTRE, no vetor ordenado, a posicao em que esse elemento deve ir
    3. INSIRA esse elemento na posicao encontrada
    A insercao dos elementos eh a operacao mais custosa do algoritmo (quando trabalhando
    com vetores), pois eh realizada linearmente. Por isso, o uso de outra busca (mais rapida)
    sem ser a linear nao se faz necessario.
    **/

    value_type *last_sorted = first; //posicao apos o ultimo elemento da parte ordenada
    value_type *i; //ponteiro que ira ENCONTRAR a posicao em que o elemento devera ser INSERIDO

    //PRE-CONDICAO: first <= last
    //INVARIANTE DE LAÇO: elementos com endereços anteriores ao de last_sorted estao
    //ordenados
    while(last_sorted != last){ // N iteracoes
        for(i = last_sorted - 1; i >= first; i--){
            if(comp(*i, *(i + 1))){ //Iterar ate que v[i - 1] < v[i]
                break;
            }else{
                std::swap(*i, *(i + 1));
            }
        }
        last_sorted++;
    }
    //FUNCAO DECREMENTO: last - last_sorted
    //POS-CONDICAO: O VETOR ESTA ORDENADO

    /**
    Analise de Complexidade
    Sempre teremos N iteracoes = insercoes, pois vamos inserir sempre 1 elemento
    de cada vez na parte ordenada. Iteracoes representadas pelo laço (while(last_sorted != last)).

    Agora resta saber quantas operacoes por insercao. Cada operacao terá seu laço
    for(i = last_sorted - 1; i >= first; i--).
    -> No pior caso, teremos que, em cada operaçao, esse laço sera executado ate o final,
    ou seja, ate i < first. Para que isso ocorra, eh necessario que a condicao
    (comp(*(i - 1), *i)) nunca seja satisfeita, ou seja, que o elemento a ser INSERIDO
    seja menor que todos os elementos no vetor. Como isso ocorre? O elemento a ser INSERIDO,
    enquanto dentro do laço, será representado pelo ponteiro (i + 1). A funcao comp(x ,y)
    responde verdadeiro para x < y. Ou seja, se comp(*i, *(i + 1)) nunca for atendida,
    eh porque !(*i  < *(i + 1)), ou seja, (*i >= *(i + 1)). Como i irá percorrer o vetor
    completo, e a condicao nunca será satisfeita, o valor a ser inserido será sempre menor.
    Em resumo, o pior caso ocorre quando o elemento a ser inserido é sempre menor que todos
    os elementos no vetor ordenado, ou seja, é sempre menor que os elementos já inseridos.
    Para que isso ocorra, nosso vetor original teria a seguinte configuração:
    v0 >= v1 >= ... >= vn.
    Fica facil de ver que esse é um vetor ordenado de forma decrescente.

    -> No melhor caso, a condição (comp(*(i - 1), *i)) será atendida logo de primeira. Ou seja,
    o elemento a ser inserido é maior do que o último elemento da parte ordenada. Já que estamos
    tratando da parte ordenada, o último elemento é o maior de todos. Logo, o elemento inserido
    é maior que todos elementos já inseridos. Então, fica fácil de ver que nosso vetor teria a
    seguinte configuração:
    v0 < v1 < ... < vn.

    Melhor caso: F pertence a Ω(N). Cada insercao so vai realizar uma operação de
    comparação e troca. Como 1 eh uma constante, o tempo fica linear.
    Pior caso: F pertence a O(N ^ 2). Cada insercao precisa percorrer todos elementos
    ja inseridos (o que nao é constante!). Mais precisamente, a i-ésima insercao
    vai percorrer (i - 1) elementos. Havendo N elementos, teriamos uma P.A indo de 0
    até N - 1. Pela fórmula da soma dos termos de uma P.A, temos:
    Quantidade de termos = N
    Primeiro termo = 0
    Ultimo termo = N - 1
    N(N - 1 - 0) / 2 = (N ^ 2) / 2.
    **/

    /**
    Propriedades
    Adaptativo (eficiente para dados ordenados)
    Estável (não altera a ordem relativa de elementos com chaves repetidas)
    in-place (apenas requer uma quantidade de memória constante Op1q para funcionar)
    online (pode ordenar uma lista à medida que a recebe)
    correto (...)

    **/

}

void selectionSort(value_type *first, value_type *last, Compare comp){

    value_type *last_sorted = first; //Limite da parte ordenada
    value_type *i, *min; //Ponteiros para iterar e para armazenar o minimo

    //PRE-CONDICAO: first <= last
    //INVARIANTE DE LAÇO: Elementos com enderecos anteriores aos de last_sorted
    //sao os menores do vetor e estao ordenados
    while(last_sorted != last - 1){
        min = last_sorted;
        for(i = last_sorted + 1; i < last; i++){
            if(*i < *min){
                min = i;
            }
        }std::swap(*last_sorted, *min);
        last_sorted++;
    }
    //FUNCAO DECREMENTO: (last - last_sorted)
    //POS-CONDICAO: O vetor esta ordenado

    /**
    Analise de Complexidade
    Sempre vamos realizar (N - 1) selecoes (a ultima selecao eh trivial).
    Cada selecao ira custar, seja m o tamanho da parte nao ordenada, (m - 1) iteracoes.
    (Nao precisamos checar se o primeiro elemento eh menor que o minimo, se o minimo
    for inicializado com o valor do primeiro elemento).
    Nao importa a configuracao do vetor, o algoritmo sempre ira realizar a mesma
    quantidade de passos para certo tamanho.
    Logo, temos no pior e no melhor caso uma P.A, como no pior caso do Insertion Sort.
    So que, dessa vez, temos:
    Quantidade de termos = N - 1
    Primeiro termo = N - 1 (vamos percorrer o vetor inteiro, comecando do segundo elemento
    para acharmos o menor elemento)
    Ultimo termo = 1 (faltando 2 elementos, vamos apenas checar se o segundo é menor que o primeiro)

    (N - 1)(N - 1 - 1) / 2 <= (N ^ 2) / 2.

    Logo, Θ(N ^ 2).
    **/
}

void bubbleSort(value_type *first, value_type *last, Compare comp){
    bool is_sorted = false;

    while(!is_sorted){
        is_sorted = true;
        for(value_type *i = first; i < last - 1; i++){
            if(!comp(*i, *(i + 1))){
                std::swap(*i, *(i + 1));
                is_sorted = false;
            }
        }
    }
}

void quickSort(value_type *first, value_type *last, Compare comp){
    if(std::distance(first, last) <= 1) return;

    value_type *left_last = partition(first, last, (last - 1), comp);
    quickSort(first, left_last, comp);
    quickSort(left_last, last, comp);

    return;
}

void mergeSort(value_type *first, value_type *last, Compare comp){
    int size = std::distance(first, last);

    if(size == 1) return;

    value_type *left = new value_type[size / 2];
    std::copy(first, first + (size / 2), left);
    mergeSort(left, left + (size / 2), comp);

    value_type *right = new value_type[size - (size / 2)];
    std::copy(first + (size / 2), last, right);
    mergeSort(right, right + (size - (size / 2)) , comp);

    merge(left, left + (size / 2), right, right + (size - (size / 2)), first, comp);

    delete[] right;
    delete[] left;

    return;
}

int main(){
    // int A[] = {1,2,3,4,5,6,7,8,9,10};
    // int A_size = std::distance(std::begin(A), std::end(A));

    // int A[] = {10,9,8,7,6,5,4,3,2,1};
    // int A_size = std::distance(std::begin(A), std::end(A));

    int A[] = {5,3,2,1,4,7,8,9,6,10};
    int A_size = std::distance(std::begin(A), std::end(A));

    int *B = new int[A_size];

    printf("Testando o insertion sort\n");
    std::copy(std::begin(A), std::end(A), B);

    std::cout << "Before sorting: \n";
    std::copy(B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n";
    insertionSort(B, B + A_size, comp);
    std::cout << "Afther sorting: \n";
    std::copy( B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n\n";

    printf("Testando o selection sort\n");
    std::copy(std::begin(A), std::end(A), B);

    std::cout << "Before sorting: \n";
    std::copy( B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n";
    selectionSort(B, B + A_size, comp);
    std::cout << "Afther sorting: \n";
    std::copy( B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n\n";

    printf("Testando o bubble sort\n");
    std::copy(std::begin(A), std::end(A), B);

    std::cout << "Before sorting: \n";
    std::copy(B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n";
    bubbleSort(B, B + A_size, comp);
    std::cout << "Afther sorting: \n";
    std::copy( B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n\n";

    printf("Testando o quick sort\n");
    std::copy(std::begin(A), std::end(A), B);

    std::cout << "Before sorting: \n";
    std::copy( B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n";
    quickSort(B, B + A_size, comp);
    std::cout << "Afther sorting: \n";
    std::copy( B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n\n";

    printf("Testando o merge sort\n");
    std::copy(std::begin(A), std::end(A), B);

    std::cout << "Before sorting: \n";
    std::copy( B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n";
    mergeSort(B, B + A_size, comp);
    std::cout << "Afther sorting: \n";
    std::copy( B, B + A_size, std::ostream_iterator< value_type >( std::cout, " " ) );
    std::cout << "\n\n";

}
