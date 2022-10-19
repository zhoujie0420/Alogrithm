    //
    // Created by ZhouJie on 2022/7/15.
    //很久很久以前，森林里住着一群兔子。
    //
    //有一天，兔子们想要研究自己的 DNA 序列。
    //
    //我们首先选取一个好长好长的 DNA 序列（小兔子是外星生物，DNA 序列可能包含 26 个小写英文字母）。
    //
    //然后我们每次选择两个区间，询问如果用两个区间里的 DNA 序列分别生产出来两只兔子，这两个兔子是否一模一样。
    //
    //注意两个兔子一模一样只可能是他们的 DNA 序列一模一样。
    //
    //输入格式
    //第一行输入一个 DNA 字符串 S。
    //
    //第二行一个数字 m，表示 m 次询问。
    //
    //接下来 m 行，每行四个数字 l1,r1,l2,r2，分别表示此次询问的两个区间，注意字符串的位置从 1 开始编号。
    //
    //输出格式
    //对于每次询问，输出一行表示结果。
    //
    //如果两只兔子完全相同输出 Yes，否则输出 No（注意大小写）。
    //
    //数据范围
    //1≤length(S),m≤1000000
    //输入样例：
    //aabbaabb
    //3
    //1 3 5 7
    //1 3 6 8
    //1 2 1 2
    //输出样例：
    //Yes
    //No
    //Yes

    #include <bits/stdc++.h>
    using namespace std;
    const int N=1e6+10;
    typedef long long  LL;
    LL h[N], p[N];
    char s[N];
    const LL P = 131;

    int n,m;

    int main() {
        cin >> (s+1) >> m;
        n = strlen(s+1);
        p[0] = 1;
        for(int i = 1;i <=n ;++i){
            h[i]=(h[i-1]*P+(s[i]-'a'+1));
            p[i] = p[i-1] * P;
        }
        while(m--){
            int l1,r1,l2,r2;
            cin >> l1 >> r1 >> l2 >> r2;
            if(  ( h[r1] - h[l1-1] *p[r1 - l1 +1] ) == (  h[r2] - h[l2-1]  *p[r2 - l2 +1])  ) puts("Yes");
            else puts("No");
        }
        return 0;
    }