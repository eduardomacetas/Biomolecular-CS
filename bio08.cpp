#include <iostream>
#include <map>
using namespace std;

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
            cout<<"\tM["<<valor<<"]"<<it2->first<<"["<<"]: "<<it2->second;
   }
   cout<<endl;
}
/*void imprimir(){
    for(map<char, map<char,int>>::const_iterator it= pesos.begin(); it != peso.end(); ++it)
        cout<<it->first <<" "<<it->second.first<<" "<<it->second.second<<endl;
}*/




int main ()
{
    map<char, map<char, int> >pesos;
    llenar_Matriz(pesos);
    mostrar_Matriz(pesos);
  
  //imprimir();

  
 

  return 0;
}