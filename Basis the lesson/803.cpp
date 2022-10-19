//
// Created by ZhouJie on 2022/6/7.
//给定 n 个区间 [li,ri]，要求合并所有有交集的区间。
//
//注意如果在端点处相交，也算有交集。
//
//输出合并完成后的区间个数。
//
//例如：[1,3] 和 [2,6] 可以合并为一个区间 [1,6]。
//
//输入格式
//第一行包含整数 n。
//
//接下来 n 行，每行包含两个整数 l 和 r。
//
//输出格式
//共一行，包含一个整数，表示合并区间完成后的区间个数。
//
//数据范围
//1≤n≤100000,
//−109≤li≤ri≤109
//输入样例：
//5
//1 2
//2 4
//5 6
//7 8
//7 9
//输出样例：
//3

#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n;
vector<pair<int,int>> p;
int main() {
    cin >> n ;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        p.push_back({a,b});
    }
    sort(p.begin(),p.end());

    int res = 1;
    int right = p[0].second;
    for (int i = 1; i < n; ++i) {
        if(p[i].first > right) {
            res++;
            right = p[i].second;
        }else{
            right = max(right,p[i].second);
        }
    }

    cout << res;
    return 0;
}