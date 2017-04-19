#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

long double factorial (int i) {
  int result = 1;
  while (i > 0) {
    result = result * i;
    i = i-1;
  }
  return result;
}

float p_adenina(string a){
    float Adenina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='A')
            Adenina+=1;
    }
    return Adenina;
}

float p_timina(string a){
    float Timina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='T')
            Timina+=1;
    }
    return Timina;
}

float p_citosina(string a){
    float Citosina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='C')
            Citosina+=1;
    }
    return Citosina;
}

float p_guanina(string a){
    float Guanina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='G')
            Guanina+=1;
    }
    return Guanina;
}

float p_purina(string a){
    float Purina=p_adenina(a)+p_guanina(a);
    return Purina;
}

float p_piriminida(string a){
    float Pirimidina=p_citosina(a)+p_timina(a);
    return Pirimidina;
}

float com_purina(string s){
    double purina1 = p_purina(s)/s.size();
    double purina2 = (p_piriminida(s)/s.size() )* (p_purina(s)/(s.size()-1));
    double res = purina1+(2.0*purina2);
    return purina1;
}

float com_piriminida(string s){
    double piriminida1 = p_piriminida(s)/s.size();
    double piriminida2 = (p_purina(s)/s.size() )* (p_piriminida(s)/(s.size()-1));
    //cout<<"P1   "<<piriminida1<<endl;
    //cout<<"P2   "<<piriminida2<<endl;
    double res = piriminida1+(2.0*piriminida2);
    return res;
}



void archivo()
{
    //LEER en ARCHIVO:
    ifstream ficheroEntrada01;
    string cadena01;

    ficheroEntrada01.open ("practica_06B.txt");
    
    getline(ficheroEntrada01, cadena01);
    ficheroEntrada01.close();
    cout << "ADN es: " << cadena01 << endl;

    
    //cout<<com_purina(cadena01)<<endl;
    //cout<<com_piriminida(cadena01)<<endl;


	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("JMacetas_Practica06_C.txt");
	ficheroSalida << "Ejerciciio 6-C:"<<endl;
	ficheroSalida << "====================================="<<endl;
    ficheroSalida << "Aproximadamente cuántos nucleótidos son retirados de la cadena de ADN hasta obtener una purina: " <<com_purina(cadena01)<<endl;
    ficheroSalida << "Aproximadamente cuántos nucleótidos son retirados de la cadena de ADN hasta obtener una pirimidina: "<<com_piriminida(cadena01)<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}


int main () {
    archivo();
    return(0);
}

// g++ bio05.cpp -p b
// ./b
