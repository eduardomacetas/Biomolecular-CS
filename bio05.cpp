#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//Distribucion Geometrica:
float distri_geo(int x, float a){
	// a = p ... q = 1-p
	float q = (1.0 - a);
	float pro = pow(q,x-1)*a;
	return pro;
}

// Probabilidad de C-G-A-T que son dados
float p_C = 19/100.0;
float p_G = 31/100.0;
float p_A = 37/100.0;
float p_T = 13/100.0;
float Purina = p_A + p_G; // Probabilidad de una PURINA = A+G
float Pirimidina = p_C + p_T; // Probabilidad de una Pirimidina = C+T

void archivo()
{
	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("JMacetas_Practica05_A.txt");

	ficheroSalida << "Ejerciciio 5-A:"<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Purina en el tercero intento    :   "<<distri_geo(3,Purina)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Purina en el quinto intento     :   "<<distri_geo(5,Purina)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Purina en el séptimo intento    :   "<<distri_geo(7,Purina)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Purina en el noveno intento     :   "<<distri_geo(9,Purina)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Pirimidina en el cuarto intento :   "<<distri_geo(4,Pirimidina)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Pirimidina en el sexto intento  :   "<<distri_geo(6,Pirimidina)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Pirimidina en el octavo intento :   "<<distri_geo(8,Pirimidina)<<endl;
	ficheroSalida << "Probabilidad de seleccionar una Pirimidina en el décimo intento :   "<<distri_geo(10,Pirimidina)<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}


int main () {

  int x=6;
  float er=0.05;
  cout<<"====Caso de PRUEBA:====="<<endl;
  cout<<distri_geo(x,er)<<endl;
  cout<<"========="<<endl;
  archivo();
  
  return(0);
}

// g++ bio05.cpp -p a
// ./a