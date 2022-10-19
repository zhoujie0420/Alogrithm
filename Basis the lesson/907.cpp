//
// Created by ZhouJie on 2022/5/25 8:42.
//给定 N 个闭区间 [ai,bi] 以及一个线段区间 [s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。
//
//输出最少区间数，如果无法完全覆盖则输出 −1。
//
//输入格式
//第一行包含两个整数 s 和 t，表示给定线段区间的两个端点。
//
//第二行包含整数 N，表示给定区间数。
//
//接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。
//
//输出格式
//输出一个整数，表示所需最少区间数。
//
//如果无解，则输出 −1。
//
//数据范围
//1≤N≤105,
//−109≤ai≤bi≤109,
//−109≤s≤t≤109
//输入样例：
//1 5
//3
//-1 3
//2 4
//3 5
//输出样例：
//2

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int>PII;
vector<PII> p;
bool success;
int main() {
    int start , end;
    cin >> start >> end;
    int n ;
    cin >> n;
    int res = 0;
    while(n--){
        int a,b;
        cin >> a >> b;
        p.push_back({a,b});
    }
    sort(p.begin(),p.end());

    for (int i = 0; i < p.size(); ++i) {
        int j = i,r = -2e9;
        while(j < p.size() && p[j].first <= start){     //双指针 寻找满足条件的区间中右端点最大的区间
            r = max(r,p[j].second);
            j++;
        }
        res ++;

        if(r<start){                   //两个判断边界
            cout << -1 << endl;
            return 0;
        }
        if(r>=end) {
            success  = true;           //一定要标记 循环结束不代表一定可行解 （所有区间的最大值不一定能够满足大于end)
            break;
        }

        start = r;
        i = j-1;
    }
    if(success) {
        cout << res;
    }else
        cout << -1;
    return 0;
}