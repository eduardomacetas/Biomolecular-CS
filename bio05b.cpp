#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

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
        if(a[i]=='T')
            Citosina+=1;
    }
    return Citosina;
}

float p_guanina(string a){
    float Guanina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='T')
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

//Distribucion Geometrica:
float distri_geo(int x, float a){
	// a = p ... q = 1-p
	float q = (1.0 - a);
	float pro = pow(q,x-1)*a;
	return pro;
}


void archivo()
{
    //LEER en ARCHIVO:
    ifstream ficheroEntrada01;
    string cadena01;

    ficheroEntrada01.open ("practica_05_B.txt");
    
    getline(ficheroEntrada01, cadena01);
    ficheroEntrada01.close();
    cout << "ADN es: " << cadena01 << endl;

    float pu=p_purina(cadena01)/cadena01.size(); 
    cout<<"PURINA:"<<pu<<endl;
    float pi=p_piriminida(cadena01)/cadena01.size();
    cout<<"PIRIMINIDA"<<pi<<endl;

	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("JMacetas_Practica05_B.txt");
	ficheroSalida << "Ejerciciio 5-B:"<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Purina en el segundo intento        :   "<<distri_geo(2,pu)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Purina en el cuarto intento         :   "<<distri_geo(4,pu)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Pirimidina en el tercero intento    :   "<<distri_geo(3,pi)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Pirimidina en el quinto intento     :   "<<distri_geo(5,pi)<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}


int main () {
    archivo();
    return(0);
}

// g++ bio05.cpp -p b
// ./b