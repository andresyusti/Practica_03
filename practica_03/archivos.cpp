#include "archivos.h"

string leer_txt(string name){
  long long int tam;
  string data;
  fstream k(name, fstream::in | fstream::ate | fstream::binary);
  if(k.is_open()){
    tam=k.tellg();
    k.seekg(0);
    for(long long int i=0;i<tam; i++) data.push_back(k.get());
  }
  else cout<<"El archivo de texto no existe"<<endl;
  k.close();
  return data;
}

bool validar_administrador(string archivo, string usuario_ingresado, string clave_ingresado){

    string usuario_confirmar, clave_confirmar;
    bool ingreso=false;

    for(unsigned int i=0; i<archivo.length(); i++){
        for(;archivo[i]!=' '; i++){
            usuario_confirmar.push_back(archivo[i]);
        }
        for(i++;archivo[i]!='\n'; i++){
            clave_confirmar.push_back(archivo[i]);
        }
        if(usuario_ingresado==usuario_confirmar && clave_ingresado==clave_confirmar){
            cout << "Usted ha ingresado." << endl;
            ingreso=true;
        }
        else{
            usuario_confirmar.clear();
            clave_confirmar.clear();
        }
    }
    return ingreso;
}

string agregar_clientes(string archivo){
    string cedula, clave, saldo;

    cout << "Ingresar cedula: ";
    cin >> cedula;
    cout << "Ingresar clave: ";
    cin >> clave;
    cout << "Ingresar saldo: ";
    cin >> saldo;
    archivo = archivo + cedula + ";" + clave + ";" + saldo + "\n";
    return archivo;
}

string validar_clientes(string archivo, string cedula_ingresada, string clave_ingresada){
    string confirmar_cedula, confirmar_clave, saldo;

    for(unsigned int i=0; i<archivo.length(); i++){
        for(;archivo[i]!=';'; i++){
            confirmar_cedula.push_back(archivo[i]);
        }
        for(i++;archivo[i]!=';'; i++){
            confirmar_clave.push_back(archivo[i]);
        }
        for(i++;archivo[i]!='\n'; i++){
               saldo.push_back(archivo[i]);
        }
        if(cedula_ingresada==confirmar_cedula && clave_ingresada==confirmar_clave){
            cout << "Usted ha ingresado." << endl;
            return saldo;
        }
        else{
            confirmar_cedula.clear();
            confirmar_clave.clear();
            saldo.clear();
        }
    }
}

string retirar_dinero(string saldo){
    long int saldoint, dinero_retirar;
    istringstream(saldo) >> saldoint;
    saldoint -= 1000;
    while(true){
        cout << "Su saldo es de: " << saldoint << endl;
        cout << "Cuanto dinero desea retirar: ";
        cin >> dinero_retirar;

        if (dinero_retirar<0) cout << "Por favor ingresar numero positivos." << endl;

        else if (saldoint>=dinero_retirar){
            saldoint -= dinero_retirar;
            saldo = to_string(saldoint);
            return saldo;
        }

        else cout << "Usted no posee esa cantidad de dinero" << endl;
    }
}

string verificar_saldo(string saldo){
    long int saldoint;
    istringstream(saldo) >> saldoint;
    saldoint -= 1000;
    cout << "Su saldo es de: " << saldoint << endl;
    saldo = to_string(saldoint);
    return saldo;
}

string configurar_archivo_clientes(string archivo, string cedula, string clave, string saldo){
    string confirmar_cedula, confirmar_clave;
    string archivo2, saldo2;

    for(unsigned int i=0; i<archivo.length(); i++){
        for(;archivo[i]!=';'; i++){
            confirmar_cedula.push_back(archivo[i]);
        }
        for(i++;archivo[i]!=';'; i++){
            confirmar_clave.push_back(archivo[i]);
        }
        for(i++;archivo[i]!='\n'; i++){
            saldo2.push_back(archivo[i]);
        }

        if(cedula==confirmar_cedula && clave==confirmar_clave){
            archivo2 = archivo2 + cedula + ";" + clave + ";" + saldo + "\n";
        }
        else{
            archivo2 = archivo2 + cedula + ";" + clave + ";" + saldo2 + "\n";
            confirmar_cedula.clear();
            confirmar_clave.clear();
            saldo2.clear();
        }
    }
    return archivo2;
}



void escribir_txt(string name, string data){
    fstream k(name, fstream::out | fstream::binary);
    k.write(data.c_str(), data.length());
    k.close();
}
