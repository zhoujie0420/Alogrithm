//
// Created by ZhouJie on 2022/7/13.
//这里有 n 列火车将要进站再出站，但是，每列火车只有 1 节，那就是车头。
//
//这 n 列火车按 1 到 n 的顺序从东方左转进站，这个车站是南北方向的，它虽然无限长，只可惜是一个死胡同，而且站台只有一条股道，火车只能倒着从西方出去，而且每列火车必须进站，先进后出。
//
//也就是说这个火车站其实就相当于一个栈，每次可以让右侧头火车进栈，或者让栈顶火车出站。
//
//车站示意如图：
//
//            出站<——    <——进站
//                     |车|
//                     |站|
//                     |__|
//现在请你按《字典序》输出前 20 种可能的出栈方案。
//
//输入格式
//输入一个整数 n，代表火车数量。
//
//输出格式
//按照《字典序》输出前 20 种答案，每行一种，不要空格。
//
//数据范围
//1≤n≤20
//输入样例：
//3
//输出样例：
//123
//132
//213
//231
//321

#include <bits/stdc++.h>

using namespace std;
vector<int > res;
stack<int > temp;
int start = 1;
int cnt = 20;
int n;

 void dfs(){
    if(cnt == 0) return;
    if(res.size()== n) {
        cnt --;
        for (const auto i: res) cout << i;
        cout << endl;
        return;
    }
    if(temp.size()){
        res.push_back(temp.top());
        temp.pop();
        dfs();
        temp.push(res.back());
        res.pop_back();
    }
    if(start <= n){
        temp.push(start);
        start++;
        dfs();
        temp.pop();
        start--;
    }
 }

int main() {
    cin >> n;
    dfs();
    return 0;
}