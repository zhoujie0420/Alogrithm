//
// Created by ZhouJie on 2022/4/28.
//二位差分

#include "bits/stdc++.h"
using namespace std;
const int N = 10005;
int n , m;
int a[N],b[N];

void insert(int l, int r,int c){
    b[l] +=c;
    b[r+1] -=c;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n ; ++i) insert(i,i,a[i]);

    while(m--){
        int l, r, c;
        cin >> l >> r >> c;
        insert(l,r,c);

    }
    for (int i = 1; i <= n ; ++i) b[i]+=b[i-1];
    for (int i = 1; i <=n ; ++i) cout << b[i] << " ";
        
return 0;
}