//
// Created by ZhouJie on 2022/7/4.
//编写一个程序，可以实现将一个数字由一个进制转换为另一个进制。
//
//这里有 62 个不同数位 {0−9,A−Z,a−z}。
//
//输入格式
//第一行输入一个整数，代表接下来的行数。
//
//接下来每一行都包含三个数字，首先是输入进制（十进制表示），然后是输出进制（十进制表示），最后是用输入进制表示的输入数字，数字之间用空格隔开。
//
//输入进制和输出进制都在 2 到 62 的范围之内。
//
//（在十进制下）A=10，B=11，…，Z=35，a=36，b=37，…，z=61 (0−9 仍然表示 0−9)。
//
//输出格式
//对于每一组进制转换，程序的输出都由三行构成。
//
//第一行包含两个数字，首先是输入进制（十进制表示），然后是用输入进制表示的输入数字。
//
//第二行包含两个数字，首先是输出进制（十进制表示），然后是用输出进制表示的输入数字。
//
//第三行为空白行。
//
//同一行内数字用空格隔开。
//
//输入样例：
//8
//62 2 abcdefghiz
//10 16 1234567890123456789012345678901234567890
//16 35 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
//35 23 333YMHOUE8JPLT7OX6K9FYCQ8A
//23 49 946B9AA02MI37E3D3MMJ4G7BL2F05
//49 61 1VbDkSIMJL3JjRgAdlUfcaWj
//61 5 dl9MDSWqwHjDnToKcsWE1S
//5 10 42104444441001414401221302402201233340311104212022133030
//输出样例：
//62 abcdefghiz
//2 11011100000100010111110010010110011111001001100011010010001
//
//10 1234567890123456789012345678901234567890
//16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
//
//16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
//35 333YMHOUE8JPLT7OX6K9FYCQ8A
//
//35 333YMHOUE8JPLT7OX6K9FYCQ8A
//23 946B9AA02MI37E3D3MMJ4G7BL2F05
//
//23 946B9AA02MI37E3D3MMJ4G7BL2F05
//49 1VbDkSIMJL3JjRgAdlUfcaWj
//
//49 1VbDkSIMJL3JjRgAdlUfcaWj
//61 dl9MDSWqwHjDnToKcsWE1S
//
//61 dl9MDSWqwHjDnToKcsWE1S
//5 42104444441001414401221302402201233340311104212022133030
//
//5 42104444441001414401221302402201233340311104212022133030
//10 1234567890123456789012345678901234567890

#include<iostream>
#include<algorithm>
using namespace std;
char s[1010011];
int  a[1010011];


char get(int m)
{
    if(m<=9) return m+'0';
    else if(m<=35) return m+'A'-10;
    else if(m<=61) return m+'a'-36;
}

int reget(char m)
{
    if(m<='9') return m-'0';  // '0'=48  'A'=65 'a'=97
    else if(m<='Z') return m-'A'+10;
    else if(m<='z') return m-'a'+36;
}


string base(string s,int a,int b)
{
    int res=0;
    string n;
    for (auto t:s)
    {
        res=res*a+reget(t);
    }
    while(res)
    {
        n+=get(res%b);
        res/=b;

    }

    reverse(n.begin(),n.end());
    return n;
}


void work(string s)
{
    // string -> number
    int len=strlen(s);
    for(int i=0;i<len;++i)
    {
        if(s[i]>='0'&&s[i]<='9') a[len-i]=s[i]-'0';
        if(s[i]>='A'&&s[i]<='Z') a[len-i]=s[i]-'A'+10;
        if(s[i]>='a'&&s[i]<='z') a[len-i]=s[i]-'a'+36;
    }
    stack<char>sta;
    while(len)
    {
        int x=0;
        for(int i=len;i>=1;--i)//核心代码，高精除低精（除nxt）
        {
            int b=(x*pre+a[i])/nxt;
            x=(x*pre+a[i])%nxt;
            a[i]=b;
        }
        while(!a[len]&&len>=1) --len;
        if(x>=0&&x<=9) sta.push((char)(x+'0'));
        if(x>=10&&x<=35) sta.push((char)(x-10+'A'));
        if(x>=36&&x<=61) sta.push((char)(x-36+'a'));
    }
    while(!sta.empty()) {
        cout<<sta.top();
        sta.pop();
    }
    return;
}



int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;

        cout<<x<<" "<<s<<endl;
        cout<<y<<" "<<base(s,x,y)<<endl<<endl;
    }
}

