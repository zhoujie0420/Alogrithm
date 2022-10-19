//
// Created by ZhouJie on 2022/5/5 17:39.
//模拟双链表

#include <bits/stdc++.h>

using namespace std;
const int N = 10006;

int m;
int e[N];
int l[N];
int r[N];
int idx;
void init(){
    r[0] = 1 ,l[1] = 0;
    idx = 2;
}

void add (int k ,int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
}
void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main() {

    return 0;
}