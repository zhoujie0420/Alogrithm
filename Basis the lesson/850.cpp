//
// Created by ZhouJie on 2022/5/28 9:04.
//给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。
//
//请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。
//
//输入格式
//第一行包含整数 n 和 m。
//
//接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
//
//输出格式
//输出一个整数，表示 1 号点到 n 号点的最短距离。
//
//如果路径不存在，则输出 −1。
//
//数据范围
//1≤n,m≤1.5×105,
//图中涉及边长均不小于 0，且不超过 10000。
//数据保证：如果最短路存在，则最短路的长度不超过 109。
//
//输入样例：
//3 3
//1 2 2
//2 3 1
//1 3 4
//输出样例：
//3

#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n;
int m;
typedef pair<int,int> PII;
vector<list<PII>> g;            //这里用邻接表存储，稀疏图  其中对于g而言相当二维数组其中二维坐标表示的pair类型 first代表目标结点，second代表的权值
int dist[N];                      //到第n个结点的距离
bool st[N];                      //表示第n个结点是否被修改过

int Dijkstra(){
    memset(dist,0x3f,sizeof dist);  //定义所有的边长都为正无穷
    dist[1] = 0;                                 //定义自身结点到1的距离为0；
    priority_queue<PII,vector<PII>,greater<PII>> heap;   // 定义一个pair类型的小根队  其中first为距离，second为节点编号
    heap.push({0,1});

    while(heap.size()){
        auto t = heap.top();    //取出到源节点距离最小的节点位置
        heap.pop();

        int node = t.second;

        if(st[node]) continue; //如果该节点被修改过，跳过
        st[node] = true;       //不然的话将其标记已修改 并对其进行以下操作

        for (auto li : g[node]) {
            int newnode = li.first;
            int w = li.second;
            if(dist[newnode] > dist[node] + w){
                dist[newnode] = dist[node] + w;
                heap.push({dist[newnode] ,newnode});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
int main() {
    cin >> n >> m;
    g.resize(n+1);        //这里一定要开g的大小不然无法存储，可以直接在定义时开N的大小
    while(m--){
        int a , b , c ;
        cin >> a >> b >>c;
        g[a].push_back({b,c});
    }

    cout << Dijkstra() << endl;
    return 0;
}