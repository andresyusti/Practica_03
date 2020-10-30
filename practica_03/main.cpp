#include "codificacion.h"

int main()
{
    string archivo_administradores = "sudo.txt";
    string archivo_clientes = "datos.txt";
    int metodo, semilla;

    cout << "Ingresar el metodo para la codificacion: ";
    cin >> metodo;
    cout << "Ingresar la semilla para la codificacion: ";
    cin >> semilla;
    aplicacion(archivo_administradores, archivo_clientes, metodo, semilla);

    return 0;
}
