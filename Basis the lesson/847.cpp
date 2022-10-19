//
// Created by ZhouJie on 2022/6/7.
//给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。
//
//所有边的长度都是 1，点的编号为 1∼n。
//
//请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 −1。
//
//输入格式
//第一行包含两个整数 n 和 m。
//
//接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。
//
//输出格式
//输出一个整数，表示 1 号点到 n 号点的最短距离。
//
//数据范围
//1≤n,m≤105
//输入样例：
//4 5
//1 2
//2 3
//3 4
//1 3
//1 4
//输出样例：
//1

#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n ,m;
vector<list<int>> g(N);
bool visted[N];
int dist[N];  //表示的是当前i号点到起点的距离
int main() {
    cin >> n >> m;
    while(m--){
        int a , b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    queue<int> q;
    memset(dist , -1, sizeof dist);
    dist[1] = 0;
    q.push(1);
    while(q.size() > 0){
        int t = q.front();
        q.pop();

        for(auto num : g[t]){
            if(dist[num] == -1) {
                dist[num] = dist[t] + 1;
                q.push(num);
            }
        }
    }

    cout << dist[n];
    return 0;
}











