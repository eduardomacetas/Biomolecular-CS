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
    for(int i=0;i<a.size()+2;i++){
        if(a[i]=='A')
            Adenina+=1;
    }
    return Adenina;
    
}

float p_timina(string a){
    float Timina=0;
    for(int i=0;i<a.size()+2;i++){
        if(a[i]=='T')
            Timina+=1;
    }
    return Timina;
}

float p_citosina(string a){
    float Citosina=0;
    for(int i=0;i<a.size()+2;i++){
        if(a[i]=='C')
            Citosina+=1;
    }
    return Citosina;
}

float p_guanina(string a){
    float Guanina=0;
    for(int i=0;i<a.size()+2;i++){
        if(a[i]=='G')
            Guanina+=1;
    }
    
    return Guanina;
}

float D_Multinomial(int n, int a, int t, int g, int c, string s){
    int tam = s.size()+1;
    int r = factorial(n)/(factorial(a)* factorial(t)* factorial(g)* factorial(c));
    float u = pow(p_adenina(s)/tam,a) * pow(p_timina(s)/tam,t) * pow(p_guanina(s)/tam,g) * pow(p_citosina(s)/tam,c);
    float resul = (r*1.0)*u;
    return resul;
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
    //////////////////// n-a-t-g-c
	cout<< D_Multinomial(13,2,4,4,3,cadena01)<<endl;
    cout<< D_Multinomial(10,2,3,3,2,cadena01)<<endl;
    cout<< D_Multinomial(8,3,2,2,1,cadena01)<<endl;
    cout<< D_Multinomial(7,3,1,1,2,cadena01)<<endl;

	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("JMacetas_Practica06_B.txt");
	ficheroSalida << "Ejerciciio 6-B:"<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida << "Calcule la probabilidad de que haya 3C, 4G, 2A y 4T: "<<D_Multinomial(13,2,4,4,3,cadena01)<<endl;
    ficheroSalida << "Calcule la probabilidad de que haya 2C, 3G, 2A y 3T: "<<D_Multinomial(10,2,3,3,2,cadena01)<<endl;
    ficheroSalida << "Calcule la probabilidad de que haya 1C, 2G, 3A y 2T: "<<D_Multinomial(8,3,2,2,1,cadena01)<<endl;
    ficheroSalida << "Calcule la probabilidad de que haya 2C, 1G, 3A y 1T: "<<D_Multinomial(7,3,1,1,2,cadena01)<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}


int main () {
    archivo();
    return(0);
}

// g++ bio05.cpp -p b
// ./b
