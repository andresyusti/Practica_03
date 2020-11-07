#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

void aplicacion(string archivo_administrador, string archivo_clientes, int metodo, int semilla);



string leer_txt(string name);
bool validar_administrador(string archivo, string clave_ingresado);
string agregar_clientes(string archivo);

string validar_clientes(string archivo, string cedula_ingresada, string clave_ingresada);
string retirar_dinero(string saldo);
string verificar_saldo(string saldo);
string configurar_archivo_clientes(string archivo, string cedula, string clave, string saldo);

void escribir_txt(string name, string data);
