#include "Data.h"
#include "string"
#include <sstream>

Data::Data(string dataStr){ // data na forma DD/MM/AAA
	stringstream line(dataStr);
	line >> dia; line.ignore();
	line >> mes; line.ignore();
	line >> ano; line.ignore();
	/*
	getline(line, dataStr, '/');
	dia >> dataStr;
	*/
}

int Data::getDia() const{
	return dia;
}

int Data::getMes() const{
	return mes;
}

int Data::getAno() const{
	return ano;
}

void Data::setDia(int dia){
	this->dia = dia;
}

void Data::setMes(int mes){
	this->mes = mes;
}

void Data::setAno(int ano){
	this->ano = ano;
}


void Data::save(ofstream & out) const{
	out << dia << '/' << mes << '/' << ano;

}

ostream& operator<<(ostream& out, const Data & data){
	out << data.getDia() << '/' << data.getMes() << '/' << data.getAno();
	return out;
}
