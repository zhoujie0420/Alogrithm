//
// Created by ZhouJie on 2022/5/18 8:19.
//给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。
//
//现在，请你按照字典序将所有的排列方法输出。
//
//输入格式
//共一行，包含一个整数 n。
//
//输出格式
//按字典序输出所有排列方案，每个方案占一行。
//
//数据范围
//1≤n≤7
//输入样例：
//3
//输出样例：
//1 2 3
//1 3 2
//2 1 3
//2 3 1
//3 1 2
//3 2 1

#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
bool flag[N]; //标记 i 是否被使用过
int n;  //输入数字
vector<int> res;


void dfs(int u){
    if(u == n) {
        for (auto x : res) {
            cout << x << " ";
        }
        cout << endl;
    }

    for(int k = 1;k <= n;++k) {
        if(!flag[k]){
            res.push_back(k);
            flag[k] = true;
            dfs(u+1);
            res.pop_back();
            flag[k] = false;
        }
    }
}

int main() {
    cin >> n;

    dfs(0); // 要从零开始  因为参数等于n的时候已经实行输出语句

    return 0;
}