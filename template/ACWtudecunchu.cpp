    //
    // Created by ZhouJie on 2022/5/11 9:25.
    //给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。
    //
    //请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。
    //
    //重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。
    //
    //输入格式
    //第一行包含整数 n，表示树的结点数。
    //
    //接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。
    //
    //输出格式
    //输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。
    /*

    #include <list>
    #include <vector>
    #include <iostream>

    const int N = 10006;
    using namespace std;
    vector<list<int>> adj(N);
    bool visited[N] ;
    int n;


    int ans = N;
    void addEdge( int i,int j){//想a这个结点中加入b;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    int dfs(int i){
        visited[i] = true;

        int sum = 1, res = 0;
        for(auto j = adj[i].begin(); j != adj[i].end(); j++){

            if(!visited[*j]) {
                int s = dfs( *j);
                res = max(res, s);
                sum += s;
            }
        }
        res = max(res,n-sum);
        ans = min(res,ans);
        return sum;
    }


    int main() {
        cin >> n ;
        for (int i = 0; i < n-1; ++i) {
            int a,b;
            cin >> a >> b;
            addEdge(a,b);
        }
        dfs(1);
        cout << ans << endl;

        return 0;
    }
     */

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

    /*
    #include "bits/stdc++.h"
    using namespace std;
    const int N = 100010;
    int n,m;
    vector<list<int>> adj(N);
    int d[N];
    queue<int> q;
    void addEdge(int a,int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int  bfs(){
        q.push(1);
        memset(d,-1,sizeof d);
        d[1]=0;

        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto j : adj[t]){
                if(d[j] == -1){
                    d[j]=d[t]+1;
                    q.push(j);
                }
            }
        }
        return d[n];
    }
    int main(){
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int a,b;
            cin >> a >> b;
            addEdge(a,b);
        }
        cout << bfs() << endl;
        return 0;
    }
     */

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
    #include "bits/stdc++.h"
    using namespace std;
    const int N = 100010;
    vector<list<int>> adj(N); //有向图
    queue<int> q;
    vector<int> res;
    int n,m;
    int d[N];  //表示入度

    void addEdge(int a,int b){
        adj[a].push_back(b);   //注意插入顺序
    }
    bool topsort(){
        for (int i = 1; i <= n ; ++i) {
            if(!d[i]) q.push(i);
        }
        while(!q.empty()){
            int t = q.front();
            res.push_back(t);
            q.pop();
            for(auto j : adj[t]){
                d[j] --;
                if(d[j] == 0) q.push(j);
            }
        }
        return res.size() == n;
    }
    int main(){
        cin >> n >> m;
        int a , b;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            addEdge(a,b);
            d[b]++;
        }

        if(topsort()) {
            for (int i = 0; i < n; ++i) {
                cout << res[i] << " " ;
            }
        } else
            cout << "-1";

        return 0;
    }