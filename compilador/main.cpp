#include "compilador.h"

string fuente, resto;
vector <string> lineas, reservadas,operadores,ids,numeros;
int linesN, nReservadas, found;
bool flt = false;

int main(int argc, char** argv) {
    //*****Proceso de scaning******
	compilador* c1 = new compilador();
    c1->setCompilador(c1);
    cout<<"*********"<<endl;
	linesN = c1->getNlineas();
	c1->getLineas(lineas);
	for(int i = 0; i<linesN; i++){
		cout<<lineas[i]<<endl;
	}
	//*****Proceso de generacion de tokens*****
	for(int i = 0; i<lineas.size();i++){
		resto = c1->getOperadores(lineas[i]);
	    cout<<resto<<endl;
	    c1->crearToken(resto,c1,reservadas,operadores,numeros,ids,flt);
	    c1->generate(lineas[i]);
	    c1->showlProp();
	    c1->clearVectors();
	}
	
	c1->emit();

	return 0;
}




