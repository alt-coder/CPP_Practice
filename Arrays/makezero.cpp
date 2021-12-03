#include <bits/stdc++.h>
using namespace std;
void makecolZero(vector<vector<int>> &A,int x){
    int m = A.size();
    int n = A[0].size();
    
        for(int i =0 ; i < m; i++){

        A[i][x]=0;
    }

}
void makerowZero(vector<vector<int>> &A,int x){
    int m = A.size();
    int n = A[0].size();

    {
        for(int i =0 ; i < n; i++){
        A[x][i] = 0;

    }

    }
  
}


void setZeroes(vector<vector<int> > &A) {
       int m = A.size();
       if(m==0) return ;
       
    int n = A[0].size();
    vector<bool> row(m,false);
    vector<bool>check(n,false);
    for(int i =0; i < m; i++){
        for(int j =0; j < n;j++){
            if(A[i][j]==0){
                check[j] = true;
                row[i]=true;
                //break;
            }
        }
    }
    
    for(int i =0; i < check.size(); i++)
        if(check[i]) makecolZero(A,i);
    for(int i =0; i < row.size(); i++)
        if(row[i]) makerowZero(A,i);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main(){
vector<vector<int>>A(3,vector<int>(3,1));
A[0][1]=0;
for(auto s:A){
    for(auto a:s){
        cout << a <<" ";
    }
    cout <<"\n";
}
setZeroes(A);
for(auto s:A){
    for(auto a:s){
        cout << a <<" ";
    }
    cout <<"\n";
}
}