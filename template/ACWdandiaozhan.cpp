//
// Created by ZhouJie on 2022/5/5 22:48.
//给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。
//
//输入格式
//第一行包含整数 N，表示数列长度。
//
//第二行包含 N 个整数，表示整数数列。
//
//输出格式
//共一行，包含 N 个整数，其中第 i 个数表示第 i 个数的左边第一个比它小的数，如果不存在则输出 −1。
// 单调栈

#include <bits/stdc++.h>

using namespace std;
const int N = 10006;
int n;
stack<int> st;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while(!st.empty() && st.top() >= x) st.pop();
        if(!st.empty()) cout << st.top() << " " ;
        else cout << "-1" << " ";

        st.push(x);

    }
    return 0;
}
