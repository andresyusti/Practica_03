#include "codificacion.h"

string text2bin(string texto){
  string binario;
  for (unsigned long long int i=0;i<texto.length();i++){
    for (int j=0;j<8;j++){
      binario.push_back(char(((texto[i]<<j)&(0x80))/128+48));
    }
  }
  return binario;
}

string bin2text(string bin){
    string bin2, texto;
    unsigned long long int i, exponente, calculo, k=0;

    for (i=0;i<bin.length();i++){
        bin2.push_back(bin[i]);
        if (i==(k+1)*8-1){
            calculo=0;
            exponente=0;
            for (int c=7;c>=0;c--){
                if (bin2[c]=='1') calculo+=pow(2,exponente);
                exponente++;
            }
            texto+= calculo;
            k++;
            bin2.clear();
        }
    }
    return texto;
}

string decodificar(string archivo, int metodo, int semilla){
    if (metodo==1){
        string archivo2, copia, copia2;
        unsigned int k=0;
        for (unsigned long long int i=0;i<archivo.length();i++){
            copia.push_back(archivo[i]);
            if (k<1){
                if (archivo[i]=='1') archivo2.push_back('0');
                else archivo2.push_back('1');

                if (i==semilla-1){
                    copia2=archivo2;
                    copia.clear();
                    k++;
                }

            }
            else if (i==archivo.length()-1){
                copia2=cambio_debit1(copia, copia2);
                archivo2=archivo2+copia2;
            }
            else{
                if (i==(k+1)*semilla-1){
                    copia2=cambio_debit1(copia, copia2);
                    archivo2=archivo2+copia2;
                    copia.clear();
                    k++;
                }
            }
        }
        return archivo2;
    }

    else{
        string archivo2, copia;
        unsigned int k=0;

        for(unsigned int i=0;i<archivo.length();i++){
            copia.push_back(archivo[i]);
            if (i==(k+1)*semilla-1){
                archivo2+=cambio_debit2(copia);
                copia.clear();
                k++;

            }
            else if (i==archivo.length()-1){
                archivo2+=cambio_debit2(copia);
            }
        }
        return archivo2;
    }
}

string cambio_debit1(string partido, string partido2){
    long int unos=0,ceros=0;
    for (unsigned long long int i=0;i<partido.length();i++){
        if (partido2[i]=='1') unos++;
        else ceros++;
    }

    if (unos==ceros){
        for(unsigned int c=0;c<partido.length();c++){
            partido=intercambio(partido, c);
        }
    }

    else if(ceros>unos){
        for (unsigned int c=1;c<partido.length();c+=2){
            partido=intercambio(partido, c);
        }
    }

    else{
        for (unsigned int c=2;c<partido.length();c+=3){
            partido=intercambio(partido, c);
        }
    }
    return partido;
}

string intercambio(string bi, int c){
    if(bi[c]=='1') bi[c]='0';
    else bi[c]='1';
    return bi;
}

string cambio_debit2(string bi){
    unsigned int i;
    string bi2, copia;
    for (i=1;i<=bi.length();i++){
        if (i==bi.length()) bi2+=bi[0];
        else bi2+=bi[i];
    }
    return bi2;
}


string codificar(string archivo, int metodo, int semilla){
    if (metodo==1){
        string copia, copia2, archivo2;
        for (unsigned long long int i=0, k=0;i<archivo.length();i++){
              copia.push_back(archivo[i]);
              if (k<1){
                  if (archivo[i]=='1') archivo2.push_back('0');
                  else archivo2.push_back('1');

                  if (semilla-1==i){
                      copia2=copia;
                      copia.clear();
                      k++;
                  }
              }
              else if (i==archivo.length()-1){
                  archivo2=archivo2+cambio_bit1(copia,copia2);
              }

              else{
                  if ((k+1)*semilla-1==i){
                    archivo2=archivo2+cambio_bit1(copia,copia2);
                    copia2=copia;
                    copia.clear();
                    k++;
                  }
              }
        }
        return archivo2;
    }

    else{
        string archivo2, copia;
        unsigned int k=0;

        for(unsigned long long int i=0;i<archivo.length();i++){
            copia.push_back(archivo[i]);
            if (i==(k+1)*semilla-1){
                archivo2+=cambio_bit2(copia);
                copia.clear();
                k++;
            }
            else if (i==archivo.length()-1){
                archivo2+=cambio_bit2(copia);
            }
        }
        return archivo2;
    }
}

string cambio_bit1(string partido, string partido2){
    long int unos=0,ceros=0;
    for (unsigned long long int i=0;i<partido.length();i++){
        if (partido2[i]=='1') unos++;
        else ceros++;
    }

    if (unos==ceros){
        for(unsigned int c=0;c<partido.length();c++){
            partido=intercambio(partido, c);
        }
    }

    else if(ceros>unos){
        for (unsigned int c=1;c<partido.length();c+=2){
            partido=intercambio(partido, c);
        }
    }

    else{
        for (unsigned int c=2;c<partido.length();c+=3){
            partido=intercambio(partido, c);
        }
    }
    return partido;
}

string cambio_bit2(string bi){
    unsigned int i;
    string bi2, copia;
    copia=bi[bi.length()-1];
    for (i=0;i<bi.length();i++){
        bi2+=copia;
        copia=bi[i];
    }
    return bi2;
}
