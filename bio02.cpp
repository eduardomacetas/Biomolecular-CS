#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void promedios()
{
	ifstream ficheroEntrada;
    string cadena;

    ficheroEntrada.open ("practica_02A.txt");
    getline(ficheroEntrada, cadena);
    ficheroEntrada.close();
    cout << "ADN es: " << cadena << endl;

    string ADN=cadena;
	float Adenina=0;
	float Timina=0;
	float Citosina=0;
	float Guanina=0;

	for(int i=0;i<ADN.size();i++){
		
		if(ADN[i]=='A'){
			Adenina+=1;	
		}
		if(ADN[i]=='T'){
			Timina+=1;
		}
		if(ADN[i]=='C'){
			Citosina+=1;
			
		}
		if(ADN[i]=='G'){
			Guanina+=1;
		}
	}

	float p_Adenina = (Adenina/ADN.size());
	float p_Timina = (Timina/ADN.size());
	float p_Citosina = (Citosina/ADN.size());
	float p_Guanina = (Guanina/ADN.size());
	float p_Purinas = ((Adenina+Guanina)/ADN.size());
	float p_Pirimidas = ((Citosina+Timina)/ADN.size());

    ofstream ficheroSalida;
    ficheroSalida.open ("JMacetas_practica_02A.txt");    
    ficheroSalida<<"PROMEDIO de Adenina :"<<p_Adenina<<endl;
    ficheroSalida<<"PROMEDIO de Timina :"<<p_Timina<<endl;
    ficheroSalida<<"PROMEDIO de Citosina :"<<p_Citosina<<endl;
    ficheroSalida<<"PROMEDIO de Guanina :"<<p_Guanina<<endl;
    ficheroSalida<<"PROMEDIO de Purinas :"<<p_Purinas<<endl;
    ficheroSalida<<"PROMEDIO de Pirimidas :"<<p_Pirimidas<<endl;
    ficheroSalida.close();

}

int main()
{
    
    promedios();
    return 0;
}