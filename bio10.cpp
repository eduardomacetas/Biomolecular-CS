#include <iostream>
#include <map>
#include <algorithm> 
#include <vector>
#include <string>
using namespace std;

void imprimir_vector(vector<char> myvector){
    for(int i=0;i<myvector.size();i++)
        cout<<myvector[i];
}   


void cadenas(string a, string b, int match, int mismatch, int peso, int umbral){
    int tca = a.size(); // tamano de a
    int tcb = b.size(); // tamano de b
    int dimension = peso;

    vector<string> sub_cad1;
    vector<string> sub_cad2;
    string cad1;
    string cad2;
    int posicion_i;
    int posicion_j;
    
    for(int i=0;i<a.size()-2;i++){
        for(int j=0;j<peso+1;j++){
            cad1=a.substr(i,j);
        }
        
        cout<<cad1<<endl;
        sub_cad1.push_back(cad1);
    }

    cout<<endl;
    cout<<endl;

    for(int i=0;i<b.size()-2;i++){
        for(int j=0;j<peso+1;j++){
            cad2=b.substr(i,j);
        }
        
        cout<<cad2<<endl;
        sub_cad2.push_back(cad2);
    }

    for(int i=0;i<sub_cad1.size();i++){
        for(int j=0;j<sub_cad2.size();j++){
            if (sub_cad1[i] == sub_cad2[j]){
                posicion_i = i;
                posicion_j = j;  
            }
        }
    }

    cout<<endl;
    cout<<"posicion de mi primera cadena:  "<<posicion_i<<endl;
    cout<<"posicion de mi segunda cadena:  "<<posicion_j<<endl;
    cout<<endl;

    cout<<"Cadenas que son iguales:"<<endl;
    string cadena1r = sub_cad1[posicion_i];
    string cadena2r = sub_cad2[posicion_j];
    cout<<cadena1r<<endl;
    cout<<cadena2r<<endl;
    cout<<endl;

    int HSP=peso*match;
    
    vector<char> final_cad1;
    vector<char> final_cad2;
    int i = -1;
    int j = 1;

    int nueva_posicion_i_a = posicion_i; //posicion -1
    int nueva_posicion_j_a = posicion_j; //posicion -1
    int nueva_posicion_i_p = posicion_i+peso-1; //posicion +1
    int nueva_posicion_j_p = posicion_j+peso-1; //posicion +1

    while(HSP>umbral){
        

        if(a[nueva_posicion_i_a+i]==b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]==b[nueva_posicion_j_p+j]){
            HSP=HSP+(2*match);
            cout<<"HSP 1: "<<HSP<<endl;
        }

        /*if(a[nueva_posicion_i_a+i]!=b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]!=b[nueva_posicion_j_p+j]){
            HSP=HSP+(2*mismatch);
            cout<<"HSP 2: "<<HSP<<endl;
        }*/

        if(a[nueva_posicion_i_a+i]!=b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]!=b[nueva_posicion_j_p+j]){
            if(a[nueva_posicion_i_a+i]==NULL || b[nueva_posicion_j_a+i]==NULL){
                HSP=HSP+mismatch;
                cout<<"HSP 2: "<<HSP<<endl;

            }
            else{
                HSP=HSP+(2*mismatch);
                cout<<"HSP 2: "<<HSP<<endl;
            }
        }

        if(a[nueva_posicion_i_a+i]==b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]!=b[nueva_posicion_j_p+j]){
            HSP=HSP+match+mismatch; 
            cout<<"HSP 3: "<<HSP<<endl;
        }
        if(a[nueva_posicion_i_a+i]!=b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]==b[nueva_posicion_j_p+j]){
            HSP=HSP+mismatch+match;
            cout<<"HSP 4: "<<HSP<<endl;
        }
        //cout<<HSP<<endl;
        //cout<<"valor de i: "<<i<<endl;
        //cout<<"valor de j: "<<j<<endl;
        i--;
        j++;
        
    //cout<<HSP<<endl;
    //cout<<"HSP:"<<endl;
    //cout<<HSP<<endl;
    }
    
    
    cout<<"valor:  "<<nueva_posicion_i_a<<endl;
    cout<<"valor:  "<<nueva_posicion_i_p+peso-1<<endl; 
    cout<<"valor:  "<<nueva_posicion_j_a<<endl;
    cout<<"valor:  "<<nueva_posicion_j_p+peso-1<<endl;
    cout<<"ALINEACION"<<endl;
    cout<<"============================================="<<endl;
    for(int p=nueva_posicion_i_a;p<=nueva_posicion_i_p+peso-1;p++){
        cout<<a[p]<<"";
        
    }
    cout<<endl;
    for(int q=nueva_posicion_j_a;q<=nueva_posicion_j_p+peso-1;q++){
        cout<<b[q]<<"";
    }
    cout<<endl;
    cout<<"============================================="<<endl;
    
}

int main(){
    cadenas("TCAGATCACGG","GTATCGCTC",+1,-2,3,-3);
    //cadenas("TCAGATCACGG","GTATCACTC",+1,-2,3,-3);

    return 0;
}