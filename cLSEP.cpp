#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#include "cLSEP.h"
#include "cNoLSEP.h"

// ***********************************************
// ***                                         ***
// ***********************************************
cLSEP::cLSEP() {			
	inicio 		= NULO;
    numElems 	= 0;
}

// ***********************************************
// ***                                         ***
// ***********************************************
cLSEP::~cLSEP() {

cNoLSEP* noCor;

	noCor = inicio;							

	while ( noCor != NULO) {
		inicio = noCor->getProx();
		delete noCor;
		noCor = inicio;
		numElems--;
	}			
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEP::inserirElem(float k) {

cNoLSEP* novoNo = NULO;
cNoLSEP* noCor 	= NULO;

	novoNo = new cNoLSEP;						// Cria uma alocação de um nó na memoria heap    

	if (novoNo == NULO) 						// alocação sem sucesso
		return false;

	novoNo->setDado(k);							// Coloca o novo dado no nó
	novoNo->setProx(NULO);						// Sinaliza que ele será o ultimo, apontando para NULO

	if(inicio == NULO) 							// Verifica se a lista esta vazia
		inicio = novoNo;						// e nesse caso é necessário atualizar o inicio da lista

	else {										// A lista tem pelo menos um elemento

		noCor = inicio;							// Inicia a busca do ultimo elemento da lista pelo primeiro

		while ( noCor->getProx() != NULO) 		// Busca o ultimo elemento, cujo campo prox do nó aponta para NULO
			noCor = noCor->getProx();			// Avança na lista pelo encadeamento, ou seja, o campo prox do nó

		noCor->setProx(novoNo);					// Encontrado o ultimo elemento faz com que ele aponte para o novo nó
		}	
		
	numElems++;									// Atualiza o numero de elementos armazenados na lista

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEP::inserirElementoInicio(float k) {

	cNoLSEP* noAtual = NULO;
	cNoLSEP* novoNo = NULO;

	novoNo = new cNoLSEP;						// Cria uma alocação de um nó na memoria heap    

	if (novoNo == NULO) { 						// alocação sem sucesso
		return false;
	}

	novoNo->setDado(k);							// Coloca o novo dado no nó
	novoNo->setProx(inicio);					// O novoNo irá apontar para o atual inicio (que passará a ser o segundo na linha abaixo)
	inicio = novoNo;							// O início da lista será o novo elemento inserido

	this->numElems++;

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEP::removerElem(float k) {

cNoLSEP* noCor;
cNoLSEP* noAnt;

	if ( numElems == 0 )						// Verifica se a lista é vazia (poderia verificar pelo inicio == NULO)
		return false;

	if (buscarElem(k, noCor, noAnt) == false)	// Busca a posição da chave na lista e seu nó anterior
		return false;							// Busca sem sucesso

	if (noAnt == NULO)  						// O elemento a ser removido é o primeiro
		inicio = noCor->getProx();				// Atualiza o inicio pois não há nó anterior ao primmeiro 
	else 										// O elemento a ser removido não é o primeiro
		noAnt->setProx(noCor->getProx());		// Atualiza o encadeamento do nó anterior para apontar para o proximo do nó a ser removido
	
	delete noCor;								// deletar a área de memória.
		
	numElems--;									// Reduz o numero de elementos da lista

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEP::removerElementosPares() {
	
	cNoLSEP* noAnterior = NULO;
	cNoLSEP* noAtual = inicio;
	cNoLSEP* noAuxiliar = NULO;

	int totalElementos = this->numElems;

	for (int i = 0; i < totalElementos; i++) {						

		if ((int) trunc(noAtual->getDado()) % 2 == 0) { // verifica se o dado armazenado em noAtual é par
			
			if (noAnterior == NULO) {
				inicio = noAtual->getProx();
				noAuxiliar = inicio;
			} else {
				noAnterior->setProx(noAtual->getProx());
				noAuxiliar = noAnterior->getProx();
			}
			
			delete noAtual;
			noAtual = noAuxiliar;
			this->numElems--; // decrementa o número de elementos que compõe a lista
			
		} else {
			std::cout << noAtual->getDado() << " eh impar" << std::endl;
			noAnterior = noAtual;
			noAtual = noAtual->getProx();

			std::cout << "noAtual = " << noAtual->getDado() << std::endl;
		}		
	}
		return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEP::buscarElem(float k, cNoLSEP* &pos) {
		
	pos = NULO;

	if ( numElems == 0 )						// Verifica se a lista é vazia (poderia verificar pelo inicio == NULO)
		return false;

	pos = inicio;								// Ajusta o apontador do nó corrente da busca para o primeiro da lista

	while 	( 	(pos != NULO) &&				// Final da lista encontrado 
				(pos->getDado() != k) 			// Chave de busca encontrada
			) {
		pos = pos->getProx();					// Nó corrente avança para o proximo nó da lista
		}

	if(pos == NULO) 							// Verifica se a busca terminou pelo final da lista
		return false;							// Busca sem sucesso

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEP::buscarElem(float k, cNoLSEP* &noCor, cNoLSEP* &noAnt) {

	noCor = 
	noAnt =	NULO;	

	if ( numElems == 0 )						// Verifica se a lista é vazia (poderia verificar pelo inicio == NULO)
		return false;

	noCor = inicio;								// Ajusta o apontador do nó corrente da busca para o primeiro da lista
	noAnt = NULO;								// Ajusta o apontador do nó anterior ao corrente para NULO (não há nó antes do primeiro)

	while 	( 	(noCor != NULO) &&				// Final da lista encontrado 
				(noCor->getDado() != k) 		// Chave de busca encontrada
			) {
		noAnt = noCor;							// Nó corrente na proxima repetição vira o nó anterior
		noCor = noCor->getProx();				// Nó corrente avança para o proximo nó da lista
		}

	if(noCor == NULO) 							// Verifica se a busca terminou pelo final da lista
		return false;							// Busca sem sucesso

	return true;
}

// ***********************************************
// ***                                         ***
// ***********************************************
bool cLSEP::buscarElem(float k) {
		
cNoLSEP* noCor = NULO;

	if ( numElems == 0 )						// Verifica se a lista é vazia (poderia verificar pelo inicio == NULO)
		return false;

	noCor = inicio;								// Ajusta o apontador do nó corrente da busca para o primeiro da lista

	while 	( 	(noCor != NULO) &&				// Final da lista encontrado 
				(noCor->getDado() != k) 		// Chave de busca encontrada
			) 
		noCor = noCor->getProx();				// Nó corrente avança para o proximo nó da lista

	if(noCor == NULO) 							// Verifica se a busca terminou pelo final da lista
		return false;							// Busca sem sucesso

	return true;								// Busca com sucesso
}

// ***********************************************
// ***                                         ***
// ***********************************************
void cLSEP::imprimirLSEA() {

	if (inicio == NULO) {
		std::cout << "*********** LISTA VAZIA ***********" << std::endl;
		return;
		}

	cNoLSEP* noCor = inicio;

	std::cout << "[ ";

	while (noCor != NULO) {
		noCor->imprimeNo();
		std::cout << " , ";
		noCor = noCor->getProx();
		}

	std::cout << " ]" << std::endl;

	std::cout << "-------------------------------" << std::endl;	

}
