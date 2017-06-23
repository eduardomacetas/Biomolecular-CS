#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <fstream>

#define ciudades 5
#define numAnts 3
#define maxTime 100
using namespace std;

int alpha = 1;                  // influence of pheromone in direction
int beta = 1;                   // influence of adjacent node distance
double rho = 0.99;              //  pheromone decrease factor
double Q = 1.0;               // pheromone increase factor 
double f = 0.1;                 // pheromone initial

double distancias[ciudades][ciudades] = {
    {0, 12, 3, 23, 1},
    {12,0, 9, 18, 3},
    {3, 9, 0, 89, 56},
    {23, 18, 89, 0, 87},
    {1, 3, 56, 87, 0}
    };

//Imprime la matriz de distancias:
void Graph(double dist[ciudades][ciudades]){
    cout<<"Distancias :"<<endl;
	for (int i = 0; i < ciudades; i++) {
		for (int j = 0; j < ciudades; j++) {
            cout<<"\t"<<dist[i][j]<<"  ";
        }
        cout<<endl;
	}
}

//Imprime la Matriz de Visibilidad: 
// para esto tenemos que dividir 1/distancia(x,y)
// 1 creo por que es por defecto x?
void PrintVisibilidad(double visibilidad[ciudades][ciudades]){
    cout<<"Visibilidad :"<<endl;
    for(int i=0;i<ciudades;i++){
        for(int j=0;j<ciudades;j++){
            if(i==j){
                visibilidad[i][j] = 0.0;
                cout<<"\t0.0";
            }else{
                visibilidad[i][j] = 1.0/visibilidad[i][j];
                cout<<"\t"<<visibilidad[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

//Imprime las feromonas:
void PrintPheromones(double pheromones[ciudades][ciudades], double f){
    cout<<"Feromona Inicial :"<<endl;
	for (int i = 0; i < ciudades; i++) {
		for (int j = 0; j < ciudades; j++) {
            if(j==i){
                pheromones[i][j]=0.0;
                cout<<"\t0.0 ";
            }else{
                pheromones[i][j]=f;
                cout<<"\t"<<f<<" ";
            }
		}
        cout<<endl;	
	}
}

//Objectivo (target) => si es que voy a poder llegar a ese camino
int IndexOfTarget(int target, int camino[]){
    int i;
    for(int i=0;i<ciudades;i++){
        if(camino[i]==target) return i;
    }
    cout<<"Destino no encontrado:   "<<i<<endl;

}

//Iniciando las hormigas:
void InitAnts(int ants[numAnts][ciudades]){
	for (int i = 0; i < numAnts; i++) {
		//int start = rand() % numCities;
		int start = 3;
		int trail[ciudades];
		for (int j = 0; j < ciudades; j++) {
			trail[j] = j;
            cout<<"trail[j]:  "<<trail[j]<<endl;
		}
		random_shuffle(trail, trail + ciudades);
		int index = IndexOfTarget(start, trail);
		swap(trail[0], trail[index]);
		for (int j = 0; j < ciudades; j++) {
			ants[i][j] = trail[j];
            cout<<"ants[i][j]:  "<<ants[i][j]<<endl;
		}
	}
}


int main(){
    
    Graph(distancias);
    PrintVisibilidad(distancias);
    PrintPheromones(distancias,f);

    int ants[numAnts][ciudades];
    InitAnts(ants);
    

    

    return 0;
}

