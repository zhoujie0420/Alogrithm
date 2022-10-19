//////
////// Created by ZhouJie on 2022/5/13 13:27.
////
//////Dijkstra
/////*
//#include <bits/stdc++.h>
//using namespace std;
//int n,m;
//const int N = 510;
//int dist[N]; //定义到起点的最小值
//bool st[N]; //判断是否确定为最小距离
//int g[N][N];
//int Dijkstra(){
//    memset(dist,0x3f,sizeof dist);
//    dist[1] = 0;
//    for (int i = 0; i < n; ++i) {
//        int t = -1;
//        for (int j = 1; j <= n ; ++j) {
//            if(!st[j] && (t == -1||dist[t] > dist[j])) { // 找未确定最短距离的最小值
//                t = j;
//            }
//        }
//        st[t] = true;
//        for (int j = 1; j <= n ; ++j) {
//            dist[j] = min(dist[j] , dist[t] + g[t][j]);
//        }
//    }
//    if(dist[n] == 0x3f3f3f3f) return -1;
//    else return dist[n];
//}
//
////int main() {
////    cin >> n >> m;
////    memset(g, 0x3f ,sizeof g);
////    while(m --){
////        int a , b, c ;
////        cin >> a >> b >> c;
////        g[a][b] = min(g[a][b],c);//题目定义了存在重复边和自环 ，这里维护g为最小值；
////    }
////
////    cout << Dijkstra() << endl;
////
////    return 0;
////}
////*/
////堆优化Dijkstra
//#include <bits/stdc++.h>
//using namespace std;
//const int N = 100010;
//int n;
//int m;
//typedef pair<int,int> PII;
//vector<list<PII>> g;            //这里用邻接表存储，稀疏图  其中对于g而言相当二维数组其中二维坐标表示的pair类型 first代表目标结点，second代表的权值
//int dist[N];                      //到第n个结点的距离
//bool st[N];                      //表示第n个结点是否被修改过
//
//int Dijkstra(){
//    memset(dist,0x3f,sizeof dist);  //定义所有的边长都为正无穷
//    dist[1] = 0;                                 //定义自身结点到1的距离为0；
//    priority_queue<PII,vector<PII>,greater<PII>> heap;   // 定义一个pair类型的小根队  其中first为距离，second为节点编号
//    heap.push({0,1});
//
//    while(heap.size()){
//        auto t = heap.top();    //取出到源节点距离最小的节点位置
//        heap.pop();
//
//        int node = t.second;
//
//        if(st[node]) continue; //如果该节点被修改过，跳过
//        st[node] = true;       //不然的话将其标记已修改 并对其进行以下操作
//
//        for (auto li : g[node]) {
//            int newnode = li.first;
//            int w = li.second;
//            if(dist[newnode] > dist[node] + w){
//                dist[newnode] = dist[node] + w;
//                heap.push({dist[newnode] ,newnode});
//            }
//        }
//    }
//    if(dist[n] == 0x3f3f3f3f) return -1;
//    return dist[n];
//}
////int main() {
////    cin >> n >> m;
////    g.resize(n+1);        //这里一定要开g的大小不然无法存储，可以直接在定义时开N的大小
////    while(m--){
////        int a , b , c ;
////        cin >> a >> b >>c;
////        g[a].push_back({b,c});
////    }
////
////    cout << Dijkstra() << endl;
////    return 0;
////}
////
////
//////bellman_ford
//////
////// Created by ZhouJie on 2022/5/28 21:59.
//////给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。
//////
//////请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。
//////
//////注意：图中可能 存在负权回路 。
//////
//////输入格式
//////第一行包含三个整数 n,m,k。
//////
//////接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。
//////
//////输出格式
//////输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。
//////
//////如果不存在满足条件的路径，则输出 impossible。
//////
//////数据范围
//////1≤n,k≤500,
//////1≤m≤10000,
//////任意边长的绝对值不超过 10000。
//////
//////输入样例：
//////3 3 1
//////1 2 1
//////2 3 1
//////1 3 3
//////输出样例：
//////3
////
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
////int main() {
////    cin >> n >> m >> k;
////    for (int i = 0; i < m; ++i) {
////        int a,b,w;
////        cin >> a >>b >> w;
////        edge[i] = {a, b, w};
////    }
////    bellman_ford();
////    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
////    else cout << dist[n];
////    return 0;
////}
////




//spfa
#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n;
int m;
typedef pair<int,int> PII;
vector<list<PII>> g;            //这里用邻接表存储，稀疏图  其中对于g而言相当二维数组其中二维坐标表示的pair类型 first代表目标结点，second代表的权值
int dist[N];                      //到第n个结点的距离
bool st[N];                      //表示是否在队列中  避免重复判断  没有这个标记数组其实也没有问题 为了降低时间复杂度而已

int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;

    queue<int >q ;
    q.push(1);
    st[1] = true;   //表示1这个节点在队列中  防止重复调用

    while(q.size()){     //当队列中 没有元素时 停止遍历  这里使用bfs
        int t = q.front();
        q.pop();
        st[t] = false;   //表示t 这个节点已经处理过

        for (auto li : g[t]) {
            int j = li.first;
            int distance = li.second;
            if(dist[j] > dist[t] + distance){
                dist[j] = dist[t] + distance;
                if(!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n];


}
////int main() {
////    cin >> n >> m;
////    g.resize(n+1);        //这里一定要开g的大小不然无法存储，可以直接在定义时开N的大小
////    while(m--){
////        int a , b , c ;
////        cin >> a >> b >>c;
////        g[a].push_back({b,c});
////    }
////
////
////    int t = spfa();
////    if(t==0x3f3f3f3f) puts("impossible");
////    else cout<<t<<endl;
////    return 0;
////}
//
//
//
////prim
////给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。
////
////求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
////
////给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。
////
////由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。
////
////输入格式
////第一行包含两个整数 n 和 m。
////
////接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。
////
////输出格式
////共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
////
////数据范围
////1≤n≤500,
////1≤m≤105,
////图中涉及边的边权的绝对值均不超过 10000。
////
////输入样例：
////4 5
////1 2 1
////1 3 2
////1 4 3
////2 3 2
////3 4 4
////输出样例：
////6
//
////#include "bits/stdc++.h"
////using namespace std;
////const int N = 510, INF = 0x3f3f3f3f;
////
////int n, m;
////int g[N][N];
////int dist[N];
////bool st[N];  //记录当前点在集合内还是集合外
////
////int prim(){
////    memset(dist, 0x3f, sizeof dist);
////
////    int res = 0;
////    for(int i = 0; i < n; i++){  //要遍历n个点
////        //找一个最短边权的点
////        int t = -1; //初始化为没有找到的点
////        for(int j = 1; j <= n; j ++){
////            if(!st[j] && (t == -1 || dist[t] > dist[j])){
////                t = j;
////            }
////        }
////        //不是第一个取出的节点，并且当前节点的距离为INF,则表示没有和集合中点相连的边。
////        if(i && dist[t] == INF) return INF;
////        //不是第一个取出的节点，是其他点与集合中的连接线（最小边）
////        //写在前面，如果一个节点本身出现负环，下面这句更新后，会影响结果，比如g[t][j],当t = j,更新了g[t][t],影响res结果
////        //比如4->4 -10, 更新后dist[4] = min(dist[4], g[4][4])
////        if(i) res += dist[t];
////        //更新当前最短边权点t到集合的距离(保留最小的值，如果比之前最短t到集合的距离还小，更新)
////        for(int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);
////        st[t] = true;
////    }
////    return res;
////}
////
////int main(){
////    scanf("%d%d", &n, &m);
////
////    memset(g, 0x3f, sizeof g);
////    while(m --){
////        int a, b, c;
////        scanf("%d%d%d", &a, &b, &c);
////        g[a][b] = g[b][a] = min(g[a][b], c);
////    }
////
////    int t = prim();
////
////    if(t == INF) puts("impossible"); //有点不连通的时候，不存在最小生成树
////    else printf("%d", t);
////    return 0;
////}
//
//
////kruskal
////给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。
////
////求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
////
////给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示    图中边的集合，n=|V|，m=|E|。
////
////由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。
////
////输入格式
////第一行包含两个整数 n 和 m。
////
////接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。
////
////输出格式
////共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
////
////数据范围
////1≤n≤105,
////1≤m≤2∗105,
////图中涉及边的边权的绝对值均不超过 1000。
////
////输入样例：
////4 5
////1 2 1
////1 3 2
////1 4 3
////2 3 2
////3 4 4
////输出样例：
////6
//
//#include "bits/stdc++.h"
//using namespace std;
//const int N = 200010;
//int n , m;
//int p[N];
//
//
//vector<pair<int ,pair<int,int>>> edges;
//
//int find(int x){
//    if(p[x] != x) p[x] = find(p[x]);
//    return p[x];
//}
//
//int main(){
//    cin >> n >>m;
//
//    for (int i = 0; i < m; ++i) {
//        int a,b,w;
//        cin >> a >> b >> w;
//        edges.push_back({w,{a,b}});
//    }
//    sort(edges.begin(), edges.end());
//
//    for (int i = 1; i <= n ; ++i) {
//            p[i] = i;
//    }
//    int res = 0 ,cnt  = 0;
//    for (int i = 0; i < m; ++i) {
//        int w = edges[i].first;
//        int a = edges[i].second.first;
//        int b = edges[i].second.second;
//
//        a = find(a);
//        b = find(b);
//        if(a!= b ){
//            p[a] = b;
//            res += w;
//            cnt++;
//        }
//    }
//
//    if(cnt  < n-1 ) cout << "impossible";
//    else cout << res;
//    return  0;
//}


// 染色法判定二分图
//给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。
//
//请你判断这个图是否是二分图。
//
//输入格式
//第一行包含两个整数 n 和 m。
//
//接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。
//
//输出格式
//如果给定图是二分图，则输出 Yes，否则输出 No。
//
//数据范围
//1≤n,m≤105
//输入样例：
//4 4
//1 3
//1 4
//2 3
//2 4
//输出样例：
//Yes
//#include "bits/stdc++.h"
//using namespace std;
//const int N = 100010 , M = 200010;
//
//int n ,m;
//vector<list<int>> h(N);
//int color[N];
//
//bool dfs(int u ,int c){
//    color[u] = c;
//    for (auto t : h[u]){
//        if(!color[t]){
//            if(!dfs(t,3-c)) return false;
//        }
//        else if(color[t] == c) return false;
//    }
//    return true;
//}
//
//
//int main(){
//    cin >> n >> m;
//    while(m--){
//        int a, b ;
//        cin >> a >> b;
//        h[a].push_back(b);
//        h[b].push_back(a);
//    }
//
//    bool flag = true;
//    for (int i = 1; i <= n; ++i)
//        if(!color[i]){
//            if(!dfs(i,1)){
//                flag = false;
//                break;
//            }
//        }
//
//
//    if(flag) cout << "Yes" ;
//    else cout << "No";
//
//    return  0;
//}


// 二分图的最大匹配
//给定一个二分图，其中左半部包含 n1 个点（编号 1∼n1），右半部包含 n2 个点（编号 1∼n2），二分图共包含 m 条边。
//
//数据保证任意一条边的两个端点都不可能在同一部分中。
//
//请你求出二分图的最大匹配数。
//
//二分图的匹配：给定一个二分图 G，在 G 的一个子图 M 中，M 的边集 {E} 中的任意两条边都不依附于同一个顶点，则称 M 是一个匹配。
//
//二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。
//
//输入格式
//第一行包含三个整数 n1、 n2 和 m。
//
//接下来 m 行，每行包含两个整数 u 和 v，表示左半部点集中的点 u 和右半部点集中的点 v 之间存在一条边。
//
//输出格式
//输出一个整数，表示二分图的最大匹配数。
//
//数据范围
//1≤n1,n2≤500,
//1≤u≤n1,
//1≤v≤n2,
//1≤m≤105
//输入样例：
//2 2 4
//1 1
//1 2
//2 1
//2 2
//输出样例：
//2

#include "bits/stdc++.h"
using namespace std;
const int N = 510 , M = 100010;
int n1,n2,m;
vector<list<int>> h(N);
bool st[N];
int match[N];

int find(int x){
    for (auto t :h[x]) {
        if(!st[t]){
            st[t] = true;
            if(!match[t] || find(match[t])){
                match[t] = x;
                return true;
            }
        }
    }
    return false;
}


int main(){
    cin >> n1 >> n2 >> m;
    while(m--){
        int a ,b;
        cin >> a >> b;
        h[a].push_back(b);
    }
    int res = 0;
    for (int i = 1; i <= n1; ++i) {
        memset(st, false,sizeof st);
        if(find(i)) res ++;

    }
    cout << res << endl;
}