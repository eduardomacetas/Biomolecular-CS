#include <iostream>
#include <map>
#include <algorithm> 
#include <vector>
using namespace std;

#define MAX_M 7
#define MAX_N 9


void llenar_Matriz( map<char, map<char, int> >&pesos){

    pesos['A']['A'] = 10;
    pesos['A']['G'] = -1;
    pesos['A']['C'] = -3;
    pesos['A']['T'] = -4;

    pesos['G']['A'] = -1;
    pesos['G']['G'] = 7;
    pesos['G']['C'] = -5;
    pesos['G']['T'] = -3;

    pesos['C']['A'] = -3;
    pesos['C']['G'] = -5;
    pesos['C']['C'] = 9;
    pesos['C']['T'] = 0;

    pesos['T']['A'] = -4;
    pesos['T']['G'] = -3;
    pesos['T']['C'] = 0;
    pesos['T']['T'] = 8;
}

void mostrar_Matriz(map<char, map<char, int> >&pesos){
   map<char, map<char, int> > :: iterator it =pesos.begin();
   map<char, int> :: iterator it2;
   for(it =pesos.begin(); it!=pesos.end();it++)
   {
       map<char, int> segu =(it->second);
       char valor =it->first;
        for(it2 =segu.begin(); it2!=segu.end();it2++)
            cout<<"\tM["<<valor<<"]"<<"["<<it2->first<<"]: "<<it2->second;
            cout<<"   "<<endl;
   }
   cout<<endl;
}

int comparar(int a, int b, int c){
    int big_int = a;
    if (a < b)
        big_int = b;
    if (big_int < c)
        big_int = c;
    return big_int;
}


void imprimir_vector(vector<char> myvector){
    for(int i=myvector.size(); i>0;--i)
        cout<<" "<<myvector[i];
}



// string a = size de N = 9+1
// string b = size de M = 6+1
void matrix(string a, string b, int gaps, map<char, map<char, int> >&pesos){
    int tam_a = a.size()+1; //9
    int tam_b = b.size()+1; //7
    int matrix[tam_b][tam_a];
    
    for(int i=0;i<tam_a;i++){
        matrix[0][i] = - i*5;
    }
    
    for(int i=0;i<tam_b;++i){
        
        matrix[i][0] = - i*5;
    }

    
    for(int i=1;i<tam_b;i++){ //7
        for(int j=1;j<tam_a;j++){ //9pX
            char c1 = a[j-1];
            char c2 = b[i-1];
            
            int vp = pesos[c1][c2];
            
            int a = vp + matrix[i-1][j-1]; //diagonal
            int b = matrix[i-1][j] -5; //el de arriba
            int c = matrix[i][j-1] -5; //el de la izquierda

            int com = comparar(a,b,c);
            matrix[i][j] = com;      
            cout<<matrix[i][j]<<"   ";
        }
        cout<<" "<<endl;
    }

    
    //funcion principal, para alinear la cadena:
    int tca = a.size()-1; //7
    int tcb = b.size()-1; //5
    int aa = a.size();//8
    int bb =b.size();//6

    vector<char> cadena1; //guardo en la cadena A
    vector<char> cadena2; //guardo en la cadena B
  
    while(tca>1){

        char c1 = a[tca]; // ACCGTCTT
        char c2 = b[tcb]; // CGTCTT

        int valor = pesos[c1][c2];
        int nv = matrix[bb][aa] - valor;

        if(nv==matrix[bb-1][aa-1]){//diagonal
            nv==matrix[bb-1][aa-1];
            cadena1.push_back(c1);
            cadena2.push_back(c2);
            tca--;
            tcb--;
            aa--;
            bb--;
        }   

        if(nv==matrix[bb][aa-1]){ //izquierda
            nv=matrix[bb][aa-1];
            cadena1.push_back(c1);
            cadena2.push_back(c2);
            tca--;
            tcb--;
            aa--;
            bb--;
        }

        if(nv==matrix[bb-1][aa]){ //arriba
            nv=matrix[bb-1][aa];
            cadena1.push_back(c1);
            cadena2.push_back(c2);
            tca--;
            tcb--;
            aa--;
            bb--;
        }
        
    }

    cadena1.push_back('-');
    cadena1.push_back('-');
    imprimir_vector(cadena1);
    cout<<endl;

    cadena2.push_back('-');
    cadena2.push_back('-');

    imprimir_vector(cadena2);
    cout<<endl;
    
}

int main ()
{
    map<char, map<char, int> >pesos;
    llenar_Matriz(pesos);
    mostrar_Matriz(pesos);
    matrix("ACCGTCTT","CGTCTT",-5,pesos);
    

  
 

  return 0;
}

