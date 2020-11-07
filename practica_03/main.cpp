#include "codificacion.h"

int main()
{
    string archivo_administradores = "sudo.dat";
    string archivo_clientes = "datos.txt";
    int metodo, semilla, elegir;
    string datos_administradores;

    cout << "Ingresar el metodo para la codificacion: ";
    cin >> metodo;
    cout << "Ingresar la semilla para la codificacion: ";
    cin >> semilla;
    cout << "ingresar que quiere hacer: ";
    cin >> elegir;
    if (elegir==1){
        datos_administradores = leer_txt(archivo_administradores);
        datos_administradores = text2bin(datos_administradores);
        datos_administradores = decodificar(datos_administradores, metodo, semilla);
        datos_administradores = bin2text(datos_administradores);
        escribir_txt("resultado sudo.txt", datos_administradores);
    }
    else{
    aplicacion(archivo_administradores, archivo_clientes, metodo, semilla);
    }

    return 0;
}
