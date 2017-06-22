#include <cstdlib> // Para gerar numeros randômicos
#include <iostream>
#include <string> // Para trabalhar fácil com strings
#include <sstream> // Para trabalhar fácil com strings
#include <math.h> // Para ajudar em calculos matemáticos
#include <ctime>  // Para usar o time() e fornecer um bom seed para o random
#include <vector>
using namespace std;

#define CIUDAD 5

// Variables: 
#define p 0.99 //evaporacion
#define ALFA 1
#define BETA 1
#define Q 1
#define FEROMONA 0.1 //feromona inicial
#define HORMIGAS 3 
#define MAX_TIME 100 //iteraciones


// Matriz:
float distancia[CIUDAD][CIUDAD] = {
    {0.0, 12.0, 3.0, 23.0, 1.0},
    {12.0 ,0.0, 9.0, 18.0, 3.0},
    {3.0, 9.0, 0.0, 89.0, 56.0},
    {23.0, 18.0, 89.0, 0.0, 87.0},
    {1.0, 3.0, 56.0, 87.0, 0.0}
    };

// Matriz Distancia:
void imprimir_distancia(int f, int c, float M[CIUDAD][CIUDAD]){
    cout<<"Matriz Distancia: "<<endl;
    cout<<endl;
    cout<<"=================================================="<<endl;
    for(int i=0;i<CIUDAD;i++){
        for(int j=0;j<CIUDAD;j++){
            cout<<"\t"<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"=================================================="<<endl;
}

// Matriz Visibilidad:
void matriz_visibilidad(float M[CIUDAD][CIUDAD], float x){
    cout<<"Matriz Visibilidad: "<<endl;
    cout<<"=================================================="<<endl;
    for(int i=0;i<CIUDAD;i++){
        for(int j=0;j<CIUDAD;j++){
            if(M[i][j]==0){
                cout<<"\t"<<"0.0"<<" ";
            }
            else{
                cout<<"\t"<<x/M[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"=================================================="<<endl;
}

//Random:
float get_random_number(float desde, int hasta) {
	return (desde < hasta) ? (rand() % hasta) + desde : 0;
}

//Ruleta:
// s => sumatoria
int ruleta(vector<float> v, float s){
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    cout<<endl;  
    cout<<"Numero Aleatorio para la Probabilidad:  "<<r<<endl;
    int i=0;
    while(r>0.0){
        r = r-v[i];
        i++;
    }
    return i-1;   
}

//Imprimir vector(SALIDA):
void imprimir_v(vector<char> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" - ";
    }
}

// convertir:
// letra => inicio del camino
void convertir(char letra, float M[CIUDAD][CIUDAD]){
    cout<<"Ciudad Inicial:   "<<letra<<endl;
    cout<<endl;

    // en el vector voy a poner 0-A 1-B...
    vector<char> letras_ciudades;
    letras_ciudades.push_back('A');
    letras_ciudades.push_back('B');
    letras_ciudades.push_back('C');
    letras_ciudades.push_back('D');
    letras_ciudades.push_back('E');


    // Un vector para guardar las ciudades visitadas
    // por defecto voy a guardar la letra que se ingresa al comienzo:
    vector<char> ciudades_visitadas;
    ciudades_visitadas.push_back(letra);

    /*
    vector<char> ciudades_no_visitadas;
    letras_ciudades.push_back('A');
    letras_ciudades.push_back('B');
    letras_ciudades.push_back('C');
    letras_ciudades.push_back('D');
    letras_ciudades.push_back('E');
    */

    
    


    while(ciudades_visitadas.size()<CIUDAD){
    
   

        int tem_num = ciudades_visitadas.size();

        // Camino: 
        // a_suma => acumulador de la suma 
        float a_suma=0.0;
        for(int i=0;i<CIUDAD;i++){
            if(tem_num!=i){
                // v almancena el resultado:
                float v = FEROMONA*(1/M[tem_num][i]);
                cout<<letras_ciudades[tem_num]<<" - "<<letras_ciudades[i]<<" : "<<v<<endl;
                a_suma = a_suma+v;
            }else{
                a_suma = a_suma+0.0;
            }
            // imprimo la suma
            
        }

        cout<<endl;
        cout<<"Esta es la suma total: "<<a_suma<<endl;
        cout<<endl;

        // Probabilidades:
        vector<float> probabilidad;
        for(int i=0;i<CIUDAD;i++){
            if(tem_num!=i){
                float v = FEROMONA*(1/M[tem_num][i]);
                cout<<letras_ciudades[tem_num]<<" - "<<letras_ciudades[i]<<" : prob = "<<v/a_suma<<endl;
                probabilidad.push_back(v/a_suma);
            }
        }

        int val_r = ruleta(probabilidad,a_suma);
        ciudades_visitadas.push_back(letras_ciudades[val_r]);
        cout<<endl;
        imprimir_v(ciudades_visitadas);
        cout<<endl;
        probabilidad.clear();
    }



    

    

}




int main(){
    imprimir_distancia(CIUDAD,CIUDAD,distancia);
    matriz_visibilidad(distancia,1.0);
    convertir('D',distancia);
    return 0;
} 
