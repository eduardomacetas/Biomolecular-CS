#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void promedios_01()
{
	ifstream ficheroEntrada01;
	ifstream ficheroEntrada02;
	ifstream ficheroEntrada03;
	ifstream ficheroEntrada04;

    string cadena01;
    string cadena02;
    string cadena03;
    string cadena04;

    ficheroEntrada01.open ("practica_03B_1.txt");
    getline(ficheroEntrada01, cadena01);
    ficheroEntrada01.close();
    cout << "ADN es: " << cadena01 << endl;
    cout<<"a,shashask"<<endl; 

    ficheroEntrada02.open ("practica_03B_2.txt");
    getline(ficheroEntrada02, cadena02);
    ficheroEntrada02.close();
    cout << "ADN es: " << cadena02 << endl;

    ficheroEntrada03.open ("practica_03B_3.txt");
    getline(ficheroEntrada03, cadena03);
    ficheroEntrada03.close();
    cout << "ADN es: " << cadena03 << endl;

    ficheroEntrada04.open ("practica_03B_4.txt");
    getline(ficheroEntrada04, cadena04);
    ficheroEntrada04.close();
    cout << "ADN es: " << cadena04 << endl;

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

	///////// CADENA 02

    string ADN02=cadena02;
	float Adenina2=0;
	float Timina2=0;
	float Citosina2=0;
	float Guanina2=0;

	for(int i=0;i<ADN02.size();i++){
		
		if(ADN02[i]=='A'){
			Adenina2+=1;	
		}
		if(ADN02[i]=='T'){
			Timina2+=1;
		}
		if(ADN02[i]=='C'){
			Citosina2+=1;
			
		}
		if(ADN01[i]=='G'){
			Guanina2+=1;
		}
	}

	float p_Adenina2 = (Adenina2/ADN02.size());
	float p_Timina2 = (Timina2/ADN02.size());
	float p_Citosina2 = (Citosina2/ADN02.size());
	float p_Guanina2 = (Guanina2/ADN02.size());

	///////// CADENA 03

    string ADN03=cadena03;
	float Adenina3=0;
	float Timina3=0;
	float Citosina3=0;
	float Guanina3=0;

	for(int i=0;i<ADN03.size();i++){
		
		if(ADN03[i]=='A'){
			Adenina3+=1;	
		}
		if(ADN03[i]=='T'){
			Timina3+=1;
		}
		if(ADN03[i]=='C'){
			Citosina3+=1;
			
		}
		if(ADN03[i]=='G'){
			Guanina3+=1;
		}
	}

	float p_Adenina3 = (Adenina3/ADN03.size());
	float p_Timina3 = (Timina3/ADN03.size());
	float p_Citosina3 = (Citosina3/ADN03.size());
	float p_Guanina3 = (Guanina3/ADN03.size());

///////// CADENA 04

    string ADN04=cadena04;
	float Adenina4=0;
	float Timina4=0;
	float Citosina4=0;
	float Guanina4=0;
	cout<<ADN04.size()<<endl;

	for(int i=0;i<ADN04.size();i++){
		
		if(ADN04[i]=='A'){
			Adenina4+=1;	
		}
		if(ADN04[i]=='T'){
			Timina4+=1;
		}
		if(ADN04[i]=='C'){
			Citosina4+=1;
			
		}
		if(ADN04[i]=='G'){
			Guanina4+=1;
		}
	}

	float p_Adenina4 = (Adenina4/ADN04.size());
	float p_Timina4 = (Timina4/ADN04.size());
	float p_Citosina4 = (Citosina4/ADN04.size());
	float p_Guanina4 = (Guanina4/ADN04.size());

	////probabilidad de seleccionar una A de la 1ra cadena
	float P_TOTAL_Adenina_1 = (p_Adenina * 0.25) / ((p_Adenina * 0.25) + (p_Adenina2 * 0.25) + (p_Adenina3 * 0.25) + (p_Adenina4 *0.25));
	cout<<P_TOTAL_Adenina_1<<endl;
	////probabilidad de seleccionar una A de la 2da cadena
	float P_TOTAL_Adenina_2 = (p_Adenina2 * 0.25) / ((p_Adenina2 * 0.25) + (p_Adenina * 0.25) + (p_Adenina3 * 0.25) + (p_Adenina4 *0.25));
	cout<<P_TOTAL_Adenina_2<<endl;
	////probabilidad de seleccionar una A de la 3ra cadena
	float P_TOTAL_Adenina_3 = (p_Adenina3 * 0.25) / ((p_Adenina3 * 0.25) + (p_Adenina * 0.25) + (p_Adenina2 * 0.25) + (p_Adenina4 *0.25));
	cout<<P_TOTAL_Adenina_3<<endl;
	////probabilidad de seleccionar una A de la 4ta cadena
	float P_TOTAL_Adenina_4 = (p_Adenina4 * 0.25) / ((p_Adenina4 * 0.25) + (p_Adenina2 * 0.25) + (p_Adenina3 * 0.25) + (p_Adenina *0.25));
	cout<<P_TOTAL_Adenina_4<<endl;


	////probabilidad de seleccionar una G de la 1ra cadena
	float P_TOTAL_Guanina_1 = (p_Guanina * 0.25) / ((p_Guanina * 0.25) + (p_Guanina2 * 0.25) + (p_Guanina3 * 0.25) + (p_Guanina4 *0.25));
	cout<<P_TOTAL_Guanina_1<<endl;
	////probabilidad de seleccionar una G de la 2da cadena
	float P_TOTAL_Guanina_2 = (p_Guanina2 * 0.25) / ((p_Guanina2 * 0.25) + (p_Guanina * 0.25) + (p_Guanina3 * 0.25) + (p_Guanina4 *0.25));
	cout<<P_TOTAL_Guanina_2<<endl;
	////probabilidad de seleccionar una G de la 3ra cadena
	float P_TOTAL_Guanina_3 = (p_Guanina3 * 0.25) / ((p_Guanina3 * 0.25) + (p_Guanina * 0.25) + (p_Guanina2 * 0.25) + (p_Guanina4 *0.25));
	cout<<P_TOTAL_Guanina_3<<endl;
	////probabilidad de seleccionar una G de la 4ta cadena
	float P_TOTAL_Guanina_4 = (p_Guanina4 * 0.25) / ((p_Guanina4 * 0.25) + (p_Guanina2 * 0.25) + (p_Guanina3 * 0.25) + (p_Guanina *0.25));
	cout<<P_TOTAL_Guanina_4<<endl;

	////probabilidad de seleccionar una T de la 1ra cadena
	float P_TOTAL_Timina_1= (p_Timina * 0.25) / ((p_Timina * 0.25) + (p_Timina2 * 0.25) + (p_Timina3 * 0.25) + (p_Timina4 *0.25));
	cout<<P_TOTAL_Timina_1<<endl;
	////probabilidad de seleccionar una T de la 2ra cadena
	float P_TOTAL_Timina_2= (p_Timina2 * 0.25) / ((p_Timina2 * 0.25) + (p_Timina * 0.25) + (p_Timina3 * 0.25) + (p_Timina4 *0.25));
	cout<<P_TOTAL_Timina_2<<endl;
	////probabilidad de seleccionar una T de la 3ra cadena	
	float P_TOTAL_Timina_3= (p_Timina3 * 0.25) / ((p_Timina3 * 0.25) + (p_Timina * 0.25) + (p_Timina2 * 0.25) + (p_Timina4 *0.25));
	cout<<P_TOTAL_Timina_3<<endl;
	////probabilidad de seleccionar una T de la 4ra cadena
	float P_TOTAL_Timina_4= (p_Timina4 * 0.25) / ((p_Timina4 * 0.25) + (p_Timina * 0.25) + (p_Timina2 * 0.25) + (p_Timina3 *0.25));
	cout<<P_TOTAL_Timina_4<<endl;

	////probabilidad de seleccionar una C de la 1ra cadena
	float P_TOTAL_Citosina_1= (p_Citosina * 0.25) / ((p_Citosina * 0.25) + (p_Citosina2 * 0.25) + (p_Citosina3 * 0.25) + (p_Citosina4 *0.25));
	cout<<P_TOTAL_Citosina_1<<endl;
	////probabilidad de seleccionar una C de la 2da cadena
	float P_TOTAL_Citosina_2= (p_Citosina2 * 0.25) / ((p_Citosina2 * 0.25) + (p_Citosina * 0.25) + (p_Citosina3 * 0.25) + (p_Citosina4 *0.25));
	cout<<P_TOTAL_Citosina_2<<endl;
	////probabilidad de seleccionar una C de la 3ra cadena
	float P_TOTAL_Citosina_3= (p_Citosina3 * 0.25) / ((p_Citosina3 * 0.25) + (p_Citosina * 0.25) + (p_Citosina2 * 0.25) + (p_Citosina4 *0.25));
	cout<<P_TOTAL_Citosina_3<<endl;
	////probabilidad de seleccionar una C de la 4ta cadena
	float P_TOTAL_Citosina_4= (p_Citosina4 * 0.25) / ((p_Citosina4 * 0.25) + (p_Citosina * 0.25) + (p_Citosina2 * 0.25) + (p_Citosina3 *0.25));
	cout<<P_TOTAL_Citosina_4<<endl;
	

    ofstream ficheroSalida;
    ficheroSalida.open ("JMacetas_practica_03B.txt");    
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"probabilidad de seleccionar una A de la 1ra cadena :"<<P_TOTAL_Adenina_1<<endl;
    ficheroSalida<<"probabilidad de seleccionar una A de la 2da cadena :"<<P_TOTAL_Adenina_2<<endl;
    ficheroSalida<<"probabilidad de seleccionar una A de la 3ra cadena :"<<P_TOTAL_Adenina_3<<endl;
    ficheroSalida<<"probabilidad de seleccionar una A de la 4ta cadena :"<<P_TOTAL_Adenina_4<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"probabilidad de seleccionar una G de la 1ra cadena :"<<P_TOTAL_Guanina_1<<endl;
    ficheroSalida<<"probabilidad de seleccionar una G de la 2da cadena :"<<P_TOTAL_Guanina_2<<endl;
    ficheroSalida<<"probabilidad de seleccionar una G de la 3ra cadena :"<<P_TOTAL_Guanina_3<<endl;
    ficheroSalida<<"probabilidad de seleccionar una G de la 4ta cadena :"<<P_TOTAL_Guanina_4<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"probabilidad de seleccionar una T de la 1ra cadena :"<<P_TOTAL_Timina_1<<endl;
    ficheroSalida<<"probabilidad de seleccionar una T de la 2da cadena :"<<P_TOTAL_Timina_2<<endl;
    ficheroSalida<<"probabilidad de seleccionar una T de la 3ra cadena :"<<P_TOTAL_Timina_3<<endl;
    ficheroSalida<<"probabilidad de seleccionar una T de la 4ta cadena :"<<P_TOTAL_Timina_4<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"probabilidad de seleccionar una C de la 1ra cadena :"<<P_TOTAL_Citosina_1<<endl;
    ficheroSalida<<"probabilidad de seleccionar una C de la 2da cadena :"<<P_TOTAL_Citosina_2<<endl;
    ficheroSalida<<"probabilidad de seleccionar una C de la 3ra cadena :"<<P_TOTAL_Citosina_3<<endl;
    ficheroSalida<<"probabilidad de seleccionar una C de la 4ta cadena :"<<P_TOTAL_Citosina_4<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida<<"========================================="<<endl;
    ficheroSalida.close();

    
}

int main()
{
    
    promedios_01();
    return 0;
}