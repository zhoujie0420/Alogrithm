//
// Created by ZhouJie on 2022/7/2.
//有 n 个小组要排成一个队列，每个小组中有若干人。
//
//当一个人来到队列时，如果队列中已经有了自己小组的成员，他就直接插队排在自己小组成员的后面，否则就站在队伍的最后面。
//
//请你编写一个程序，模拟这种小组队列。
//
//输入格式：
//输入将包含一个或多个测试用例。
//
//对于每个测试用例，第一行输入小组数量 t。
//
//接下来 t 行，每行输入一个小组描述，第一个数表示这个小组的人数，接下来的数表示这个小组的人的编号。
//
//编号是 0 到 999999 范围内的整数。
//
//一个小组最多可包含 1000 个人。
//
//最后，命令列表如下。 有三种不同的命令：
//
//1、ENQUEUE x - 将编号是 x 的人插入队列；
//
//2、DEQUEUE - 让整个队列的第一个人出队；
//
//3、STOP - 测试用例结束
//
//每个命令占一行。
//
//当输入用例 t=0 时，代表停止输入。
//
//需注意：测试用例最多可包含 200000（20 万）个命令，因此小组队列的实现应该是高效的：
//
//入队和出队都需要使用常数时间。
//
//输出样例
//对于每个测试用例，首先输出一行 Scenario #k，其中 k 是测试用例的编号。
//
//然后，对于每个 DEQUEUE 命令，输出出队的人的编号，每个编号占一行。
//
//在每个测试用例（包括最后一个测试用例）输出完成后，输出一个空行。
//
//数据范围
//1≤t≤1000
//输入样例：
//2
//3 101 102 103
//3 201 202 203
//ENQUEUE 101
//ENQUEUE 201
//ENQUEUE 102
//ENQUEUE 202
//ENQUEUE 103
//ENQUEUE 203
//DEQUEUE
//DEQUEUE
//DEQUEUE
//DEQUEUE
//DEQUEUE
//DEQUEUE
//STOP
//2
//5 259001 259002 259003 259004 259005
//6 260001 260002 260003 260004 260005 260006
//ENQUEUE 259001
//ENQUEUE 260001
//ENQUEUE 259002
//ENQUEUE 259003
//ENQUEUE 259004
//ENQUEUE 259005
//DEQUEUE
//DEQUEUE
//ENQUEUE 260002
//ENQUEUE 260003
//DEQUEUE
//DEQUEUE
//DEQUEUE
//DEQUEUE
//STOP
//0
//输出样例：
//
//Scenario #1
//101
//102
//103
//201
//202
//203
//
//Scenario #2
//259001
//259002
//259003
//259004
//259005
//260001

#include <bits/stdc++.h>
const int N = 1010,M = 1000010;;
using namespace std;

int team_id[M]; // 人的编号

int main() {
    int n;//代表有n个队伍
    int k = 1;
    while(cin >> n , n){
        printf("Scenario #%d\n",k ++); // 输出这个队的编号
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            while(m--){
                int x;
                scanf("%d",&x);
                team_id[x] = i; // 存下编号
            }
        }
        queue<int> team;
        queue<int> person[N];
        string str;
        while(cin >> str , str != "STOP"){

            if(str == "ENQUEUE"){
                int x;
                cin >> x;
                int id = team_id[x];
                if(person[id].empty()) team.push(id);
                person[id].push(x);
            }else{
                int id = team.front();
                cout << person[id].front() << endl;
                person[id].pop();
                if(person[id].empty()) team.pop();
            }
        }
        cout << endl;
    }
    return 0;
}