//
// Created by zhoujie on 2022/4/24.
//高精度加法
#include<bits/stdc++.h>
using namespace std;
vector<int> add(vector<int> &A ,vector<int> &B){
    int t = 0;
    vector<int> C;
    for(int i = 0 ; i < A.size() || i < B.size() ; ++i){
        if(i<A.size()) t += A[i];
        if(i<B.size()) t += B[i];
        C.push_back(t%10);
        t /= 10;
    }
    if(t) C.push_back(t);
    return C;
}
int main(){
    string a,b;
    vector<int> A;
    vector<int> B;
    cin >> a >> b;
    for(int i = 0;i < a.size() ; ++ i) A.push_back(a[i] - '0');
    for(int i = 0;i < b.size() ; ++ i) B.push_back(b[i] - '0');

    auto C = add(A,B);

    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

    return 0;
}