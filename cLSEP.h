/* Classe No de uma Lista Simplesmente Encadeada */ 

#pragma once

#include<iostream>

#include "cNoLSEP.h"

class cLSEP {               // Lista Simplesmente Encadeada baseada em Ponteiros

private:
    cNoLSEP*    inicio;     // Endereço do primeiro elemento da lista dentro da memoria heap
    int         numElems;	// numero de elementos na lista em um determinado momento

    bool buscarElem(float k, cNoLSEP* &noCor, cNoLSEP* &noAnt);

public:
    cLSEP();
    ~cLSEP();

    bool inserirElem(float k);

    bool inserirElementoInicio(float k);

    bool removerElem(float k);
    
    bool removerElementosPares();

    bool removerPosicoesImpares();

    bool buscarElem(float k);
    
    bool buscarElem(float k, cNoLSEP* &pos);    

    void imprimirLSEA();
    
};
