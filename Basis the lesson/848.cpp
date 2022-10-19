//
// Created by ZhouJie on 2022/6/8.
//给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。
//
//请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。
//
//若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。
//
//输入格式
//第一行包含两个整数 n 和 m。
//
//接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。
//
//输出格式
//共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。
//
//否则输出 −1。
//
//数据范围
//1≤n,m≤105
//输入样例：
//3 3
//1 2
//2 3
//1 3
//输出样例：
//1 2 3

#include <bits/stdc++.h>

using namespace std;
const int N = 10010;
int n , m;
vector<list<int>> g(N);
queue<int> q;
vector<int> res;
int cnt[N]; //  表示的i的入度
int main() {
    cin >> n >> m;
    while(m--){
        int a,b ;
        cin >>a >> b;
        g[a].push_back(b);
        cnt[b] ++ ;
    }
    for (int i = 1; i <=n; ++i) {
        if(cnt[i] == 0) {
            q.push(i);
        }
    }
    while(q.size()>0){
        int t = q.front();
        res.push_back(t);
        q.pop();
        for(auto s : g[t]){
            cnt[s]--;
            if(cnt[s] == 0) {
                q.push(s);
            }
        }
    }

    if(res.size() != n){
        cout << -1 ;
        return 0;
    } else
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << " ";
        }

    return 0;
}