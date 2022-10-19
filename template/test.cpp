#include "bits/stdc++.h"
using namespace std;


using namespace std;

typedef pair<int, int> PLL;
typedef long long LL;
int n;
int cnt = 0;
int sum = 0;
map<PLL, vector<pair<LL, int>>> mp;
int main()
{
    scanf("%d", &n);
    while(n--){
        LL x,y,s;
        scanf("%lld %lld %d", &x, &y, &s);
        sum += s;

        LL d = x*x+y*y;
        LL gcd = abs(__gcd(x, y));

        x /= gcd;
        y /= gcd;
        mp[{x,y}].push_back({d,s});
    }

    for (auto item: mp){
        vector<pair<long long ,int >> now = item.second;
        sort(now.begin(),now.end());

        for (int i = 0; i < now.size(); ++i) {
            if(now[i].second != 1)
                cnt ++;
            else{
                if((i+1 < now.size() && now[i+1].second != 1) || i+1 == now.size()) cnt ++;
            }
        }
    }
    cout << sum << " " << cnt;
    return 0;
}