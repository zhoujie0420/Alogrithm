//
// Created by ZhouJie on 2022/5/7 22:07.
//维护一个集合，支持如下几种操作：
//
//I x，插入一个数 x；
//Q x，询问数 x 是否在集合中出现过；
//现在要进行 N 次操作，对于每个询问操作输出对应的结果。
//
//输入格式
//第一行包含整数 N，表示操作数量。
//
//接下来 N 行，每行包含一个操作指令，操作指令为 I x，Q x 中的一种。
//
//输出格式
//对于每个询问指令 Q x，输出一个询问结果，如果 x 在集合中出现过，则输出 Yes，否则输出 No。
//
//每个结果占一行。



//拉链法
/*
#include <bits/stdc++.h>

using namespace std;
const int N = 100003; //  这里取mod的值一般取质数且离2的整次方最近；

int h[N], e[N], ne[N], idx;
void insert(int x){
    int k = (x % N + N)%N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x){
    int k = (x % N + N)%N;
    for (int i = h[k];i != -1; i = ne[i]) {
        if(e[i] == x) {
            return true;
        }

    }
    return false;
}
int main() {
    int n ;
    cin >> n;
    memset(h,-1,sizeof h);
    while(n--){
        char op[2];
        int x;
        cin >> op >> x;
        if(*op == 'I') insert(x);
        else {
            if(find(x)) cout << "yes"<< endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
*/

//开放寻址法

/*
#include <bits/stdc++.h>

using namespace std;
const int N = 200003 , null = 0x3f3f3f3f;//这里一般开的数组都是题目给的两到三倍

int h[N];
int find(int x){
    int k = (x%N+N)%N;
    while(h[k]!= null && h[k] != x){
        k++;
        if(k == N) return 0;
    }
    return k;
}

int main(){
    int n;
    cin >> n;
    memset(h,0x3f,sizeof h);
    while(n--){
        char op[2];
        int x;
        cin >> op >> x;
        int k = find(x);
        if(*op == 'I') h[k] = x;
        else {
            if(h[k] !=null) cout << "Yes"<< endl;
            else cout << "No" << endl;
        }
    }
}
*/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5+5,P = 131;//131 13331
ULL h[N],p[N];

// h[i]前i个字符的hash值
// 字符串变成一个p进制数字，体现了字符+顺序，需要确保不同的字符串对应不同的数字
// P = 131 或  13331 Q=2^64，在99%的情况下不会出现冲突
// 使用场景： 两个字符串的子串是否相同
ULL query(int l,int r){
    return h[r] - h[l-1]*p[r-l+1];
}
int main(){
    int n,m;
    cin>>n>>m;
    string x;
    cin>>x;

    //字符串从1开始编号，h[1]为前一个字符的哈希值
    p[0] = 1;
    h[0] = 0;
    for(int i=0;i<n;i++){
        p[i+1] = p[i]*P;
        h[i+1] = h[i]*P +x[i];      //前缀和求整个字符串的哈希值
    }

    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(query(l1,r1) == query(l2,r2)) printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
