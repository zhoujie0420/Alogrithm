//
// Created by ZhouJie on 2022/7/22.
//给定一张 N 个点 M 条边的有向无环图，分别统计从每个点出发能够到达的点的数量。
//
//输入格式
//第一行两个整数 N,M，接下来 M 行每行两个整数 x,y，表示从 x 到 y 的一条有向边。
//
//输出格式
//输出共 N 行，表示每个点能够到达的点的数量。
//
//数据范围
//1≤N,M≤30000
//输入样例：
//10 10
//3 8
//2 3
//2 5
//5 9
//5 9
//2 3
//3 9
//4 8
//2 10
//4 9
//输出样例：
//1
//6
//3
//3
//2
//1
//1
//1
//1
//1

#include <bits/stdc++.h>

using namespace std;
const int N = 30010;
int n,m;
vector<list<int>> adj(N);
int cnt[N] ;
vector<int> res;
bitset<N> f[N];
void topsort(){
    queue<int> q;
    for (int i = 0; i < n; ++i) if(cnt[i] == 1) q.push(i);
    while(!q.empty()) {
        int temp = q.front();
        res.push_back(temp);
        q.pop();
        for (const auto j: adj[temp]){
            cnt[j] --;
            if(cnt[j] == 1) q.push(j);
        }
    }


}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cnt[i] = 1;
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        cnt[b]++;
    }
    topsort();
    for (int i = n-1; i = 0; i--){

    }
    return 0;
}