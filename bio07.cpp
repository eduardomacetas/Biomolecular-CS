#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

char last(string a){
    int tam=a.size()-1;
    return a[tam];
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



float markov_cont(string a, char x,char y){
    float count=0.0;
    char x1 = x;
    char y1 = y;
    for(int i=0;i<a.size();i++){
        if(a[i]==x1 && a[i+1]==y1){
            count+=1;
        }
    }
    return count;
}

float markov_pro_A(string a, char x, char y){
    float tam = p_adenina(a);
    if (last(a)=='A')
        return markov_cont(a,x,y)/(tam-1);
    else
        return markov_cont(a,x,y)/tam;
}

float markov_pro_C(string a, char x, char y){
    float tam = p_citosina(a);
    if (last(a)=='C')
        return markov_cont(a,x,y)/(tam-1);
    else
        return markov_cont(a,x,y)/tam;
}

float markov_pro_G(string a, char x, char y){
    float tam = p_guanina(a);
    if (last(a)=='G')
        return markov_cont(a,x,y)/(tam-1);
    else
        return markov_cont(a,x,y)/tam;
}

float markov_pro_T(string a, char x, char y){
    float tam = p_timina(a);
    if (last(a)=='T')
        return markov_cont(a,x,y)/(tam-1);
    else
        return markov_cont(a,x,y)/tam;
}

/*void read_matrix(int** matrix, int rows, int cols)
{
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for(int j = 0; i < cols; ++i) {
            cin >> matrix[i][j];
        }
    }
}*/

float formula1(string a){
    int tam = a.size();
    float res = (p_adenina(a)/tam) * markov_pro_A(a,'A','T') * markov_pro_T(a,'T','C') * markov_pro_C(a,'C','A'); 
    return res;
}

float formula2(string a){
    int tam = a.size();
    float res = (p_citosina(a)/tam) * markov_pro_C(a,'C','A') * markov_pro_A(a,'A','G') * markov_pro_G(a,'G','G'); 
    return res;
}

float formula3(string a){
    int tam = a.size();
    float res = (p_guanina(a)/tam) * markov_pro_G(a,'G','A') * markov_pro_A(a,'A','A') * markov_pro_A(a,'A','T'); 
    return res;
}

float formula4(string a){
    int tam = a.size();
    float res = (p_timina(a)/tam) * markov_pro_T(a,'T','G') * markov_pro_G(a,'G','A') * markov_pro_A(a,'A','C'); 
    return res;
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
    
    cout<<formula1(cadena01)<<endl;
    cout<<formula2(cadena01)<<endl;
    cout<<formula3(cadena01)<<endl;
    cout<<formula4(cadena01)<<endl;
    
    
	//ESCRIBIR en ARCHIVO
	ofstream ficheroSalida;
	ficheroSalida.open ("JMacetas_Practica06_C1.txt");
	ficheroSalida << "Ejerciciio 6-C:"<<endl;
	ficheroSalida << "====================================="<<endl;
    ficheroSalida << " ATCA    : "<<formula1(cadena01)<<endl;
    ficheroSalida << " CAGG    : "<<formula2(cadena01)<<endl;
    ficheroSalida << " GAAT    : "<<formula3(cadena01)<<endl;
    ficheroSalida << " TGAC    : "<<formula4(cadena01)<<endl;
	ficheroSalida << "====================================="<<endl;
	ficheroSalida.close();
}


int main () {
    archivo();
    return(0);
}

// g++ bio05.cpp -p b
// ./b
