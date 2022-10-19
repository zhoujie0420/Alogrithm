//
// Created by ZhouJie on 2022/7/13.
//

#include <bits/stdc++.h>

using namespace std;
stack<int> l;
stack<int> r;
const int N = 1000010;
int f[N];//初始化
int sum[N];
int main() {
    f[0]=-1e7;//初始化
    sum[0]=0;
    int n;
    cin >> n;
    while(n--){
        char c;
        cin >> c;
        if(c == 'I'){
            int x;
            cin >> x;
            l.push(x);

            sum[l.size()]=sum[l.size()-1]+l.top();//前1~a.size()-1的前缀和,加上这个一个新来的,构成1~a.size()
            f[l.size()]=max(f[l.size()-1],sum[l.size()]);

        }else if(c == 'D'){
            if(!l.empty()){
                l.pop();
            }
        }else if(c == 'L'){
            if(!l.empty()){
                int temp = l.top();
                l.pop();
                r.push(temp);
            }
        }else if(c == 'R'){
            if(!r.empty()){
                int temp = r.top();
                r.pop();
                l.push(temp);
                sum[l.size()]=sum[l.size()-1]+l.top();//同样的还是重新定义.
                f[l.size()]=max(f[l.size()-1],sum[l.size()]);//见插入操作.
            }
        }else if(c == 'Q'){
            int x;
            cin >> x;
            printf("%d\n",f[x]);//输出当前最大值区间.
        }
    }
    return 0;
}