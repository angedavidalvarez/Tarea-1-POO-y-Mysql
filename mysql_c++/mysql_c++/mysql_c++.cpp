// mysql_c++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<iostream>
#include "Cliente.h"
using namespace std;
int main()
{
    string nit, nombre, apellidos, direccion, fecha_nacimiento;
    int telefono;
    cout << "-- Bienvenido--" << endl;
    cout << "-- Ingrese Nit: ";
    getline(cin, nit);
    cout << "Ingrese Nombres: ";
    getline(cin, nombre);
    cout << "Ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Fecha de Nacimiento: ";
    cin >> fecha_nacimiento;
    Cliente c = Cliente(nombre, apellidos, direccion, telefono, fecha_nacimiento, nit);
    c.crear();
    c.leer();
    system("Pause");
    return 0;
}