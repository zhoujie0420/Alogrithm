//
// Created by ZhouJie on 2022/5/6 10:44.
//单调队列

#include <bits/stdc++.h>

using namespace std;
const int N = 100006;
int n,k;
int a[N],q[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int hh = 0 , tt = -1;
    for (int i = 0; i < n; ++i) {
        // 判断是否已经滑出窗口
        if(hh <= tt && i-k+1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] > a[i] ) tt--;
        q[++tt] = i;
        if(i >=k-1) cout << a[q[hh]] << " ";
    }
    return 0;
}