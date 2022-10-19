//
// Created by ZhouJie on 2022/5/10 21:56.
//给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。
//
//最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
//
//请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。
//
//数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。
//
//输入格式
//第一行包含两个整数 n 和 m。
//
//接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。
//
//输出格式
//输出一个整数，表示从左上角移动至右下角的最少移动次数。
/*
dfs{
    队列初始话
    while(队列不为空) // 当队列为空时 说明已经回到了刚开始的位置 即没有可以寻找的路
{
        auto t = 队头元素
                且需要弹出队头元素不然会重复
                拓展t进行操作
}
};

 */
#include <bits/stdc++.h>

using namespace std;
const int N = 10006;
int n , m;
typedef pair<int,int> PII;
queue<PII> q;
int g[N][N];
int d[N][N];

vector<int> prev;
//记录路径

int bfs(){
    q.push({0,0});
    memset(d,-1,sizeof d);
    d[0][0] = 0;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = t.first+dx[i];
            int y = t.second+dy[i];
            if(x >= 0 && x < n && y>=0  && y < m && g[x][y] == 0 && d[x][y] == -1){
                d[x][y] = d[t.first][t.second] + 1;

                q.push({x,y});
            }
        }
    }

    return d[n-1][m-1];

}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j] ;
        }
    }
    cout << bfs() << endl;
    return 0;
}