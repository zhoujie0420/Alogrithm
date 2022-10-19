//
// Created by ZhouJie on 2022/5/24 22:03.
//给定 N 个闭区间 [ai,bi]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）。
//
//输出可选取区间的最大数量。
//
//输入格式
//第一行包含整数 N，表示区间数。
//
//接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。
//
//输出格式
//输出一个整数，表示可选取区间的最大数量。
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
typedef pair<int,int> PII;
vector<PII> p;

bool cmp(pair<int,int>a,pair<int,int> b){
    return a.first<b.first;
}

int main() {
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a>> b;
        p.push_back({a,b});
    }

    sort(p.begin(),p.end(), cmp);
    int res = 1;
    int flag = p[0].second;

    for(auto i = 1;i<p.size();++i){
        if(flag >= p[i].first)
            flag = min(p[i].second, flag);
        else {
            res++;
            flag = p[i].second;
        }
    }

    cout << res;
    return 0;
}