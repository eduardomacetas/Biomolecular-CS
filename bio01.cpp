#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string transcribir(string cadena)
{
    string ARN;
    string ADN=cadena;

    for(int i=0;i<ADN.size();i++)
    {
        if(ADN[i]=='T')
        {
            ARN[i]='U';
        }
        else
        {
            ARN[i]=ADN[i];
        }
    ARN.push_back(ARN[i]);
    }   
    return ARN;  
}


void traducir(string cadena)
{
    int numberOfCodons;
    int rnaLength;
    int beginIndex;
    int endIndex;
    int i,j,k;
    string codons[64] = {"UUU","UUC","UUA","UUG","UCU","UCC","UCA","UCG","UAU","UAC","UAA","UAG","UGU","UGC","UGA","UGG", 
                         "CUU","CUC","CUA","CUG","CCU","CCC","CCA","CCG","CAU","CAC","CAA","CAG","CGU","CGC","CGA","CGG",
                         "AUU","AUC","AUA","AUG","ACU","ACC","ACA","ACG","AAU","AAC","AAA","AAG","AGU","AGC","AGA","AGG",
                         "GUU","GUC","GUA","GUG","GCU","GCC","GCA","GCG","GAU","GAC","GAA","GAG","GGU","GGC","GGA","GGG"};

    char aminoAcids[]={'F','F','L','L','S','S','S','S','Y','Y','.','.','C','C','.','W',
                           'L','L','L','L','P','P','P','P','H','H','Q','Q','R','R','R','R',
                           'I','I','I','M','T','T','T','T','N','N','K','K','S','S','R','R',
                           'V','V','V','V','A','A','A','A','D','D','E','E','G','G','G','G'};
    

    /*string aminoAcids[64]={"F","F","L","L","S","S","S","S","Y","Y",".",".","C","C",".","W",
                           "L","L","L","L","P","P","P","P","H","H","Q","Q","R","R","R","R",
                           "I","I","I","M","T","T","T","T","N","N","K","K","S","S","R","R",
                           "V","V","V","V","A","A","A","A","D","D","E","E","G","G","G","G"};                       
                           */
    string codon;
    string protein;
    string RNA=cadena;
    
    rnaLength=RNA.length();
    for(int i=0; i<RNA.length(); i+=3){
            cout<<RNA[i];
            //cout<<endl;
        if(i+1 < RNA.length())
            cout<<RNA[i+1];
            //cout<<endl;
        if(i+2 < RNA.length())
            cout<<RNA[i+2];
    }

    numberOfCodons=rnaLength/3;
    beginIndex=0;
    string temp="";
    cout<<"Numero de aminoAcids: "<<numberOfCodons<<endl;
    for(i=0; i<RNA.size();i+=3){
        for(j=0;j<3;j++){
            temp+=RNA[i+j];
        }
        for(k=0;k<64;k++){
            if(temp==codons[k])
            {
                codon.push_back(aminoAcids[k]);
                codon.push_back(' ');
            }
        }
        temp="";
    }
    cout<<codon<<endl;
}

void leer_escribir()
{
    ifstream ficheroEntrada;
    string cadena;

    ficheroEntrada.open ("ficheroTexto.txt");
    getline(ficheroEntrada, cadena);
    ficheroEntrada.close();
    cout << "ADN es: " << cadena << endl;

    ofstream ficheroSalida;
    ficheroSalida.open ("JMacetas_Practica01_A_1.txt");
    //
    string nARN = transcribir(cadena);
    ficheroSalida<<nARN;
    ficheroSalida.close();

    cout << "ARN es: " << transcribir(cadena) << endl;

}

int main()
{
    //transcribir("TTTTTAAACA");
    //leer_escribir();
    traducir("ACAGACAGAUACAAU"); //T
    return 0;
}

// g++ bio01.cpp -o bio
// ./bio