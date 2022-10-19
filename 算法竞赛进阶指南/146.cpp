//
// Created by ZhouJie on 2022/7/21.
//给定 m 个序列，每个包含 n 个非负整数。
//
//现在我们可以从每个序列中选择一个数字以形成具有 m 个整数的序列。
//
//很明显，我们一共可以得到 nm 个这种序列，然后我们可以计算每个序列中的数字之和，并得到 nm 个值。
//
//现在请你求出这些序列和之中最小的 n 个值。
//
//输入格式
//第一行输入一个整数 T，代表输入中包含测试用例的数量。
//
//接下来输入 T 组测试用例。
//
//对于每组测试用例，第一行输入两个整数 m 和 n。
//
//接下在 m 行输入 m 个整数序列，数列中的整数均不超过 10000。
//
//输出格式
//对于每组测试用例，均以递增顺序输出最小的 n 个序列和，数值之间用空格隔开。
//
//每组输出占一行。
//
//数据范围
//0<m≤1000,
//0<n≤2000
//输入样例：
//1
//2 3
//1 2 3
//2 2 3
//输出样例：
//3 3 4

#include <bits/stdc++.h>

using namespace std;
const int N = 2010;
typedef pair<int,int > PII;
int t;
int n , m;
int a[N],b[N],c[N];
void merge(){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for (int i = 0; i < n; ++i)  heap.push({a[0]+b[i],0});

    for (int i = 0; i < n; ++i){
        int s = heap.top().first;
        int p = heap.top().second;
        heap.pop();
        c[i] = s;

        heap.push({s-a[p]+a[p+1],p+1});
    }
    for (int i = 0; i < n; ++i) a[i] = c[i];
}
int main() {
    cin >> t;
    while(t --){
        cin >> m >> n;
        for (int i = 0; i < n; ++i)  cin >> a[i];

        sort(a,a+n);



        for (int i = 0; i < m-1; ++i){
            for (int j = 0; j < n; ++j)  cin >> b[j];

            merge();
        }

        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        puts("");
    }
    return 0;
}