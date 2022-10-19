//
// Created by ZhouJie on 2022/7/22.
//翰翰和达达饲养了 N 只小猫，这天，小猫们要去爬山。
//
//经历了千辛万苦，小猫们终于爬上了山顶，但是疲倦的它们再也不想徒步走下山了（呜咕>_<）。
//
//翰翰和达达只好花钱让它们坐索道下山。
//
//索道上的缆车最大承重量为 W，而 N 只小猫的重量分别是 C1、C2……CN。
//
//当然，每辆缆车上的小猫的重量之和不能超过 W。
//
//每租用一辆缆车，翰翰和达达就要付 1 美元，所以他们想知道，最少需要付多少美元才能把这 N 只小猫都运送下山？
//
//输入格式
//第 1 行：包含两个用空格隔开的整数，N 和 W。
//
//第 2..N+1 行：每行一个整数，其中第 i+1 行的整数表示第 i 只小猫的重量 Ci。
//
//输出格式
//输出一个整数，表示最少需要多少美元，也就是最少需要多少辆缆车。
//
//数据范围
//1≤N≤18,
//1≤Ci≤W≤108
//输入样例：
//5 1996
//1
//2
//1994
//12
//29
//输出样例：
//2

#include <bits/stdc++.h>


using namespace std;

const int N = 2e1;
int cat[N],cab[N];
int n , w;
int ans;



bool cmp(int a, int b){
    return a > b;
}

void dfs(int now, int cnt){
    if(cnt >= ans ) return ;
    if(now == n){
        ans = min(ans,cnt);
        return;
    }
    for (int i = 0; i < cnt; ++i){
        if(cab[i] + cat[now] <= w){
            cab[i] += cat[now];
            dfs(now+1,cnt);
            cab[i] -= cat[now];
        }
    }

    cab[cnt+1] =cat[now];
    dfs(now+1,cnt+1);
    cab[cnt+1] = 0;
}
int main() {
    cin >> n >> w;
    for (int i = 0; i < n; ++i) cin >> cat[i];
    sort(cat,cat+n, cmp);
    ans = n-1;

    dfs(0,0);

    cout << ans+1;
    return 0;
}