//
// Created by ZhouJie on 2022/5/28 21:59.
//给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
//
//请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。
//
//注意：图中可能 存在负权回路 。
//
//输入格式
//第一行包含三个整数 n,m,k。
//
//接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
//
//输出格式
//输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。
//
//如果不存在满足条件的路径，则输出 impossible。
//
//数据范围
//1≤n,k≤500,
//1≤m≤10000,
//任意边长的绝对值不超过 10000。
//
//输入样例：
//3 3 1
//1 2 1
//2 3 1
//1 3 3
//输出样例：
//3

#include <bits/stdc++.h>

using namespace std;
const int N = 505 , M = 10010;
int n , m ,k;
int dist[N];   //记录原点到其他n点的距离
int backup[N];  // 备份
struct Edge{
    int a,b,w;
}edge[M];

void bellman_ford(){
    memset(dist,0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; ++i) {
        memcpy(backup,dist,sizeof dist);
        for (int j = 0; j < m; ++j) {
            int a = edge[j].a;
            int b = edge[j].b;
            int w = edge[j].w;
            dist[b] = min(dist[b],backup[a]+w);   //这里一定要用backup备份的数组来看 不然会出现连续调用
        }
    }

}
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a,b,w;
        cin >> a >>b >> w;
        edge[i] = {a, b, w};
    }
    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else cout << dist[n];
    return 0;
}