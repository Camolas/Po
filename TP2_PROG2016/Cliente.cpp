#include "Cliente.h"
#include <vector>
#include "utils.h"
#include "Data.h"

Cliente::Cliente(ifstream & in){ // le uma cliente na forma de  idcliente ; nome ; data ; montante
	string data_aux, cli_aux;
	float montante;
	string nome;

	//idcliente
	in >> id; in.ignore();
	
	//nome
	getline(in, nome, ';');
	trimSpaces(cli_aux);
	 //in.ignore();

	//data
	getline(in, cli_aux, ';');
	
	data_aux.erase(data_aux.begin()); 
	data_aux.erase(data_aux.end() - 1);               //apaga 1 e último espaço
	Data data(data_aux);

	//montante

	in >> montante; in.ignore();

	
}


string Cliente::getNome() const{
  return nome;
}
void Cliente::setId(string idRead) { 
}

void Cliente::setNome(string nameRead)
{
	nome = nameRead;
}

void Cliente::setVolCompras(string amountRead)
{
	volCompras = stof(amountRead);
}
unsigned int Cliente::getId() const{
	return id;
}


float Cliente::getVolCompras() const{
  return volCompras;
}

void Cliente::save(ofstream & out) const{

	out << id << ' ; ';
	out << nome << ' ; ';
	cartaoCliente.save(out); 
	out << volCompras;

}

Data Cliente::getCartaoCliente() const {
	return cartaoCliente;
}

 ostream& operator<<(ostream& out, const Cliente & cli){
	out << cli.getId() << ' ; ' << cli.getNome() << ' ; ';

	Data data = cli.getCartaoCliente();

	out << data;

	return out;
}


bool operator<(const Cliente &cli1, const Cliente &cli2){
	

	if (cli1.getNome() < cli2.getNome())
		return true;
	else
		return false;

}


//////////////////////
// Leitura ficheiro //
//////////////////////

vector<Cliente> le_fichClientes(string fichClientes){
	ifstream f_clientes;
	vector<Cliente> v_clientes;
	int num_clientes;

	f_clientes.open(fichClientes);

	f_clientes >> num_clientes; f_clientes.ignore();

	while (num_clientes)
	{
		Cliente cli(f_clientes);
		v_clientes.push_back(cli);
		num_clientes--;
	}
	f_clientes.close();

	return v_clientes;

}