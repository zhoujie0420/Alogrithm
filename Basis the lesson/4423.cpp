//
// Created by ZhouJie on 2022/5/23 9:20.
//给定一个长度为 n 的整数数组 a1,a2,…,an。
//
//对于每个整数 i（1≤i≤n），请你找到一个整数 j，要求：
//
//1≤j≤n
//aj=0
//在满足以上两个条件的情况下，|i−j| 应尽可能小。|i−j| 的最小可能值不妨用 bi 来表示。
//请你计算并输出 b1,b2,…,bn。
//
//保证给定数组中一定存在 0。
//
//输入格式
//第一行包含整数 n。
//
//第二行包含 n 个整数 a1,a2,…,an。
//
//输出格式
//一行，n 个整数 b1,b2,…,bn。
//
//数据范围
//前 4 个测试点满足 1≤n≤10。
//所有测试点满足 1≤n≤2×105，−109≤ai≤109。
//
//输入样例1：
//9
//2 1 0 3 0 0 3 2 4
//输出样例1：
//2 1 0 1 0 0 1 2 3

#include <bits/stdc++.h>

using namespace std;
const int N  = 20010;
int a[N];
int b[N];
int n ;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int flag  = 1e9;
    for (int i = 0; i < n; ++i) {
        if(a[i] == 0) {
            flag = 0;
        }else{
            a[i] = min(abs(a[i]), ++flag);
        }
    }

    for (int i = n-1; i > -1; --i) {
        if(a[i] == 0) {
            flag = 0;
        }else{
            a[i] = min(abs(a[i]), ++flag);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i]  << " ";
    }
    return 0;
}