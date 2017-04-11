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

long double funcion_simplifica (int a, int b){
	int n=a;
	int k=b;

	int nf = a-b;
	long double numerador=1;
	for(int i=a;i>nf;i--)
	{
		//cout<<"valores de i  :   "<<i<<endl;
		numerador = numerador * i;
	}
	return numerador;
}

long double funcion_probabilidad(int a, int b){

	long double probabilidad = funcion_simplifica(a,b) / factorial(b);
	//cout<<"este es la probabilidad:"<<probabilidad<<endl;
	return probabilidad;
}

long double probabilidad_total(int a,int b){
	int m=a-b;
	long double p_total = funcion_probabilidad(a,b) * pow(0.35,8) * pow(0.65,m);
	//cout<<"ESte es p_total :"<<p_total<<endl;
	return p_total; 
}

void archivo()
{
	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("ficheroTexto.txt");

	ficheroSalida << "Ejerciciio 01:"<<endl;
	int a1=40;
	int b1=8;

	int a2=20;
	int b2=12;

	int a3=30;
	int b3=11;

	int a4=38;
	int b4=9;

	int a5=51;
	int b5=13;
	
	ficheroSalida << "====================================="<<endl;
	ficheroSalida << "Ejercicio 1:   "<<probabilidad_total(a1,b1)<<endl;
	ficheroSalida << "Ejercicio 2:   "<<probabilidad_total(a2,b2)<<endl;
	ficheroSalida << "Ejercicio 3:   "<<probabilidad_total(a3,b3)<<endl;
	ficheroSalida << "Ejercicio 4:   "<<probabilidad_total(a4,b4)<<endl;
	ficheroSalida << "Ejercicio 5:   "<<probabilidad_total(a5,b5)<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}

int main () {
  
  int a1=40;
  int b1=8;

  int a2=20;
  int b2=12;

  int a3=30;
  int b3=11;

  int a4=38;
  int b4=9;

  int a5=51;
  int b5=13;

  //cout<<funcion_simplifica(a,b)<<endl;
  //cout<<funcion_probabilidad(a,b)<<endl;
  cout<<probabilidad_total(a1,b1)<<endl;
  cout<<probabilidad_total(a2,b2)<<endl;
  cout<<probabilidad_total(a3,b3)<<endl;
  cout<<probabilidad_total(a4,b4)<<endl;
  cout<<probabilidad_total(a5,b5)<<endl;
  archivo();
  return(0);
}

// g++ bio04.cpp -p b
// ./b