#include<bits/stdc++.h>
using namespace std ;

int LCS(string a,string b){
    int m = a.length() ;
    int n = b.length() ;
    
    int lcs[m + 1][n + 1];  
 
    for (int i = 0; i <= m; i++)  
    {  
        for (int j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            lcs[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            lcs[i][j] = lcs[i - 1][j - 1] + 1;  
      
        else
            lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);  
        }  
    }  
          
    /* lcs[m][n] contains length of LCS  
    for X[0..n-1] and Y[0..m-1] */
    return lcs[m][n];
}

int main(){
    string str1,str2 ; 
    cout << "Take two strings to find their LCS\n";
    cin >> str1 >> str2 ; 
    cout << "Length of LCS is " 
         << LCS( str1 , str2 ); 

    return 0 ;     
}