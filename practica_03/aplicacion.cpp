#include "codificacion.h"

void aplicacion(string archivo_administradores, string archivo_clientes, int metodo, int semilla){
    int tipo_persona;
    string datos_administradores, datos_clientes;
    string usuario, clave, saldo;
    bool validar=false;

    datos_administradores = leer_txt(archivo_administradores);
    datos_administradores = text2bin(datos_administradores);
    datos_administradores = decodificar(datos_administradores, metodo, semilla);
    datos_administradores = bin2text(datos_administradores);

    datos_clientes = leer_txt(archivo_clientes);
    datos_clientes = text2bin(datos_clientes);
    datos_clientes = decodificar(datos_clientes, metodo, semilla);
    datos_clientes = bin2text(datos_clientes);

    cout << datos_administradores << endl;
    cout << datos_clientes << endl;


    while(true){

        cout << " ------------------" << endl;
        cout << "|Administrador (1) |" << endl;
        cout << "|Cliente       (2) |" << endl;
        cout << "|Salir         (3) |" << endl;
        cout << " ------------------" << "\n\n";

        cin >> tipo_persona;
        if(tipo_persona==1){
            cout << "Ingresar su usuario de administrador: ";
            cin >> usuario;
            cout << "Ingresar su clave de administrador: ";
            cin >> clave;
            cout << datos_administradores << endl;
            validar = validar_administrador(datos_administradores, usuario, clave);
            if (validar){

                while (true){

                    cout << " ------------------" << endl;
                    cout << "|Crear perfil  (1) |" << endl;
                    cout << "|Salir         (2) |" << endl;
                    cout << " ------------------" << "\n\n";

                    cin >> tipo_persona;
                    if(tipo_persona==1){
                        datos_clientes = agregar_clientes(datos_clientes);
                    }

                    else if (tipo_persona==2) break;

                    else cout << "Debe de ingresar una de las siguientes opciones." << endl;
                }
            }

            else cout << "El usuario o la contraseña son incorrectas." << endl;
        }

        else if(tipo_persona==2){
            cout << "Ingresar su cedula: ";
            cin >> usuario;
            cout << "Ingresar su clave: ";
            cin >> clave;
            cout << datos_clientes << endl;
            saldo = validar_clientes(datos_clientes, usuario, clave);
            //cout << "validar: " << validarstr << endl;

            if (saldo!=""){

                while(true){

                    cout << " --------------------" << endl;
                    cout << "|Retirar dinero  (1) |" << endl;
                    cout << "|Verificar saldo (2) |" << endl;
                    cout << "|Salir           (3) |" << endl;
                    cout << " --------------------" << "\n\n";

                    cin >> tipo_persona;
                    if (tipo_persona==1){
                        saldo = retirar_dinero(saldo);
                        datos_clientes = configurar_archivo_clientes(datos_clientes, usuario, clave, saldo);
                    }

                    else if (tipo_persona==2){
                        saldo = verificar_saldo(saldo);
                        datos_clientes = configurar_archivo_clientes(datos_clientes, usuario, clave, saldo);
                    }

                    else if (tipo_persona==3) break;

                    else cout << "Debe de ingresar una de las siguientes opciones." << endl;
                }
            }

            else cout << "Su cedula o clave son incorrectas." << endl;
        }

        else if (tipo_persona==3) break;

        else cout << "Debe de elegir una de las siguientes opciones." << "\n\n";
    }

    datos_clientes = text2bin(datos_clientes);
    datos_clientes = codificar(datos_clientes, metodo, semilla);
    datos_clientes = bin2text(datos_clientes);
    escribir_txt("datos.txt", datos_clientes);

    datos_administradores = text2bin(datos_administradores);
    datos_administradores = codificar(datos_administradores, metodo, semilla);
    datos_administradores = bin2text(datos_administradores);
    escribir_txt("sudo.txt", datos_administradores);

    cout << "archivos guardados." << endl;
}
