// Lista Encadeada Baseada em Ponteiros

#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 7

#include "cLSEP.h"

// ***********************************************
// ***********************************************
// ***********************************************

int main(int argc, char** argv) {


int nL = MAX;

    if (argc > 1) {
        nL = atoi(argv[1]);
        if (nL < 1) {
            nL = MAX; 
        }
    }

    cLSEP L;

    srand( time(NULL) );

    std::cout << "########### LISTA INICIAL" << std::endl;
    L.imprimirLSEA();
    
    int i = 0;
    while ( ( i < nL ) && ( L.inserirElem(i) ) )
        i++;

    std::cout << "########### LISTA APOS INSERCOES" << std::endl;
    L.imprimirLSEA();

    L.removerElementosPares();

    std::cout << "########### LISTA APOS REMOCOES" << std::endl;
    L.imprimirLSEA();

    /*
    i = 0;
    while ( i < nL ) {
        if ( L.buscarElem(i * 10) )
            std::cout << "Achei a chave k = " << i*10 << std::endl;
        else 
            std::cout << "Não achei a chave k = " << i*10 << std::endl;
        i++;
        }
    */   
    
}
