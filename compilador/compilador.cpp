
#include"compilador.h"

//Constructor 
compilador::compilador(){
	
	this->operador.push_back("itera");
	this->operador.push_back("bucle");
	this->operador.push_back("asigna");
	this->operador.push_back("multiplica");
	this->operador.push_back("divide");
	this->operador.push_back("suma");
	this->operador.push_back("resta");
	this->operador.push_back("condicion");
	this->operador.push_back("fin");
	this->operador.push_back("funcion");
	this->operador.push_back("llama");
	this->operador.push_back("FIN");
	
	this->alpha.push_back("a");
	this->alpha.push_back("b");
	this->alpha.push_back("c");
	this->alpha.push_back("d");
	this->alpha.push_back("e");
	this->alpha.push_back("f");
	this->alpha.push_back("g");
	this->alpha.push_back("h");
	this->alpha.push_back("i");
	this->alpha.push_back("j");
	this->alpha.push_back("k");
	this->alpha.push_back("l");
	this->alpha.push_back("m");
	this->alpha.push_back("n");
	this->alpha.push_back("o");
	this->alpha.push_back("p");
	this->alpha.push_back("q");
	this->alpha.push_back("r");
	this->alpha.push_back("t");
	this->alpha.push_back("u");
	this->alpha.push_back("v");
	this->alpha.push_back("w");
	this->alpha.push_back("x");
	this->alpha.push_back("y");
	this->alpha.push_back("z");
	
	this->alpha.push_back("A");
	this->alpha.push_back("B");
	this->alpha.push_back("C");
	this->alpha.push_back("D");
	this->alpha.push_back("E");
	this->alpha.push_back("F");
	this->alpha.push_back("G");
	this->alpha.push_back("H");
	this->alpha.push_back("I");
	this->alpha.push_back("j");
	this->alpha.push_back("K");
	this->alpha.push_back("L");
	this->alpha.push_back("M");
	this->alpha.push_back("N");
	this->alpha.push_back("O");
	this->alpha.push_back("P");
	this->alpha.push_back("Q");
	this->alpha.push_back("R");
	this->alpha.push_back("S");
	this->alpha.push_back("T");
	this->alpha.push_back("U");
	this->alpha.push_back("V");
	this->alpha.push_back("W");
	this->alpha.push_back("X");
	this->alpha.push_back("Y");
	this->alpha.push_back("Z");
	
	this->numeros.push_back("0");
	this->numeros.push_back("1");
	this->numeros.push_back("2");
	this->numeros.push_back("3");
	this->numeros.push_back("4");
	this->numeros.push_back("5");
	this->numeros.push_back("6");
	this->numeros.push_back("7");
	this->numeros.push_back("8");
	this->numeros.push_back("9");
}

int compilador::getNreservadas(){
	return this->reservadas.size();
}

void compilador::setCompilador(compilador *c){
	string fuente;
	c->setPropiedades();
	fuente = c->getFuente();
	c->setLineas(fuente);
	c->showLineas();
	this->f_ids.clear();
	this->f_numeros.clear();
	this->f_operadores.clear();
	this->f_reservadas.clear();
}

string compilador::getFuente(){
	string f1;
	ifstream archivo;
	archivo.open("archivo_fuente.txt",ios::in);
	if (archivo.is_open()){
		while(getline(archivo,f1)){
			this->fuente += f1;
		}
	return this->fuente;
    archivo.close();
  }
}

void compilador::setLineas(string texto){
	string linea;
	size_t found;
	for(int i = 0; i<texto.length();i++){
	   found = texto.find(";");
	  if(found != string::npos){
		linea = texto.substr(0,found);
		this->lineas.push_back(linea);
		this->nlineas++;
	    }
	    linea = texto.erase(0,found+1);
	}
}

void compilador::showLineas(){
	int len = this->lineas.size();
	for(int i = 0; i<len;i++){
		cout<<this->lineas[i]<<endl;
	}
}

void compilador::showReservadas(){
	int len = this->reservadas.size();
	for(int i = 0; i<len;i++){
		cout<<this->reservadas[i]<<endl;
	}
}

int compilador::getNlineas(){
	return this->nlineas;
}

void compilador::getLineas(vector<string> &lineas){
	for(int i = 0; i<this->nlineas;i++){
		lineas.push_back(this->lineas[i]);
	}
}



void compilador::setPropiedades(){
	this->lpropiedades.insert(clase("reservada",0));
	this->lpropiedades.insert(clase("identificador",0));
	this->lpropiedades.insert(clase("numero",0));
	this->lpropiedades.insert(clase("operador",0));
}

void compilador::getReservadas(vector <string> &reser){
	for(int i = 0; i<this->f_reservadas.size();i++){
		reser.push_back(this->f_reservadas[i]);
	}
}

void compilador::getOperadores(vector <string> &operador){
	for(int i = 0; i<this->f_operadores.size();i++){
		operador.push_back(this->f_operadores[i]);
	}
}

void compilador::getIdentificadores(vector <string> &id){
	for(int i = 0; i<this->f_ids.size();i++){
		id.push_back(this->f_ids[i]);
	}
}

void compilador::getNumeros(vector <string> &numeros){
	for(int i = 0; i<this->f_numeros.size();i++){
		numeros.push_back(this->f_numeros[i]);
	}
}

string compilador::setReservadas(string linea){
	int fin, ini;
	size_t found;
	string id;
	for(int i = 0; i<this->reservadas.size();i++){
		found = linea.find(this->reservadas[i]);
		if(found != string::npos){
			//cout<<"Palabra reservada "<<this->reservadas[i]<< " encontrada: "<<found<<endl;
			this->lpropiedades["reservada"]++;
			id = this->reservadas[i];
			this->f_reservadas.push_back(id);
			fin = id.size();
			ini = found;
			linea.erase(found,fin);
		}
 }
	
	return linea;
}


string compilador::esReservada(string linea){
	size_t found;
	string id;
	bool flg = false;
	for(int i = 0; i<this->reservadas.size();i++){
		found = linea.find(this->reservadas[i]);
		if(found != string::npos){
			//cout<<"Palabra reservada "<<this->reservadas[i]<< " encontrada: "<<found<<endl;
			//this->lpropiedades["reservada"]++;
			id = this->reservadas[i];
			flg = true;
		}
	}
	if(flg){
		return id;
	}
	else{
		return "NULL";
	}	
}

string compilador::setIdentificadores(string linea){
	string reservada, operador, id;
	reservada = this->esReservada(linea);
	operador = this->esOperador(linea);
	if(reservada == "NULL" && operador == "NULL"){
		id = this->getTexto(linea);
		this->lpropiedades["identificador"]++;
		this->f_ids.push_back(id);
		return id;
	}
	else{
		return "NULL";
	}
}


string compilador::setOperadores(string linea){
	
	int fin, ini;
	size_t found;
	string id;
	for(int i = 0; i<this->operador.size();i++){
		found = linea.find(this->operador[i]);
		if(found != string::npos){
			this->lpropiedades["operador"]++;
			id = this->operador[i];
			this->f_operadores.push_back(id);
			fin = id.size();
			ini = found;
			linea.erase(found,fin);
		}
	}
	
	return linea;
}

string compilador::esOperador(string linea){
	size_t found;
	string id;
	bool flg = false;
	for(int i = 0; i<this->operador.size();i++){
		found = linea.find(this->operador[i]);
		if(found != string::npos){
			//cout<<"Palabra reservada "<<this->reservadas[i]<< " encontrada: "<<found<<endl;
			//this->lpropiedades["operador"]++;
			id = this->operador[i];
			flg = true;
		}
	}
	if(flg){
		return id;
	}
	else{
		return "NULL";
	}	
}

string compilador::setNumeros(string linea, bool &flt){
	int len, j;
	char numeroc[20];
	string numero;
	char strc[linea.size()];
	strcpy(strc,linea.c_str());
	len = sizeof(strc)/sizeof(char);
	for(int i = 0;i<len;i++){
		if(isdigit(strc[i])){
			numeroc[j]=strc[i];
			j++;
			this->lpropiedades["numero"]++;
		}
		else if(strc[i] == '.'){
			flt = true;
			numeroc[j]=strc[i];
			j++;
		}
		
		else if(strc[i] == ','){
			size_t found;
			found = linea.find(',');
			linea = linea.erase(0,found+1);
			len = linea.size();
			linea.resize(len-1);
			this->f_numeros.push_back(linea);
			this->lpropiedades["numero"]++;
			break;
		}
	}
	numero = numeroc;
	this->f_numeros.push_back(numero);
	return numero;
}

string compilador::setNumeros(string linea){
	int len, j;
	cout<<linea<<"*"<<endl;
	char numeroc[20];
	string numero;
	char strc[linea.size()];
	strcpy(strc,linea.c_str());
	len = sizeof(strc)/sizeof(char);
	for(int i = 0;i<len;i++){
		if(isdigit(strc[i])){
			numeroc[j]=strc[i];
			j++;
			this->lpropiedades["numero"]++;
		}
	}
	numero = numeroc;
	this->f_numeros.push_back(numero);
	return numero;
}

string compilador::getTexto(string linea){
	
	int  len, j  = 0;
	string id;
	char strc[linea.size()+1];
	strcpy(strc,linea.c_str());
	len = sizeof(strc)/sizeof(char);
	for(int i = 0;i<len;i++){
		if(isalpha(strc[i])){
			id.push_back(strc[i]);
		}
	}
	return id;
}

void compilador::showlProp(){
	map<string,int>::iterator p = this->lpropiedades.begin();
	while(p != this->lpropiedades.end()){
	     cout<<setw(15)<<p->first<<setw(15)<<p->second<<endl;
	     p++;
    }
}

void compilador::crearToken(string linea,compilador *c1, vector <string> &reservadas, vector <string> &operadores,
                            vector <string> &numeros,vector <string> &ids, bool &flt )
		{
	   string texto;
	   texto = c1->getTexto(linea);
	   //cout<<texto<<endl;
	   texto = c1->setReservadas(texto);
	   //cout<<texto<<endl;
	   c1->getReservadas(reservadas);
	   texto = c1->setOperadores(texto);
	   //cout<<texto<<endl;
	   c1->getOperadores(operadores);
	   //cout<<operadores.size()<<endl;
	   texto = c1->setIdentificadores(texto);
	   //cout<<texto<<"*"<<endl;
	   c1->getIdentificadores(ids);
	   //cout<<ids.size()<<endl;
	   //cout<<numeros[0]<<endl;  
	   c1->setNumeros(linea,flt);
	   c1->getNumeros(numeros);  	
	   }
	   
void compilador::emit(){
	ofstream archivo;
	archivo.open("archivo_objeto.txt",ios::out);
	if(archivo.fail()){
		cout<<"Error abriendo el archivo";
		exit(1);
	}
	int len = this->lineas_objeto.size();
	for(int i = 0; i<len;i++){
		archivo<<this->lineas_objeto[i];
		archivo<<endl;
	}
	
}

void compilador::generate(string &expresion){
	this->code = expresion;
	string caso = this->f_operadores[0];
	string codigo;
    string iterador;
	if(caso =="asigna"){
		codigo.append(this->f_ids[0]);
		codigo.append("=");
		codigo.append(this->f_numeros[0]);
		codigo.append(";");
		this->lineas_objeto.push_back(codigo);
	}
	else if(caso=="multiplica"){
		codigo.append(this->f_ids[0]);
		codigo.append("=");
		if(this->f_ids.size()<=1){
			codigo.append(this->oper[0]);
			codigo.append("*");
			codigo.append(this->oper[1]);
			codigo.append(";");
			this->lineas_objeto.push_back(codigo);
		}
	}
	else if(caso=="suma"){
		codigo.append(this->f_ids[0]);
		codigo.append("=");
		if(this->f_ids.size()<=1){
			codigo.append(this->oper[0]);
			codigo.append("+");
			codigo.append(this->oper[1]);
			codigo.append(";");
			this->lineas_objeto.push_back(codigo);
		}
	}
	
	else if(caso=="divide"){
		codigo.append(this->f_ids[0]);
		codigo.append("=");
		if(this->f_ids.size()<=1){
			codigo.append(this->oper[0]);
			codigo.append("/");
			codigo.append(this->oper[1]);
			codigo.append(";");
			this->lineas_objeto.push_back(codigo);
		}
	}
	
	else if(caso=="resta"){
		codigo.append(this->f_ids[0]);
		codigo.append("=");
		if(this->f_ids.size()<=1){
			codigo.append(this->oper[0]);
			codigo.append("-");
			codigo.append(this->oper[1]);
			codigo.append(";");
			this->lineas_objeto.push_back(codigo);
		}
	}
	else if(caso=="bucle"){
		string numb = this->createLine(this->L_objeto);
		codigo.append(numb);
		codigo.append(":");
		this->lineas_objeto.push_back(codigo);
		codigo.clear();
		numb.clear();
		numb = this->createVar(this->L_var);
		codigo.append(numb);
		codigo.append("=");
		codigo.append(this->oper[1]);
		codigo.append(";");
		this->lineas_objeto.push_back(codigo);
		codigo.clear();
		codigo.append("if(");
		codigo.append(numb);
		codigo.append(")");
		codigo.append("goto");
		numb = this->createLine((this->L_objeto)+1);
		codigo.append(numb);
		codigo.append(";");
		this->lineas_objeto.push_back(codigo);
		numb = this->createLine((this->L_objeto)+2);
		codigo.clear();
		codigo.append("goto");
		codigo.append(numb);
		codigo.append(";");
		this->lineas_objeto.push_back(codigo);
		numb = this->createLine((this->L_objeto)+1);
		codigo.clear();
		codigo.append(numb);
		codigo.append(":");
		this->lineas_objeto.push_back(codigo);
	}
	else if(caso=="itera"){
		string numb;
		codigo.clear();
		codigo.append(this->oper[0]);
		codigo.append(";");
		this->lineas_objeto.push_back(codigo);
		codigo.clear();
		codigo.append("goto");
	    numb = this->createLine(this->L_objeto);
	    codigo.append(numb);
	    codigo.append(";");
	    this->lineas_objeto.push_back(codigo);
	    codigo.clear();
	    numb = this->createLine((this->L_objeto)+2);
	    codigo.append(numb);
	    codigo.append(":");
	    this->lineas_objeto.push_back(codigo);
	    this->L_objeto += 3;
	}
	else if(caso=="condicion"){
		string numb;
		numb = this->createVar(this->L_var);
		codigo.clear();
		codigo.append(numb);
		codigo.append("=");
		codigo.append(this->oper[0]);
		codigo.append(";");
		this->lineas_objeto.push_back(codigo);
		codigo.clear();
		codigo.append("if(");
		codigo.append(numb);
		codigo.append(")");
		codigo.append("goto");
		numb = this->createLine((this->L_objeto));
		codigo.append(numb);
		codigo.append(";");
		this->lineas_objeto.push_back(codigo);
		numb = this->createLine((this->L_objeto)+1);
		codigo.clear();
		codigo.append("goto");
		codigo.append(numb);
		codigo.append(";");
		this->lineas_objeto.push_back(codigo);
		numb = this->createLine(this->L_objeto);
		codigo.clear();
		codigo.append(numb);
		codigo.append(":");
		this->lineas_objeto.push_back(codigo);
	}
	else if(caso=="fin"){
		string numb;
		numb = this->createLine((this->L_objeto)+1);
		codigo.clear();
		codigo.append(numb);
		codigo.append(":");
		this->lineas_objeto.push_back(codigo);
	}
	else if(caso=="FIN"){
		string numb;
		numb = this->createRefLine(this->L_ref);
		codigo.append("goto ");
	    codigo.append(numb);
	    codigo.append(":");
	    this->lineas_objeto.push_back(codigo);
	    codigo.clear();
	    codigo.append("fin:");
	    this->lineas_objeto.push_back(codigo);
	}
	else if(caso=="funcion"){
		string numb, funcion;
		funcion = this->code;
		funcion = funcion.erase(0,8);
		this->nombres_f.push_back(funcion);
		numb = this->createLine((this->L_objeto));
		codigo.append(funcion);
	    codigo.append(":");
	    this->funciones[funcion]=codigo;
	    this->lineas_objeto.push_back(codigo);
	    codigo.clear();
	    //cout<<this->funciones.find(funcion)->second<<endl;
	}
	
	else if(caso =="llama"){
		for(int i = 0; i<this->nombres_f.size();i++){
		  if(this->f_ids[0]==this->nombres_f[i]){
		  	string numb;
			codigo.clear();
			codigo.append("call ");
			codigo.append(this->funciones.find(this->nombres_f[i])->second);
			this->lineas_objeto.push_back(codigo);
			codigo.clear();
			numb = this->createRefLine(this->L_ref);
	        codigo.append(numb);
	        codigo.append(":");
	        this->lineas_objeto.push_back(codigo);
		}
	  }
	}	
}

string compilador::createLine(int numero){
	ostringstream str1;
	str1.clear();
	str1.str("");
	string linea;
	str1<<numero;
	string numb = str1.str();
	linea.append("L");
	linea.append(numb);
	return linea;
}

string compilador::createVar(int numero){
	ostringstream str1;
	str1.clear();
	str1.str("");
	string linea;
	str1<<numero;
	string numb = str1.str();
	linea.append("VAR");
	linea.append(numb);
	this->L_var++;
	return linea;
}

string compilador::createRefLine(int numero){
	ostringstream str1;
	str1.clear();
	str1.str("");
	string linea;
	str1<<numero;
	string numb = str1.str();
	linea.append("L");
	linea.append("*");
	linea.append(numb);
	return linea;
}

string compilador::getOperadores(string linea){
	size_t found1, found2;
	string operador, resto;
	found1 = linea.find('(');
	found2 = linea.find(')');
	if(found1>0 && found1<50){
		resto = linea.substr(0,found1);
		linea.erase(found2);
	    operador = linea.substr(found1+1,found2);
	    found1 = operador.find(',');
	    found2 = operador.size();
	    this->oper.push_back(operador.substr(0,found1));
	    this->oper.push_back(operador.substr(found1+1,found2));
	    //cout<<resto<<endl;
	    return resto;
	}
	else{
		return linea;
	}
}

void compilador::clearVectors(){
	this->f_ids.clear();
	this->f_numeros.clear();
	this->f_operadores.clear();
	this->oper.clear();
	this->f_reservadas.clear();
}






