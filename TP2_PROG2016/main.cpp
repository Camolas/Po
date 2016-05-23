#include <iostream>
#include <string>
#include <vector>

#include "Vende++.h"
#include "Menus.h"
#include "utils.h"
// More
#include "Cliente.h"
#include "Produto.h"
#include  "Transacao.h"
#include "Data.h"
#include "defs.h"

using namespace std;


vector<Cliente> le_fichClientes(string fichClientes);
vector<Transacao> le_fichTransacoes(string fichTransacoes); // por a funcao / metod

int main(){
	Data teste("12/05/1996");
	cout << teste;
  string loja, fichClientes, fichProdutos, fichTransacoes;
  
  le_fichClientes("clientes.txt");
  le_fichTransacoes("transacoes.txt");
  
  // pede a informacoo sobre o nome da loja e os 3 ficheiros com
  // informacoo de clientes, produtos e transacoes
  if(! infoInicial(loja, fichClientes, fichProdutos, fichTransacoes))
    return(-1);
  
  // cria uma loja
  VendeMaisMais supermercado(loja, fichClientes, fichProdutos, fichTransacoes);

  cout << "Informacao da loja '" << loja << " do supermercado Vende++:" << endl;
  cout << supermercado << endl;  // mostra estatisticas da loja
  
  opcoesIniciais(supermercado); // menu inicial com as grandes opcoes
				// que implementam as funcioanlidades
				// disonibilizadas
 
  return 0;
}

