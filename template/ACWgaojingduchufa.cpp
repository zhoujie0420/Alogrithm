//
// Created by zhoujie on 2022/4/28.
//高精度除法
#include "bits/stdc++.h"
using namespace std;

vector<int>div(vector<int >&A , int b , int &r){
    vector<int> C;
     r = 0;
    for(int i = A.size() -1 ; i >= 0;--i){
        r = r*10 +A[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(),C.end());
    while(C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

int main(){
    string a ;
    int b;
    cin >> a >> b;
    vector<int> A;
    int r ;
    for(int i =a.size() -1  ; i >= 0 ;--i) A.push_back(a[i] - '0');

    auto C = div(A,b,r);
    for(int i = C.size() -1 ;i >=0 ;--i) cout << C[i] ;
    cout << endl << r ;
    return 0;
}