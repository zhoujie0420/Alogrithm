//
// Created by ZhouJie on 2022/5/29 20:52.
//给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。
//
//再给定 k 个询问，每个询问包含两个整数 x 和 y，表示查询从点 x 到点 y 的最短距离，如果路径不存在，则输出 impossible。
//
//数据保证图中不存在负权回路。
//
//输入格式
//第一行包含三个整数 n,m,k。
//
//接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
//
//接下来 k 行，每行包含两个整数 x,y，表示询问点 x 到点 y 的最短距离。
//
//输出格式
//共 k 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 impossible。
//
//数据范围
//1≤n≤200,
//1≤k≤n2
//1≤m≤20000,
//图中涉及边长绝对值均不超过 10000。
//
//输入样例：
//3 3 2
//1 2 1
//2 3 2
//1 3 1
//2 1
//1 3
//输出样例：
//impossible
//1

#include <bits/stdc++.h>

using namespace std;
const int N = 210;
const int INF = 1e9;
int n , m , q;
int g[N][N];       // 表示某个节点到某个节点的最短距离
void floyd(){
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n ; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = min(g[i][j] ,g[i][k] + g[k][j]);
            }
        }
    }
}
int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(i ==j ) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
    while(m--){
        int a , b, w;
        cin  >> a >> b >> w;
        g[a][b] = min(g[a][b] ,w);
    }

    floyd();
    while(q--){
        int a,b;
        cin >> a >> b;
        if(g[a][b] > INF/2 ) cout << "impossible" << endl;
        else cout << g[a][b] << endl;
    }
    return 0;
}