#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionDB.h"
#include "persona.h"
using namespace std;

class Cliente : persona{
	//Atributo
private: string nit;
	//constructor
public:
	Cliente() {

	}
	Cliente(string nom, string ape, string dir, int tel, string fn, string n) : persona(nom,ape,dir,tel,fn){
		nit = n;
};
	// METODOS
  //set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	//get (mostrar)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	// metodo
	void crear() {
		int q_estado;
		ConexionDB cn = ConexionDB();
		cn.abrir_conexion();
		if(cn.getconectar())
		{
			string t = to_string(telefono);
			string insert = "INSERT INTO `db_empresa`.`clientes`(id_Clientes,nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES(´" + nit + "',´" + nombres + "', '" + apellidos + "´,´" + direccion + "´,´" + t + "', '" + fecha_nacimiento+ "); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Guardado Correctamente :)" << endl;
			}
			else {
				cout << "Error al ingresar los datos :(" << endl;
			}
		}
		else {
			cout << "----Conexion fallida----";
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionDB cn = ConexionDB();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "SELECT * FROM db_empresa.clientes;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1]<<" , " << fila[2] <<" , " << fila[3]<<" , " << fila[4]<<" , " << fila[5] <<" , " << fila[6]<<" , " << endl;
				}
			}
			else
			{
				cout << "Error al consultar los datos" << endl;
			}
		}
		else {
			cout << "----Conexion fallida----";
		}
		cn.cerrar_conexion();
	}
};

