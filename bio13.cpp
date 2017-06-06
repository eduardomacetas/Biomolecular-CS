#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
#include <stack>

using namespace std;
#define MAX_N 1001


void llenar_datos(map<char,map<char, int> > &datos){
	datos['A']['A'] =10;	datos['A']['G'] =-1;	datos['A']['C'] =-3;	datos['A']['T'] =-4;
	datos['G']['A'] =-1;	datos['G']['G'] = 7;	datos['G']['C'] =-5;	datos['G']['T'] =-3;
	datos['C']['A'] =-3;	datos['C']['G'] =-5;	datos['C']['C'] = 9;	datos['C']['T'] = 0;
	datos['T']['A'] =-4;	datos['T']['G'] =-3;	datos['T']['C'] = 0;	datos['T']['T'] = 8;
}

string obtener_cadena(vector<pair<char, char> >&alineados,bool pos){
	if(alineados.size()==0)
		cout<<"\nERROR ALINEACIONES VACIAS\n";
	else{
		string cadena="";
		for (int i = 0; i < alineados.size(); ++i){
			if(pos==0)
				cadena +=alineados[i].first;
			else
				cadena +=alineados[i].second;
		}
		return cadena;
	}

}
pair<string, string> needleman_wunch(string cad1, string cad2){
	map<char,map<char, int> > datos;
	llenar_datos(datos);
	vector<pair<char, char> > alineados;
	alineados.clear();
	vector< vector<int> > M;
	M.resize(cad1.size()+1);
	for (int i = 0; i < cad1.size()+1; ++i){
		M[i].resize(cad2.size()+1);
	}
	//llenado de vacios fila
	for (int i = 0; i < M.size(); ++i){
		M[i][0] =(-5)*i;
	}
	//llenamos de vacios las columnas
	for (int i = 0; i < M[0].size(); ++i){
		M[0][i] =(-5)*i;
	}

	//llenado de la matriz
	vector<int> v;//vector que contendra los resultados

	for (int i = 1; i < M.size(); ++i){
		for (int j = 1; j < M[0].size(); ++j){
			//cout<<"\n\t"<<i<<" "<<j<<endl;
			v.push_back(datos[cad1[i-1]][cad2[j-1]] + M[i-1][j-1]);//diagonal
			//cout<<"Diagonal: "<<datos[cad1[i-1]][cad2[j-1]] + M[i-1][j-1]<<endl;
			v.push_back(M[i-1][j] -5);//superior
			//cout<<"Superior: "<<M[i-1][j] -5<<endl;
			v.push_back(M[i][j-1] -5);//izquierdo
			//cout<<"Izquierdo: "<<M[i][j-1] -5<<endl;
			sort(v.begin(),v.end());
			M[i][j] =v[v.size()-1];
			v.clear(); 
		}
	}


	int i=M.size()-1;
	int j=M[0].size()-1;
	while(i>0 && j>0){
		//cout<<"\n"<<i<<" : "<<j<<"\n";
		if(M[i][j] == (datos[cad1[i-1]][cad2[j-1]] +M[i-1][j-1])){//diagonal
			alineados.push_back(make_pair(cad1[i-1],cad2[j-1]));
			i--;
			j--;
		}
		else if(M[i][j] ==(M[i-1][j] -5)){//superior
			alineados.push_back(make_pair(cad1[i-1],'-'));
			i--;
		}
		else if(M[i][j] == (M[i][j-1] -5)){//izquierda
			alineados.push_back(make_pair('-',cad2[j-1]));
			j--;
		}
		else break;
	}
	if (i>0){
		//cout<<"\n\t i: "<<i<<endl;
		for (int k1 = i; k1 > 0; --k1)
		{
			alineados.push_back(make_pair(cad1[k1],'-'));
		}
	}
	if(j>0){
		//cout<<"\n\t j: "<<j<<endl;
		for (int k1 = j; k1 >0; --k1)
		{
			alineados.push_back(make_pair('-',cad2[k1-1]));
		}
	}
	/*
	cout<<"\nALINEAMIENTO: "<<alineados.size()<<endl;
	
	for (int i = 0; i < alineados.size(); ++i){
		cout<<alineados[i].first<<"\t"<<alineados[i].second<<endl;
	}
	*/
	reverse(alineados.begin(), alineados.end());
	pair<string,string> ali;
	ali =make_pair(obtener_cadena(alineados,0),obtener_cadena(alineados,1));
	return ali;
}

// ALINEACION DIRECTA: con esta funcion voy a hacer la alineacion de
// 2 cadenas... lo que hace es completar con -- 

pair<string, string> alineacion_directa(string cadena1, string cadena2){
	if(cadena1.size()==cadena2.size())
		return make_pair(cadena1,cadena2);
	else if(cadena1.size()>cadena2.size()){
		string  cadena = cadena2;
		for (int i = 0; i < cadena1.size()-cadena2.size(); ++i){
			cadena +='-';
		}
		return make_pair(cadena1,cadena);
	}
	else{
		string  cadena = cadena1;
		for (int i = 0; i < cadena2.size()-cadena1.size(); ++i){
			cadena +='-';
		}
		return make_pair(cadena,cadena2);
	}
}

// Es la sumatoria de las cadenas con el match, mismatch, gap
// TGTTAAC --  TGTAAC => 10

int sum_cadenas(string cadena1, string cadena2, int match,int mismatch, int gap){
	if(cadena1.size()!=cadena2.size()){
        cout<<"Falta llenar --- guiones"<<endl;
		return -1;
	}
	else{
		int tmp =0;
		for (int i = 0; i < cadena1.size(); ++i){
			if(cadena1[i]=='-' && cadena2[i]=='-')
				tmp +=gap;
			else if(cadena1[i]==cadena2[i])
				tmp +=match;
			else{
				if(cadena1[i]=='-')
					tmp +=gap;
				else if(cadena2[i]=='-')
					tmp +=gap;
				else tmp +=mismatch;
			}
		}
		return tmp;	
	}
}

// FUncion para ordenar de mayor a menor

void ordenar_parejas(vector<pair<int,int> > &v, int tam){
	vector<int> marcados; //ya han sido marcados (utlizados)
	vector<pair<int,int> > res; 
	for (int i = 0; i < v.size(); ++i){
		auto find1= find(marcados.begin(),marcados.end(), v[i].first);
		auto find2= find(marcados.begin(),marcados.end(), v[i].second);
		if(find1 == marcados.end() ){//si no le encuentra
			if(find2 == marcados.end() ){//si no le encuentra
				marcados.push_back(v[i].first);
				marcados.push_back(v[i].second);
				res.push_back(v[i]);
			}
		}
	}

	marcados.clear(); // Por si acaso LIMPIO los marcados despues del for
	//buscaremos el elemento que falta
	marcados.resize(tam);
	for (int i = 0; i < tam; ++i){
		marcados[i] =i;
	}

	//std::vector<int>::iterator it;
    vector<int>::iterator it;
	for (int i = 0; i < res.size(); ++i){
		it =find(marcados.begin(),marcados.end(), res[i].first);
		marcados.erase(it);
		it =find(marcados.begin(),marcados.end(),res[i].second);
		marcados.erase(it);
	}

	if(marcados.size()!=0){
		res.push_back(make_pair(marcados[0],marcados[0]));
    }
	v = res;
}

// Funcion para comparar los char de la cadena1, cadena 2
// con su match, mismatch y gap ===> get_peso2('c','a',2,1,0);
int eval_char(char c1,char c2, int match, int mismatch, int gap){
	int tmp =0;
	if(c1=='-' && c2=='-')
		tmp +=gap;
	else if(c1==c2)
		tmp +=match;
	else{
		if(c1=='-')
			tmp +=gap;
		else if(c2=='-')
			tmp +=gap;
		else tmp +=mismatch;
	}
	return tmp;	
}

int p_diagonal(vector<string>&data_f, vector<string>&data_c, int match, int mismatch, int gap, int posicion_i,int posicion_j){
	int tmp=0;
	for (int i = 0; i < data_c.size(); ++i){
		for (int j = 0; j < data_f.size() ; ++j){
			//cout<<"("<<data_c[i][posicion_j]<<" , "<<data_f[j][posicion_i]<<")\t";
			tmp +=eval_char(data_c[i][posicion_j],data_f[j][posicion_i],match,mismatch,gap);
		}
	}
	return tmp;
}

int p_izquierda(vector<string> &data_f, vector<string>&data_c, int match, int mismatch, int gap, int posicion){
	int tmp=0;
	for (int i = 0; i < data_f.size(); ++i){
		for (int j = 0; j < data_c.size() ; ++j){
			//cout<<data_c[i][posicion]<<"\t"<<'-'<<endl;
			tmp +=eval_char(data_c[i][posicion],'-',match,mismatch,gap);
		}
	}
	return tmp;
}

int p_arriba(vector<string> &data_f, vector<string>&data_c, int match, int mismatch, int gap, int posicion){
	int tmp=0;
	for (int i = 0; i < data_f.size(); ++i){
		for (int j = 0; j < data_c.size() ; ++j){
			//cout<<"( - , "<<data_f[i][position]<<")\t";
			tmp +=eval_char('-',data_f[i][posicion],match,mismatch,gap);
		}
	}
	return tmp;
}

//agregar --- guiones
vector<string> agregar_guiones(vector<string> entrada){
	std::vector<string> v;
	for (int i = 0; i < entrada.size(); ++i){
		string cadena="-" + entrada[i];
		v.push_back(cadena);
	}
	return v;
}

//Funcion para agrega caracteres en la parte final de un string del vector
void add_char_vec(vector<string> &v, int posicion,  char c){
	v[posicion] += c;
}

// ALINEACION PARCIAL:

vector<string> alineacion_parcial(vector<string>data_f,vector<string>data_c, int mat, int mis, int gap ){
	vector<vector<float> > M;//Matriz de alineaciones 
	
	M.resize(data_f[0].size()+1);
	for (int i = 0; i < M.size(); ++i){
		M[i].resize(data_c[0].size()+1);
	}
	//agregamos guiones a todas las matrices
	vector<string> v_fila =agregar_guiones(data_f);
	vector<string> v_col =agregar_guiones(data_c);
	

	cout<<"\nMOSTRAR FILAS\n";
	for (int i = 0; i < v_fila.size(); ++i)
	{
		cout<<v_fila[i]<<endl;
	}
	cout<<"\nMOSTRAR COLs\n";
	for (int i = 0; i < v_col.size(); ++i)
	{
		cout<<v_col[i]<<endl;
	}
	//cout<<"\n\tPeso: "<<get_peso("TGTAAC","TGT-AC",mat,mis,gap)<<endl;
	
	//llenado de filas
	for (int i = 0; i < M.size(); ++i){
		M[i][0] =p_arriba(v_fila,v_col,mat,mis,gap,i);
	}
	//llenado de columnas
	for (int i = 0; i < M[0].size(); ++i){
		M[0][i] =p_izquierda(v_fila,v_col,mat,mis,gap,i);	
	}

	
	//llenado de la matriz a partir de la position 1
	vector<float> res;//resulado de diagonal,superior,izquierdo
	float diag,izq,sup,size_cad_f,size_cad_c;
	for (int i = 1; i < M.size(); ++i){
		for (int j = 1; j < M[0].size(); ++j){
			size_cad_f =v_fila.size();
			size_cad_c =v_col.size();
			float tam =1.0;
			tam =size_cad_c + size_cad_f;

			//int anterior_ =get_peso3(data[i_0][j-1],data[i_1][j-1],data[pos_fil][i-1],gap,mismatch);
			diag  =p_diagonal(v_fila,v_col,mat,mis,gap,i,j)/tam;
			izq   =p_izquierda(v_fila,v_col,mat,mis,gap,i)/tam;
			sup   =p_arriba(v_fila,v_col,mat,mis,gap,j)/tam;
			//get_peso3(data[i_0][j],data[i_1][j],data[pos_fil][i],gap,mismatch);
			//suma = M[i-1][j-1] + get_peso3(data[i_0][j],data[i_1][j],data[pos_fil][i-1],gap,mismatch);
			//cout<<"\nsuma ="<<data[i_0][j]<<","<<data[pos_fil][i]<<" + "<<data[i_1][j]<<","<<data[pos_fil][i-1]<<" = "<<suma<<endl;
			
			//cout<<"\nAnteior: "<<anterior_<<endl;
			//cout<<"\ndiagonal: "<<diagonal_<<endl;
			//suma =anterior_ + diagonal_;
			res.push_back( diag+ M[i-1][j-1]);//diagonal
			//cout<<"\n\tDiagonal: "<<diag<<" + "<< M[i-1][j-1]<<endl;
			
			res.push_back(sup + M[i-1][j]);//superior
			//cout<<"\tSuperior: "<<sup <<" + "<< M[i-1][j]<<endl;
			
			res.push_back(izq + M[i][j-1]);//izquierdo
			//cout<<"\tIzquierdo: "<<izq <<" + "<< M[i][j-1]<<endl;
			
			sort(res.begin(), res.end());
	/*		
			for (int i = 0; i < res.size(); ++i){
				cout<<res[i]<<"\t";
			}
			cout<<endl;
	*/
			M[i][j] = res[res.size()-1];//escogemos al mayor
			res.clear();
			diag=izq=sup=0;	
		}
	}
	//cout<<"\n*****************ERROR******\n";
	
/*
	//mostramos las matrices
	for (int i = 0; i < M.size(); ++i){
		for (int j = 0; j < M[i].size(); ++j){
			cout<<M[i][j]<<"\t";	
		}
		cout<<endl;
	}*/



	int i=M.size()-1;
	int j=M[0].size()-1;
	vector<string> result;//vector de cadenas resultantes;
	result.resize(v_fila.size() + v_col.size());
	size_cad_f =v_fila.size();
	size_cad_c =v_col.size();
	while(i>0 && j>0){
		float tam =1.0;
		tam =size_cad_c + size_cad_f;

		diag  =p_diagonal(v_fila,v_col,mat,mis,gap,i,j)/tam;
		izq   =p_izquierda(v_fila,v_col,mat,mis,gap,i)/tam;
		sup   =p_arriba(v_fila,v_col,mat,mis,gap,j)/tam;
	
		//cout<<"\n"<<i<<" : "<<j<<"\n";
		if(M[i][j] == (diag +M[i-1][j-1])){//diagonal
			//agregar columnas
			for (int k1 = 0; k1 < size_cad_c; ++k1)
			{
				result[k1] += v_col[k1][j];
			}
			//agregar filas
			for (int k2 = 0; k2 < size_cad_f; ++k2)
			{
				result[k2 + size_cad_c] +=v_fila[k2][i];
			}
			//alineados.push_back(make_pair(cad1[i-1],cad2[j-1]));
			i--;
			j--;
		}
		else if(M[i][j] ==(M[i-1][j] + sup)){//superior
			//agregar columnas
			for (int k1 = 0; k1 < size_cad_c; ++k1)
			{
				result[k1] += '-';
			}
			//agregar filas
			for (int k2 = 0; k2 < size_cad_f; ++k2)
			{
				result[k2 + size_cad_c] +=v_fila[k2][i];
			}
			//alineados.push_back(make_pair(cad1[i-1],'-'));
			i--;
		}
		else if(M[i][j] == (M[i][j-1] + izq)){//izquierda
			//agregar columnas
			for (int k1 = 0; k1 < size_cad_c; ++k1)
			{
				result[k1] +=v_col[k1][j];
			}
			//agregar filas
			for (int k2 = 0; k2 < size_cad_f; ++k2)
			{
				result[k2 + size_cad_c] += '-';
			}

			//alineados.push_back(make_pair('-',cad2[j-1]));
			j--;
		}
		else break;
	}
	if (i>0){
		//cout<<"\nValor i: "<<i<<endl;
		for (int i_1 = i; i_1 > 0; --i_1){

			//agregar columnas
			for (int k1 = 0; k1 < size_cad_c; ++k1){
				result[k1] += '-';
			}
			//agregar filas
			for (int k2 = 0; k2 < size_cad_f; ++k2){
				result[k2 + size_cad_c] +=v_fila[k2][i_1];
			}
			//alineados.push_back(make_pair(cad1[i-1],'-'));
			//i--;
			if(i==0) break;

		}
	}
	if(j>0){
		//cout<<"\nValor j: "<<j<<endl;
		for (int j_1 = j; j_1 > 0; --j_1){
			//agregar columnas
			for (int k1 = 0; k1 < size_cad_c; ++k1)
			{
				result[k1] += v_col[k1][j_1];
			}
			//agregar filas
			for (int k2 = 0; k2 < size_cad_f; ++k2)
			{
				result[k2 + size_cad_c] += '-';
			}

			//alineados.push_back(make_pair('-',cad2[j-1]));
		}
	}
	cout<<"\nMOSTRAR RESULTADOS:\n";
	for (int i = 0; i <result.size() ; ++i){
		reverse(result[i].begin(), result[i].end());
	}
	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<endl;
	}
	return result;

}


/// ALINEACION:

void alineacion(vector<string> data,int mat, int mis, int gap){
	pair<string, string> cads_n_w;
	float peso=0;
	//multimap<float, tuple<int, string, int, string> > resultados;
	multimap<float, pair<int, int> > result;


	for (int i = 0; i < data.size(); ++i){
		for (int j = i+1; j < data.size(); ++j){
			cout<<i<<","<<j<<endl;
			cads_n_w =alineacion_directa(data[i],data[j]);
			peso = sum_cadenas(cads_n_w.first, cads_n_w.second,mat,mis,gap)*1.0/(cads_n_w.first).size();
			cout<<"\t"<<cads_n_w.first<<endl;
			cout<<"\t"<<cads_n_w.second<<endl;
			cout<<"\tPeso: "<<peso<<endl;
			//resultados.insert(make_pair(peso, make_tuple(i,cads_n_w.first, j,cads_n_w.second)) );
			result.insert(make_pair(peso,make_pair(i,j)));
			//cout<<endl;
		}
	}
/*
	//Muestra resultados
	for (auto &it:resultados){
		tuple<int, string,int,string> t =(it.second);
	    cout<<get<0>(t) <<","<<get<2>(t) <<endl;
	    cout<<"\t"<<get<1>(t) <<endl;
	    cout<<"\t"<<get<3>(t) <<endl;
		cout<<"\tPeso:"<<(it).first<<endl;
	    cout<<endl;
	}
*/
	vector<pair<int,int> > v_position;
	std::multimap<float,pair<int,int> >::reverse_iterator it;
  	for (it=result.rbegin(); it!=result.rend(); ++it){
    //std::cout << it->first << " => " << it->second << '\n';
		/*
		cout<<(it->second).first<<","<<(it->second).second;
		cout<<"\tPeso: "<<it->first<<endl;
		cout<<endl;
		*/

		v_position.push_back(make_pair((it->second).first, (it->second).second));

	}
	ordenar_parejas(v_position, data.size());
	cout<<"\nRESULTADO 2\n";
	for (int i = 0; i < v_position.size(); ++i){
		cout<<v_position[i].first<<","<<v_position[i].second<<"\t";
	}
	cout<<endl;

	vector<vector<string> > all_alineacion;//contiene a todas las alineaciones
	//all_alineacion.resize(v_position.size());
	
	vector<string> vec;
	//alinearemos todos vs todos NW
	for (int i = 0; i < v_position.size(); ++i){
		cads_n_w =needleman_wunch(data[v_position[i].first], data[v_position[i].second]);
		vec.push_back(cads_n_w.first);
		if(cads_n_w.first != cads_n_w.second )//si no se repiten agrego
			vec.push_back(cads_n_w.second);
		
		all_alineacion.push_back(vec);
		vec.clear();
	}
	vec.clear();
	//mostrar todas las all_alineaciones
	for (int i = 0; i < all_alineacion.size(); ++i){
		cout<<"\n"<<i<<endl;
		vec =all_alineacion[i];
		for (int j = 0; j < vec.size(); ++j){
			cout<<"\t"<<vec[j]<<endl;
		}
		cout<<endl;
	}


	vec.clear();
	vec =all_alineacion[0];//el ultimo elemento por el pusch_back
	cout<<"\nTamanio_all_alineaciones: "<<all_alineacion.size()<<endl;
	int i = 1;
	for (int i = 1; i < all_alineacion.size(); ++i){
		vec = alineacion_parcial(all_alineacion[i],vec,mat,mis,gap);
	}
	//vec = alineacion_parcial(all_alineacion[i],vec,mat,mis,gap);
	
/*	for (int i = all_alineacion.size()-2; i >=0; ++i){
		alineacion_parcial(vec, all_alineacion[i],mat,mis,gap);
	}
*/
}



int main(){
    vector<string> entrada;
    entrada.push_back("TGTTAAC");
    entrada.push_back("TGTAAC");
    entrada.push_back("TGTAC");
    entrada.push_back("ATGTC");
    entrada.push_back("ATGTGGC");

    int match = 2;
    int mismatch = 1;
    int gap = 0;

    cout<<"www"<<endl;
    //cout<<sum_cadenas("TGTTAAC","TGTAAC-",2,1,0);
    //cout<<eval_char('a','c',2,1,0);
    alineacion(entrada,match,mismatch,gap);
    return 0;
}


// g++ -std=c++11 bio13.cpp -o a
// ./a