#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <tuple>

#define MAX_N 1001

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int n, m;
int match_score, mismatch_score, gaps;
string A, B;
int dp[MAX_N][MAX_N];


inline int needleman_wunsch(){
    //int S;
    for (int i=0;i<=n;i++) dp[i][0] = dp[0][i] = -i * gaps;
    
    for (int i=1;i<=n;i++)
    {
        
        for (int j=1;j<=m;j++)
        {
            int S = (A[i-1] == B[j-1]) ? match_score : -mismatch_score;
            dp[i][j] = max(dp[i-1][j-1] + S, max(dp[i-1][j] - gaps, dp[i][j-1] - gaps));
            cout<<dp[i][j]<<"  ";
        }
        cout<<" "<<endl;    
    }
    cout<<"valor de S:"<<endl;
    return abs(dp[n][m]);
    cout<<endl;    
}

inline pair<string, string> get_optimo()
{
    string retA, retB;
    stack<char> SA, SB;
    int ii = n, jj = m;
    while (ii != 0 || jj != 0)
    {
        if (ii == 0)
        {
            SA.push('-');
            SB.push(B[jj-1]);
            jj--;
        }
        else if (jj == 0)
        {
            SA.push(A[ii-1]);
            SB.push('-');
            ii--;
        }
        else
        {
            int S = (A[ii-1] == B[jj-1]) ? match_score : -mismatch_score;
            if (dp[ii][jj] == dp[ii-1][jj-1] + S)
            {
                SA.push(A[ii-1]);
                SB.push(B[jj-1]);
                ii--; jj--;
            }
            else if (dp[ii-1][jj] > dp[ii][jj-1])
            {
                SA.push(A[ii-1]);
                SB.push('-');
                ii--;
            }
            else
            {
                SA.push('-');
                SB.push(B[jj-1]);
                jj--;
            }
        }
    }
    while (!SA.empty())
    {
        retA += SA.top();
        retB += SB.top();
        SA.pop();
        SB.pop();
    }
    return make_pair(retA, retB);
}

void TPS(vector <string> a){

    match_score = 0, mismatch_score = 3, gaps = 2;

    //llenado de las cadenas en mi vector cadenas:
    vector <pair<int, string>> cadenas; // creo mi vetor donde voy a almacenas las cadenas

    cadenas.push_back(make_pair(1,a[0])); //llenar
    cadenas.push_back(make_pair(2,a[1])); //llenar
    cadenas.push_back(make_pair(3,a[2])); //llenar

    for(int i=0;i<cadenas.size();i++){
        cout<<get<0>(cadenas[i])<<" , "<<get<1>(cadenas[i])<<endl;
    }

    // Hacer las comparaciones y voy a obtener los pesos:
    int valor; // en esta variable voy a almacenar el peso de NW
    multimap<int, tuple<string, int, string, int>> cad; // en este multimap voy a guardar peso, y tupla...

    for(int i=0;i<cadenas.size();i++){
        for(int j=i+1;j<cadenas.size();j++){
            A = cadenas[i].second;
            B = cadenas[j].second;
            n = A.size();
            m = B.size();
            valor = needleman_wunsch();
            pair<string, string> alignment = get_optimo();
            cout<<alignment.first.c_str()<<endl;
            cout<<alignment.second.c_str()<<endl;

            // Voy a guardar en mi tupla (Peso, Cadena 1, indixe 1, Cadena 2, Indixe 2):
    
            
            cad.insert(make_pair(valor,make_tuple(A,i,B,j)));

        }
    }
                        
    cout<<"====================="<<endl;         
    for(const auto& i : cad){
        cout<< get<0>(i)<<get<1>(i)<<get<2>(i)<<get<3>(i)<<endl;
    }
    cout<<"====================="<<endl;

    



    
    
    


    
}


int main()
{
    /*
    match_score = 1, mismatch_score = 1, gaps = 2;
    A = "CCTGCTGCAG";
    B = "GATG-TGCCG";
    n=A.size();
  entradas.push_back(a);  m=B.size();
    
    
    printf("%d\n",needleman_wunsch());
    pair<string, string> alignment = get_optimo();
    
    printf("%s\n%s\n", alignment.first.c_str(), alignment.second.c_str());
    */
    vector <string> cadenas_ingreso;

    string a = "ACTCAT";
    string b = "AGTCAT";
    string c = "ACGTCCT";// 

    cadenas_ingreso.push_back(a);
    cadenas_ingreso.push_back(b);
    cadenas_ingreso.push_back(c);

    TPS(cadenas_ingreso);
    return 0;
}


// g++ -std=c++11 your_file.cpp -o a
// ./a