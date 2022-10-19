//
// Created by ZhouJie on 2022/5/23 9:08.
//某次智力测试包含无限多的题目，编号依次为 1,2,3…
//完成第 i 道题目所需要的时间为 i(i+1)/2。
//
//测试的总时长为 n。
//
//请计算，在规定时间内，从第 1 题开始按顺序答题，最多可以完成多少道题目？
//
//输入格式
//一个整数 n。
//
//输出格式
//一个整数，表示可以完成的最大题目数量。
//
//数据范围
//前三个测试点满足 1≤n≤25。
//所有测试点满足 1≤n≤104。

#include <bits/stdc++.h>

using namespace std;


int main() {
    long long n, cnt = 0;
    //不开long long不见祖宗
    cin >> n;
    for (int i = 1; ; i++){
        //日常死循环
        cnt += i * (i + 1) / 2;
        //一年级加减乘除
        if (cnt == n){
            cout << i << endl;
            return 0;
            //幼儿园判断大小
        }
        else if (cnt > n){
            cout << i - 1 << endl;
            return 0;
        }
    }
    return 0;
}
