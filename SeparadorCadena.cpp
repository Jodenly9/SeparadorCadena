#include <iostream>
#include <string>

using namespace std;

/*Obtiene una cadena de texto y un separador de campos, ingresados por el usuario, y la separa uno abajo de otro.
 Precondici�n: @cadena es una cadena de caracteres válida y no es nullptr.
                @separadorCampos es el carácter que se utilizará para separar los campos en la cadena.
 Postcondicion: Devuelve una matriz formada de la siguiente manera
    		- La cantidad de filas es igual a la cantidad de campos + 1
  			- Los campos estan dentro de @cadena separados por el caracter @separadorCampos.
  			  ejemplo: La cadena con el valor "julio,agosto,septiembre,octubre" tiene 4 campos
  			- La ultima fila tiene un caracter \0
 Ejemplo:
 Si invoco Dividir("julio,agosto,septiembre,octubre", ',') entonces la matriz resultante sería:
       j    u    l    i    o    \0
       a    g    o    s    t    o    \0
       s    e    p    t    i    e    m    b    r    e    \0
       o    c    t    u    b    r    e    \0
       \0
 */
char** Dividir(char* cadena, char separadorCampos);
int obtenerLongCadena(const char* cadena);

int SeparadorCadena(){
    string cadena;
    char separadorCampos;

    cout<< "Ingrese la cadena de texto: ";
    getline(cin, cadena);

    cout<< "Ingrese el caracter separador de campos (Ejemplos: ,(coma),  -(guion), " "(espacio)): ";
    cin>> separadorCampos;

    char* cadenaChar= new char[cadena.length() + 1];
    strcpy(cadenaChar, cadena.c_str());

    char** matriz= Dividir(cadenaChar, separadorCampos);
    
    for(int i = 0; matriz[i] != nullptr; i++){
        cout<< matriz[i] << endl;
        delete[] matriz[i];
    }
    delete[] matriz;

    delete[] cadenaChar;
    return 0;
}

int obtenerLongCadena(const char* cadena){
    int longitud= 0;
    while(cadena[longitud] != '\0'){
        longitud++;
    }
    return longitud;
}
char** Dividir(char* cadena, char separadorCampos){
    int longitudCadena= obtenerLongCadena(cadena);
    int numeroFilas= 0;
    int contCampos= 0;

    for (int i = 0; i < longitudCadena; i++){
        if (cadena[i] == separadorCampos){
            contCampos++;
        }
    }
    numeroFilas= contCampos + 2;
    char** matriz= new char*[numeroFilas];

    int filaActual= 0;
    int inicioCampo= 0;
    for(int i = 0; i < longitudCadena; i++){
        if(cadena[i] == separadorCampos){
            int longCampo= i - inicioCampo;

            matriz[filaActual]= new char[longCampo + 1];
            for (int j = 0; j < longCampo; j++){
                matriz[filaActual][j]= cadena[inicioCampo + j];
            }
            matriz[filaActual][longCampo] = '\0';

            filaActual++;
            inicioCampo= i + 1;
        }
    }
    matriz[filaActual]= new char[1];
    matriz[filaActual][0]= '\0';

    return matriz;
}