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
            
            //cout<<"valor de S:"<<endl;
            //return S;
            //cout<<"que fue"<<endl;
        }
        cout<<" "<<endl;    
        //cout<<"valor de S:"<<endl;
        //return S;
    }
    //resultado que quiero
    cout<<"valor de S:"<<endl;
    return dp[n][m];
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

void matrix_step1(){
    
    match_score = 1, mismatch_score = 1, gaps = 2;
    vector <string> S;
    
    string S1 = "CCTGCTGCAG";
    string S2 = "GATGTGCCG";
    string S3 = "GATGTGCAG";
    string S4 = "CCGCTAGCAG";
    string S5 = "CCTGTAGG";

    S.push_back(S1);
    S.push_back(S2);
    S.push_back(S3);
    S.push_back(S4);
    S.push_back(S5);


    int m_step1[S.size()][S.size()];
    for(int i=0;i<S.size();i++){
        for(int j=0;j<S.size();j++){
            A = S[i];
            B = S[j];
            n=A.size();
            m=B.size();
            if(i==j){
                m_step1[i][j]=0;
            }else{
                cout<<"valor de A:  "<<A<<endl;
                cout<<"valor de B:  "<<B<<endl;
                m_step1[i][j] = needleman_wunsch();
                pair<string, string> alignment = get_optimo();
                cout<<alignment.first.c_str()<<endl;
                cout<<alignment.second.c_str()<<endl;;
            }
        }
        cout<<endl;
    }

    //imprime la matrix
    cout<<endl;
    cout<<"que tiene la matrix STEP_1:"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<m_step1[i][j]<<"  ";
        }
        cout<<endl;
    }

    //paso 2:
    cout<<endl;
    vector <int> sumas;
    cout<<"sumas:"<<endl;
    for(int i=0;i<S.size();i++){    
        int suma = 0;
        for(int j=0;j<S.size();j++){
            suma = m_step1[i][j] + suma;
        }
        sumas.push_back(suma);
        cout<<suma<<endl;
    }

    //paso 2.1:
    
    cout<<endl;
    int mayor = *max_element(sumas.begin(),sumas.end());
    int mayor_posicion;
    for(int i=0;i<sumas.size();i++){
        if(mayor == sumas[i])
            mayor_posicion=i;
    }
    cout<<"MAYOR"<<endl;
    cout<<mayor<<endl;
    cout<<"mayor_posicion"<<endl;
    cout<<mayor_posicion<<endl;

   
    //paso 3:

    cout<<"================================="<<endl;
    cout<<"PASO 3:"<<endl;
    cout<<"================================="<<endl;
    vector <string> string_finales_1;
    vector <string> string_finales_2;
    for(int j=0;j<S.size();j++){
        A = S[mayor_posicion];
        B = S[j];
        n = A.size();
        m = B.size();
        needleman_wunsch();
        pair<string, string> alignment = get_optimo();
        cout<<alignment.first.c_str()<<endl;
        cout<<alignment.second.c_str()<<endl;
        string_finales_1.push_back(alignment.first.c_str());
        string_finales_2.push_back(alignment.second.c_str());

    }
    cout<<"=============="<<endl;
    cout<<"STRING FINALES:"<<endl;
    cout<<"==============="<<endl;
    cout<<string_finales_1[0]<<endl;
    cout<<string_finales_1[1]<<endl;
    cout<<string_finales_1[2]<<endl;
    cout<<string_finales_1[3]<<endl;
    cout<<string_finales_1[4]<<endl;
    cout<<"=============="<<endl;
    cout<<"STRING FINALES:"<<endl;
    cout<<"==============="<<endl;
    cout<<string_finales_2[0]<<endl;
    cout<<string_finales_2[1]<<endl;
    cout<<string_finales_2[2]<<endl;
    cout<<string_finales_2[3]<<endl;
    cout<<string_finales_2[4]<<endl;

    //paso 4:

    cout<<"================================="<<endl;
    cout<<"PASO 4:"<<endl;
    cout<<"================================="<<endl;
    
    int t=0;
    vector <int> pesitos;
    for(int x=0;x<string_finales_1.size();x++){
        t = string_finales_1[x].size();
        pesitos.push_back(t);
    }
  
    
    int mayor_peso = *max_element(pesitos.begin(),pesitos.end());
    int mayor_peso_pos;
    for(int i=0;i<pesitos.size();i++){
        if(mayor_peso==pesitos[i])
            mayor_peso_pos = i;
    }

    cout<<"amyor:"<<string_finales_1[mayor_peso_pos]<<endl;

    vector <string> finals;
    for(int i=0;i<string_finales_2.size();i++){
        A = string_finales_1[mayor_peso_pos];
        B = string_finales_2[i];
        n = A.size();
        m = B.size();
        needleman_wunsch();
        pair<string, string> fi = get_optimo();
        cout<<fi.first.c_str()<<endl;
        cout<<fi.second.c_str()<<endl;
        finals.push_back(fi.second.c_str());
    }
    
    cout<<"=============="<<endl;
    cout<<"STRING FINALES:"<<endl;
    cout<<"==============="<<endl;
    cout<<finals[0]<<endl;
    cout<<finals[1]<<endl;
    cout<<finals[2]<<endl;
    cout<<finals[3]<<endl;
    cout<<finals[4]<<endl;
    

    
}


int main()
{
    /*
    match_score = 1, mismatch_score = 1, gaps = 2;
    A = "CCTGCT-GCAG";
    B = "CC-GCTAGCAG";
    n=A.size();
    m=B.size();
    
    
    printf("%d\n",needleman_wunsch());
    pair<string, string> alignment = get_optimo();
    
    printf("%s\n%s\n", alignment.first.c_str(), alignment.second.c_str());
    */
    matrix_step1();
    return 0;
}


