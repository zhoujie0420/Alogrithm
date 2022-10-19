//
// Created by ZhouJie on 2022/5/25 7:57.
//给定 N 个闭区间 [ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。
//
//输出最小组数。
//
//输入格式
//第一行包含整数 N，表示区间数。
//
//接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。
//
//输出格式
//输出一个整数，表示最小组数。
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
typedef pair<int,int>PII;

vector<PII> p;
priority_queue<int,vector<int>,greater<int>> q;

int main() {
    int n;
    cin >>n;
    while(n--){
        int a,b;
        cin>> a>>b;
        p.push_back({a,b});
    }
    sort(p.begin(),p.end());
    for (int i = 0; i < p.size(); ++i) {
        if(q.size() && q.top()<p[i].first) q.pop();
        q.push(p[i].second);
    }
    cout << q.size();

    return 0;
}