#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int c_adenina(string a){
    float Adenina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='A')
            Adenina+=1;
    }
    return Adenina;
}

int c_timina(string a){
    float Timina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='T')
            Timina+=1;
    }
    return Timina;
}

int c_citosina(string a){
    float Citosina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='C')
            Citosina+=1;
    }
    return Citosina;
}

int c_guanina(string a){
    float Guanina=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='G')
            Guanina+=1;
    }
    return Guanina;
}

int c_purina(string a){
    float Purina=floor((c_adenina(a)+c_guanina(a))/2.0);
    return Purina;
}

int c_piriminida(string a){
    float Pirimidina=floor((c_citosina(a)+c_timina(a))/2.0);
    return Pirimidina;
}

//Purinas
float factorial_pu (int i, string a) {
    int PU = c_purina(a);
    int PI = c_piriminida(a);
    float tam=PU+PI;
    
    float result = 1.0;
    while (i > 0) {
        result = result*(PI/tam);
        i = i-1;
        PI = PI-1;
        tam = tam-1;
    } 
    return result*(PU/(tam-i));
}
//Purinas
float valor_esperado_pu(string a){
    int PU = c_purina(a);
    int PI = c_piriminida(a);
   
    float tam=PU+PI;
    float res1 = PU/tam;
    float res=0.0;

    for(int i=1;i<PI+1;++i){
        res = res + ((i+1) * factorial_pu(i,a));
    }
    return res1 + res;
}

//Pirimidina
float factorial_pi(int i, string a) {
    int PU = c_purina(a);
    int PI = c_piriminida(a);
    float tam=PU+PI;
    
    float result = 1.0;
    while (i > 0) {
        result = result*(PU/tam);
        i = i-1;
        PI = PU-1;
        tam = tam-1;
    } 
    return result*(PI/(tam-i));
}

//Pirimidina
float valor_esperado_pi(string a){
    
    int PU = c_purina(a);
    int PI = c_piriminida(a);
    float tam=PU+PI;
    float res1 = PI/tam;

    float res=0.0;

    for(int i=1;i<PU+1;++i){
        res = res + ((i+1) * factorial_pu(i,a));
    }
    return res1 + res;
}


void archivo()
{
    //LEER en ARCHIVO:
    ifstream ficheroEntrada01;
    string cadena01;

    ficheroEntrada01.open ("practica_06B.txt");
    cout<<"VALOR ESPERADO"<<valor_esperado_pu(cadena01)<<endl;
    getline(ficheroEntrada01, cadena01);
    ficheroEntrada01.close();
    cout << "ADN es: " << cadena01 << endl;
    cout<<"VALOR ESPERADO"<<valor_esperado_pu(cadena01)<<endl;
    cout<<"VALOR ESPERADO"<<valor_esperado_pi(cadena01)<<endl;
	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("JMacetas_Practica06_C.txt");
	ficheroSalida << "Ejerciciio 6-C:"<<endl;
	ficheroSalida << "====================================="<<endl;
    ficheroSalida << "Cuántos nucleótidos son retirados de la cadena de ADN hasta obtener una purina:    " <<valor_esperado_pu(cadena01)<<endl;
    ficheroSalida << "Cuántos nucleótidos son retirados de la cadena de ADN hasta obtener una pirimidina:    " <<valor_esperado_pi(cadena01)<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}


int main () {
    archivo();
    return(0);
}

// g++ bio05.cpp -p b
// ./b
