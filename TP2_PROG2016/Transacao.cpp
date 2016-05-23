#include "Transacao.h"



unsigned int Transacao::getIdCliente() const{
	return idCliente;
}



Transacao::Transacao(ifstream & in){ // le uma transacao na forma de  idcliente ; data ; lista produtos
	string data_aux;
	string lista_prod_aux;
	vector<string> produtos_aux;
	string prod_individual;

	
	//idcliente
	in >> idCliente; in.ignore(); // ignora o ;

	cout << idCliente << endl;
	//data
	getline(in, data_aux, ';');
	//cout << 77 << endl;

	data_aux.erase(data_aux.begin()); data_aux.erase(data_aux.end() - 1);               //apaga 1 e último espaço
	//cout << 33 << endl;
	Data data(data_aux);
	
	//lista de produtos
	getline(in, lista_prod_aux);
	
	istringstream instr(lista_prod_aux);
	while (getline(instr, prod_individual, ','))
	{
		prod_individual.erase(0, prod_individual.find_first_not_of(' '));           //remove espacos iniciais
		produtos_aux.push_back(prod_individual);
	}
	produtos = produtos_aux;
	

}

void Transacao::save(ofstream & out) const{ // transacao guardada como na forma de  idcliente ; data ; lista produtos
	out << idCliente << " ; ";

	data.save(out); // na forma DD/MM/AAAAA
	out << " ; ";

	int ult = produtos.size();
	for (unsigned int i=0; i < produtos.size(); i++)
	{
		out << produtos[i];
		
		if ( ult!= produtos[i].size() - 1)             // so poe a vírgula se nao for o ultimo
			out << ", ";
	}

}


ostream& operator<<(ostream& out, const Transacao & trans){

	// A IMPLEMENTAR
	return out;
}


//////////////////////
// Leitura ficheiro //
//////////////////////

vector<Transacao> le_fichTransacoes(string fichTransacoes){
	ifstream f_transacoes;
	vector<Transacao> v_transacoes;
	int num_transacoes;

	f_transacoes.open(fichTransacoes);

	f_transacoes >> num_transacoes; f_transacoes.ignore();

	while (num_transacoes)
	{
		Transacao trans(f_transacoes);
		v_transacoes.push_back(trans);
		num_transacoes--;
		
	}
	f_transacoes.close();

	return v_transacoes;
}