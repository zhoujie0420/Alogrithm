//
// Created by ZhouJie on 2022/6/7.
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
//
//数据范围
//1≤n≤105
//输入样例
//9
//1 2
//1 7
//1 4
//2 8
//2 5
//4 3
//3 9
//4 6
//输出样例：
//4

#include <bits/stdc++.h>

using namespace std;
const int N = 10010;
int n;
int ans = N;
vector<list<int>> g(N);

int dfs(int u){ //其中u表示遍历到第几层   返回的是以u为节点子树中的数量
    int size = 0 , sum = 1;
    for(auto t : g[u]){
        int s = dfs(t);
        size = max(size,s);
        sum += s;
    }

    size = max(size , n -sum);
    ans = min(size,ans);
    return sum;

}
int main() {
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a , b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    dfs(1);

    cout << ans;
    return 0;
}


// 正解


//
// Created by ZhouJie on 2022/5/11 9:25.
//


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