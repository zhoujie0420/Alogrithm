//
// Created by ZhouJie on 2022/5/29 14:19.
// 给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
//
//请你判断图中是否存在负权回路。
//
//输入格式
//第一行包含整数 n 和 m。
//
//接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
//
//输出格式
//如果图中存在负权回路，则输出 Yes，否则输出 No。
//
//数据范围
//1≤n≤2000,
//1≤m≤10000,
//图中涉及边长绝对值均不超过 10000。
//
//输入样例：
//3 3
//1 2 -1
//2 3 4
//3 1 -4
//输出样例：
//Yes

#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n;
int m;
typedef pair<int,int> PII;
vector<list<PII>> g;            //这里用邻接表存储，稀疏图  其中对于g而言相当二维数组其中二维坐标表示的pair类型 first代表目标结点，second代表的权值
int dist[N];                      //到第n个结点的距离
bool st[N];                      //表示是否在队列中  避免重复判断  没有这个标记数组其实也没有问题 为了降低时间复杂度而已
int cnt[N];                     //表示的是到达这个节点需要多少条路

bool spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;

    queue<int >q ;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    while(q.size()){     //当队列中 没有元素时 停止遍历  这里使用bfs
        int t = q.front();
        q.pop();
        st[t] = false;   //表示t 这个节点已经处理过

        for (auto li : g[t]) {
            int j = li.first;
            int distance = li.second;
            if(dist[j] > dist[t] + distance){
                dist[j] = dist[t] + distance;
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;


}
int main() {
    cin >> n >> m;
    g.resize(n+1);        //这里一定要开g的大小不然无法存储，可以直接在定义时开N的大小
    while(m--){
        int a , b , c ;
        cin >> a >> b >>c;
        g[a].push_back({b,c});
    }

    if(spfa()) cout << "Yes";
    else cout << "No";
    return 0;
}