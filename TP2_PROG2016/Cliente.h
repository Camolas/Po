
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Data.h"

using namespace std;


class Cliente {
private:
	unsigned int id;
	string nome;
	Data cartaoCliente;
	float volCompras;

public:
	//Cliente();
	Cliente(ifstream & in);
	string getNome() const;
	float getVolCompras() const;
	unsigned int getId() const;
	Data getCartaoCliente() const;
	void setId(string idRead);
	void setNome(string nameRead);
	void setVolCompras(string amountRead);
	void save(ofstream & out) const;
 ostream& operator<<(ostream& out);  // mostra informacao do cliente no ecra
	friend bool operator<(const Cliente &cli1, const Cliente &cli2); // compara 2 clientes (1 cleinte e menor que outro se o seu nome for "alfabeticamente" inferior)

};
