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
	long double p_total = funcion_probabilidad(a,b) * pow(0.52,8) * pow(0.48,m);
	//cout<<"ESte es p_total :"<<p_total<<endl;
	return p_total; 
}

long double probabilidad_total_p(int a,int b){
	int m=a-b;
	long double p_total = funcion_probabilidad(a,b) * pow(0.48,8) * pow(0.52,m);
	//cout<<"ESte es p_total :"<<p_total<<endl;
	return p_total; 
}


void promedios_01()
{
	ifstream ficheroEntrada01;

    string cadena01;

    ficheroEntrada01.open ("practica_04_B.txt");
    getline(ficheroEntrada01, cadena01);
    ficheroEntrada01.close();
    cout << "ADN es: " << cadena01 << endl;
    
    string ADN01=cadena01;
	float Adenina=0;
	float Timina=0;
	float Citosina=0;
	float Guanina=0;

	for(int i=0;i<ADN01.size();i++){
		
		if(ADN01[i]=='A'){
			Adenina+=1;	
		}
		if(ADN01[i]=='T'){
			Timina+=1;
		}
		if(ADN01[i]=='C'){
			Citosina+=1;
			
		}
		if(ADN01[i]=='G'){
			Guanina+=1;
		}
	}

	float p_Adenina = (Adenina/ADN01.size());
	float p_Timina = (Timina/ADN01.size());
	float p_Citosina = (Citosina/ADN01.size());
	float p_Guanina = (Guanina/ADN01.size());

    float p_Purina = p_Adenina+p_Guanina;
    float p_Piriminida = p_Citosina + p_Timina;

    int a1=10;
    int b1=5;
    int a2=15;
    int b2=7;
    int a3=13;
    int b3=6;
    int a4=12;
    int b4=3;
    

    


    ofstream ficheroSalida;
    ficheroSalida.open ("JMacetas_practica_03A.txt");    
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida << "Ejercicio 1:   "<<probabilidad_total(a1,b1)<<endl;
    ficheroSalida << "Ejercicio 2:   "<<probabilidad_total(a2,b2)<<endl;
    ficheroSalida << "Ejercicio 3:   "<<probabilidad_total(a3,b3)<<endl;
    ficheroSalida << "Ejercicio 4:   "<<probabilidad_total(a4,b4)<<endl;
    //ficheroSalida<<"PROMEDIO de Adenina :"<<p_Adenina<<endl;
    //ficheroSalida<<"PROMEDIO de Timina :"<<p_Timina<<endl;
    //ficheroSalida<<"PROMEDIO de Citosina :"<<p_Citosina<<endl;
    //ficheroSalida<<"PROMEDIO de Guanina :"<<p_Guanina<<endl;
    //ficheroSalida<<"PROMEDIO de Purina :"<<p_Purina<<endl;
    //ficheroSalida<<"PROMEDIO de Pirimidina :"<<p_Piriminida<<endl;

    ficheroSalida<<"========================================="<<endl;
    ficheroSalida.close();
}

int main(){
    promedios_01();
    return 0;
}
