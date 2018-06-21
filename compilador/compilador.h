#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <utility>
#include <map>
#include <iomanip>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <map>
using namespace std;

typedef pair<string, int> clase;


class compilador{
	
	private:
		string fuente;
		vector <string> lineas;
		int nlineas, L_objeto;
		vector <string> reservadas;
		map <string,int> lpropiedades;
		vector <string> numeros,operador,alpha;
		//Este metodo se utiliza para crear las listas asociativas de los elmentos del token
		void setPropiedades();
		//Este metodo se encarga de identificar las lineas ingresadas en el archivo fuente
		void setLineas(string);
		vector <string> f_reservadas, f_operadores, f_ids, f_numeros,oper, lineas_objeto, nombres_f;
		int L_var=0;
		int L_ref=0;
		string code;
		map<string,string> funciones;
		
    public:
    	//El constructor inserta la gramatica a las propiedades del objeto instanciado
		compilador();
		~compilador(){} 
		//Funcion para establecer las propiedades del compilador, lineas y fuente
		void setCompilador(compilador*);
		//Obtiene la cantidad de palabras reservadas
		int getNreservadas();
		//Muestra las palabras reservadas
		void showReservadas();
		//Metodo utilizado para abrir y obtener la informacion del archivo fuente
		//Este metodo retorna un vector de caracteres
		string getFuente();
		//Este metodo se encarga de mostrar por consola las lineas encontradas en el archivo fuente
		void showLineas();
		//Este metodo devuelve la cantidad de lineas encontradas en el archivo fuente
		int getNlineas();
		//Este metodo se encarga de almacenar la informacion de las lineas del archivo fuente en un vector de 
		//Strings 
		void getLineas(vector <string>&);
		//Este metodo se encarga de almacenar la informacion de las palabras reservadas del lenguaje en un vector de 
		//Strings, almacena las palabras reservadas encontradas en 1 linea en el vector pasado como parametro
		void getReservadas(vector <string>&);
		//Este metodo se encarga de almacenar la informacion de los operadores del lenguaje en un vector de 
		//Strings, almacena los operadores encontradas en 1 linea en el vector pasado como parametro
		void getOperadores(vector <string>&);
		//Este metodo revisa si en el vector de caracteres pasado como parametro existen palabras reservadas, si es el caso
		//regresa la posicion inicial y final dentro del vector de caracteres en donde fue encontrada dicha palabra
		string esReservada(string);
		//Este metodo sobrecargado solo indica si existe una palabra reservada en un vector de caracteres
		string setReservadas(string);
		//Solo regresa el operador encontrado
		string esOperador(string);
		//Metodo que actualiza los operadores encontrados en el proceso de la creacion de los token
		string setOperadores(string);
		//Este metodo obtien todos los cracteres dentro del alfabeto {a-z} y {A-Z}
		string getTexto(string);
		//Recibe un vector de caracteres y regresa el identificador
		string setIdentificadores(string);
		//Este metodo se encarga de almacenar la informacion de los identificadores encontrados en un vector de 
		//Strings, almacena los identificadores encontrados en 1 linea en el vector pasado como parametro
		void getIdentificadores(vector <string>&);
		//Muestra las propiedades del token generadas a partir del analizis de una linea
		void showlProp();
		//Esto metodo regresa el numero encontrado dentro de un vector de caracteres 
		string setNumeros(string,bool&);
		string setNumeros(string);
		//Este metodo se encarga de almacenar la informacion de los numeros del lenguaje en un vector de 
		//Strings, almacena los numeros encontradas en 1 linea en el vector pasado como parametro
		void getNumeros(vector <string>&);
		//Este metodo crea y actualiza la informacion de los tokens generados, ademas de detectar si un numero es entero o flotante
		void crearToken(string,compilador*, vector<string>&, vector<string>&,vector<string>&,vector<string>&,bool&);
		//Este metodo se encarga de insertar el codigo en el archivo objeto
		void emit();
		//Este metodo recibe la informacion previamente analizada y genera el codigo intermedio
		void generate(string &);
		//Esta funcion revisa si los operadores involucrados en alguna posicion tiene el formato correcto
		string getOperadores(string);
		//Este metodo se utiliza para limpiar los vectores resultantes de la etapa de parseo
		void clearVectors();
		//Este metodo parsea los tokens generados en expresiones que seran recibidas por el metodo generate
		string createLine(int);
		//Metodo que crea las variables a utilizar en el archivo objeto
		string createVar(int);
		//Metodo que guarda la referencia a las lineas para realizar los branch (jumps)
		string createRefLine(int);
		
};
