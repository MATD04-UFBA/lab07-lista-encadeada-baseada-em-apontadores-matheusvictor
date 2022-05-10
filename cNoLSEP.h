/* Classe No de uma Lista Simplesmente Encadeada */ 

#pragma once

#include<iostream>

#define NULO NULL

class cNoLSEP {
  private: 
    float       dado;
    cNoLSEP*    prox;

  public:
    cNoLSEP();
    cNoLSEP(float dado);
    ~cNoLSEP();

    float       getDado();
    void        setDado(float d);

    cNoLSEP*    getProx();
    void        setProx(cNoLSEP* p);

    void imprimeNo();
    void imprimeDado();

};
