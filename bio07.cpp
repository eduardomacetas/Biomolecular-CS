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
    return Pirimidina/a.size();
}

char last(string a){
    int tam=a.size()-1;
    return a[tam];
}

float markov_cont(string a, char x,char y){
    float count=0.0;
    char x1 = x;
    char y1 = y;
    char lt = last(a);
    for(int i=0;i<a.size();i++){
        if(a[i]==x1 && a[i+1]==y1){
            count+=1;
        }
    }

    if(x1=='A')
        return count/p_adenina(a);
        

    if(x1=='G')
        return count/p_guanina(a);
    

    if(x1=='C')
        return count/p_citosina(a);
        

    if(x1=='T')
        return count/p_timina(a);

}







void archivo()
{
    //LEER en ARCHIVO:
    ifstream ficheroEntrada01;
    string cadena01;

    ficheroEntrada01.open ("entrada.txt");
    
    getline(ficheroEntrada01, cadena01);
    ficheroEntrada01.close();
    cout << "ADN es: " << cadena01 << endl;
    
    cout<<"AAAA"<<endl;
    cout<<markov_cont(cadena01,'A','A')<<endl;
    cout<<markov_cont(cadena01,'A','C')<<endl;
    cout<<markov_cont(cadena01,'A','G')<<endl;
    cout<<markov_cont(cadena01,'A','T')<<endl;
    cout<<"CCCC"<<endl;
    cout<<markov_cont(cadena01,'C','A')<<endl;
    cout<<markov_cont(cadena01,'C','C')<<endl;
    cout<<markov_cont(cadena01,'C','G')<<endl;
    cout<<markov_cont(cadena01,'C','T')<<endl;
    cout<<"GGGG"<<endl;
    cout<<markov_cont(cadena01,'G','A')<<endl;
    cout<<markov_cont(cadena01,'G','C')<<endl;
    cout<<markov_cont(cadena01,'G','G')<<endl;
    cout<<markov_cont(cadena01,'G','T')<<endl;
    cout<<"TTTT"<<endl;
    cout<<markov_cont(cadena01,'T','A')<<endl;
    cout<<markov_cont(cadena01,'T','C')<<endl;
    cout<<markov_cont(cadena01,'T','G')<<endl;
    cout<<markov_cont(cadena01,'T','T')<<endl;
    
	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("JMacetas_Practica06_C1.txt");
	ficheroSalida << "Ejerciciio 6-C:"<<endl;
	ficheroSalida << "====================================="<<endl;
    
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}


int main () {
    archivo();
    return(0);
}

// g++ bio05.cpp -p b
// ./b
