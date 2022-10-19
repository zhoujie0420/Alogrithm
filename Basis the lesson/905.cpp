//
// Created by ZhouJie on 2022/5/24 21:46.
//给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
//
//输出选择的点的最小数量。
//
//位于区间端点上的点也算作区间内。
//
//输入格式
//第一行包含整数 N，表示区间数。
//
//接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。
//
//输出格式
//输出一个整数，表示所需的点的最小数量。
//
//数据范围
//1≤N≤105,
//−109≤ai≤bi≤109
//输入样例：
//3
//-1 1
//2 4
//3 5
//输出样例：
//2

#include <bits/stdc++.h>

using namespace std;
int N = 10006;
typedef  pair<int,int> PII;

vector<PII> p;

bool cmp1(pair<int,int> a,pair<int,int>b){
    return a.second<b.second;
}
int main() {
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        p.push_back({a,b});
    }
    sort(p.begin(),p.end(), cmp1);

    int flag = p[0].second;
    int res = 1;


    for(auto t : p){
        if(flag < t.first) {       // 如果当前扫描到的位置的first  >   最大可行区间
                                // 则开始重新赋值flag  且所需要的res++
            res++;
            flag = t.second;
        }
    }
    cout << res;

    return 0;
}