#include <iostream>
#include <map>
#include <algorithm> 
#include <vector>
#include <string>
#include <ctype.h>
#include <stdio.h>
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

    vector<string> cad_iguales; // vector de string para todas las cadenas que son iguales
    for(int i=0;i<sub_cad1.size();i++){
        for(int j=0;j<sub_cad2.size();j++){
            if (sub_cad1[i] == sub_cad2[j]){
                cad_iguales.push_back(sub_cad1[i]);
                //posicion_i = i;
                //posicion_j = j;  
            }
        }
    }

    // TODAS LAS SUBCADENAS QUE SON iguales, solo  quiero la primera.
    vector<string> cad_iguales_final;
    for(int i=0;i<cad_iguales.size();i++){
        cad_iguales_final.push_back(cad_iguales[i]);
    }

    cout<<"Mi primera cadena que es igual:"<<endl;
    cout<<cad_iguales_final[0]<<endl;

    //Voy a sacar en que posiciones esta para la primera cadena
    for(int i=0;i<sub_cad1.size();i++){
        if (sub_cad1[i] == cad_iguales_final[0]){
            posicion_i = i;
        }
    }

    //Voy a sacar en que posiciones esta para la segunda cadena

    for(int x=0;x<sub_cad2.size();x++){
        if (sub_cad2[x] == cad_iguales_final[0]){
            posicion_j = x;
        }
    }

    cout<<endl;
    cout<<"posicion de mi primera cadena:  "<<posicion_i<<endl;
    cout<<"posicion de mi segunda cadena:  "<<posicion_j<<endl;
    cout<<endl;

    cout<<"Cadenas que son iguales:"<<endl;
    string cadena1r = sub_cad1[posicion_i];
    string cadena2r = sub_cad2[posicion_j];
    cout<<"========="<<endl;
    cout<<cadena1r<<endl;
    cout<<cadena2r<<endl;
    cout<<"========="<<endl;

    int HSP=peso*match;
    
    vector<char> final_cad1;
    vector<char> final_cad2;
    int i = -1;
    int j = 1;

    int nueva_posicion_i_a = posicion_i; //posicion -1
    int nueva_posicion_j_a = posicion_j; //posicion -1
    int nueva_posicion_i_p = posicion_i+peso-1; //posicion +1
    int nueva_posicion_j_p = posicion_j+peso-1; //posicion +1
    
    for(int p=0;p<cadena1r.size();p++){
        final_cad1.push_back(cadena1r[p]);
        final_cad2.push_back(cadena2r[p]);
    }

    while(HSP>umbral){

        if(a[nueva_posicion_i_a+i]==b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]==b[nueva_posicion_j_p+j]){
            if(a[nueva_posicion_i_a+i==NULL] || b[nueva_posicion_i_a==NULL]){
                HSP=HSP+match;
                cout<<"HSP 1.1: "<<HSP<<endl;
                final_cad1.push_back(a[nueva_posicion_i_p+j]);
                final_cad2.push_back(b[nueva_posicion_j_p+j]);   
            }
            else{
                HSP=HSP+(2*match);
                cout<<"HSP 1.2: "<<HSP<<endl;

                final_cad1.push_back(a[nueva_posicion_i_p+j]);
                final_cad2.push_back(b[nueva_posicion_j_p+j]);   
            }
        }

        if(a[nueva_posicion_i_a+i]!=b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]!=b[nueva_posicion_j_p+j]){
            if(a[nueva_posicion_i_a+i]==NULL || b[nueva_posicion_j_a+i]==NULL){
                HSP=HSP+mismatch;
                cout<<"HSP 2.1: "<<HSP<<endl;

                final_cad1.push_back(a[nueva_posicion_i_p+j]);
                final_cad2.push_back(b[nueva_posicion_j_p+j]);   
            }
            else{
                HSP=HSP+(2*mismatch);
                cout<<"HSP 2.2: "<<HSP<<endl;

                final_cad1.push_back(a[nueva_posicion_i_p+j]);
                final_cad2.push_back(b[nueva_posicion_j_p+j]);   
            }
        }

        if(a[nueva_posicion_i_a+i]==b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]!=b[nueva_posicion_j_p+j]){
            if(a[nueva_posicion_i_a+i]==NULL || b[nueva_posicion_i_p+i]==NULL){
                HSP=HSP+0;
                cout<<"HSP 3.1:  "<<HSP<<endl;

                final_cad1.push_back(a[nueva_posicion_i_p+j]);
                final_cad2.push_back(b[nueva_posicion_j_p+j]);   
            }
            else{
                HSP=HSP+match+mismatch; 
                cout<<"HSP 3.2: "<<HSP<<endl;

                final_cad1.push_back(a[nueva_posicion_i_p+j]);
                final_cad2.push_back(b[nueva_posicion_j_p+j]);   
            }
        }

        if(a[nueva_posicion_i_a+i]!=b[nueva_posicion_j_a+i]&&a[nueva_posicion_i_p+j]==b[nueva_posicion_j_p+j]){
            if(a[nueva_posicion_i_a+i]==NULL || b[nueva_posicion_i_p+i]==NULL){
                HSP=HSP+0;
                cout<<"HSP 4.1: "<<HSP<<endl;

                final_cad1.push_back(a[nueva_posicion_i_p+j]);
                final_cad2.push_back(b[nueva_posicion_j_p+j]);   
            }
            else{
                HSP=HSP+mismatch+match;
                cout<<"HSP 4.2: "<<HSP<<endl;

                final_cad1.push_back(a[nueva_posicion_i_p+j]);
                final_cad2.push_back(b[nueva_posicion_j_p+j]);   
            }
        }

        i--;
        j++;
    }
    cout<<endl;
    cout<<"RESULTADO FINAL"<<endl;
    cout<<"============================"<<endl;
    imprimir_vector(final_cad1);
    
    cout<<endl;
    imprimir_vector(final_cad2);
    cout<<endl;
    cout<<"============================"<<endl;
    cout<<endl;
}

int main(){
    cadenas("TCAGATCACGG","GTATCGCTC",+1,-2,3,-3);
    //cadenas("TCAGATCACGG","GTATCGCGG",+1,-2,3,-4);

    return 0;
}