//
// Created by ZhouJie on 2022/5/5 17:28.
//模拟单链表

#include <bits/stdc++.h>

using namespace std;
const int N = 10005;

int head;
int e[N];
int ne[N];
int idx;
void init(){
    head = -1;
    idx = 0;
}

void add_to_head(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

void add(int k ,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

void remove(int k){
    ne[k] = ne[ne[k]];

}

int main() {


    return 0;
}