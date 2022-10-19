//
// Created by ZhouJie on 2022/7/2.
//分形，具有以非整数维形式充填空间的形态特征。
//
//通常被定义为“一个粗糙或零碎的几何形状，可以分成数个部分，且每一部分都（至少近似地）是整体缩小后的形状”，即具有自相似的性质。
//
//现在，定义“盒子分形”如下：
//
//一级盒子分形：
//
//   X
//二级盒子分形：
//
//   X X
//    X
//   X X
//如果用 B(n−1) 代表第 n−1 级盒子分形，那么第 n 级盒子分形即为：
//
//  B(n - 1)        B(n - 1)
//
//          B(n - 1)
//
//  B(n - 1)        B(n - 1)
//你的任务是绘制一个 n 级的盒子分形。
//
//输入格式
//输入包含几个测试用例。
//
//输入的每一行包含一个不大于 7 的正整数 n，代表要输出的盒子分形的等级。
//
//输入的最后一行为 −1，代表输入结束。
//
//输出格式
//对于每个测试用例，使用 X 符号输出对应等级的盒子分形。
//
//请注意 X 是一个大写字母。
//
//每个测试用例后输出一个独立一行的短划线。
//
//输入样例：
//1
//2
//3
//4
//-1
//输出样例
//X
//-
//X X
// X
//X X
//-
//X X   X X
// X     X
//X X   X X
//   X X
//    X
//   X X
//X X   X X
// X     X
//X X   X X
//-
//X X   X X         X X   X X
// X     X           X     X
//X X   X X         X X   X X
//   X X               X X
//    X                 X
//   X X               X X
//X X   X X         X X   X X
// X     X           X     X
//X X   X X         X X   X X
//         X X   X X
//          X     X
//         X X   X X
//            X X
//             X
//            X X
//         X X   X X
//          X     X
//         X X   X X
//X X   X X         X X   X X
// X     X           X     X
//X X   X X         X X   X X
//   X X               X X
//    X                 X
//   X X               X X
//X X   X X         X X   X X
// X     X           X     X
//X X   X X         X X   X X
//-

#include <bits/stdc++.h>
using namespace std;
int a[1010][1010],n,m,i,j;
int power(int a,int b)
{
    int ans=1;
    while(b)
    {
        if (b&1)
            ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
void dg(int n,int x,int y)
{
    if (n==1)
    {
        a[x][y]=1;
        return ;
    }
    int len=power(3,n-2);
    dg(n-1,x,y);
    dg(n-1,x+2*len,y);
    dg(n-1,x+len,y+len);
    dg(n-1,x,y+2*len);
    dg(n-1,x+2*len,y+2*len);
}
int main()
{
    while(cin>>n && n!=-1)
    {
        memset(a,0,sizeof(a));
        dg(n,1,1);
        for(int i=1;i<=power(3,n-1);i++)
        {
            for(int j=1;j<=power(3,n-1);j++)
                if (a[i][j])
                    cout<<'X';
                else
                    cout<<' ';
            cout<<endl;
        }
        cout<<"-"<<endl;
    }
    return 0;
}


