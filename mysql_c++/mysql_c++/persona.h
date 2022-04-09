#pragma once
#include<iostream>
using namespace std;
class persona
{
	//atributos
protected: string nombres, apellidos, direccion,fecha_nacimiento;
		 int telefono;
		 //constructor
protected:
	persona() {
	}
		persona(string nom, string ape, string dir, int tel, string fn) {
			nombres = nom;
			apellidos = ape;
			direccion = dir;
			telefono = tel;
			fecha_nacimiento = fn;
	}
};

