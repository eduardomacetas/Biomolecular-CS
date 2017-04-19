#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//Factorial:
long double factorial (int i) {
  int result = 1;
  while (i > 0) {
    result = result * i;
    i = i-1;
  }
  return result;
}


// Probabilidad de C-G-A-T que son dados
float p_C = 0.35;
float p_G = 0.35;
float p_A = 0.15;
float p_T = 0.15;

float D_Multinomial(int n, int a, int t, int g, int c){
    double r = factorial(n)/(factorial(a)* factorial(t)* factorial(g)* factorial(c));
    double u = pow(p_A,a) * pow(p_T,t) * pow(p_G,g) * pow(p_C,c);
    double resul = r*u;
    return resul;
}

void archivo()
{
	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("JMacetas_Practica06_A.txt");

	ficheroSalida << "Ejerciciio 6-A:"<<endl;
	ficheroSalida << "====================================="<<endl;
    ficheroSalida << "Calcule la probabilidad de que haya 2C, 3G, 2A y 1T: " << D_Multinomial(8,2,1,3,2)<<endl;
    ficheroSalida << "Calcule la probabilidad de que haya 3C, 2G, 1A y 2T:" << D_Multinomial(8,1,2,2,3)<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}


int main () {

    archivo();
    cout<< D_Multinomial(8,2,1,3,2)<<endl;
    cout<< D_Multinomial(8,1,2,2,3)<<endl;
    return(0);
}

// g++ bio06.cpp -p a
// ./a

