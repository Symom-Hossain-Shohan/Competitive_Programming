#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e6 + 5; 
const ll base = 26000033; 
const ll M = 1e9 + 33; 
ll hashrr[N], p[N], n, hashkey, m, cum_sum[N]; 
map<pair<ll,ll>, ll> mp; 

struct Data
{
    ll num; 
    ll c, lat; 
};

struct data2
{
    ll d; 
    char ch; 
};

Data arr[N], brr[N]; 
data2 crr[N], drr[N]; 

ll amodb(ll a, ll b)
{
    ll div = a/b; 
    return a - (div*b); 
}



void pcal()
{
    p[0] = 1; 
    for(ll i = 1;i<N; i++)
    {
        p[i] = (p[i-1]*base) % M; 
    }
}


void hashFunc()
{
    ll dig, c, i; 
    dig = crr[0].d; 
    c = (crr[0].ch-'a') + 1; 

    hashrr[0] = mp[{dig, c}]; 

    for(i=1;i<n;i++)
    {
        dig = crr[i].d; 
        c = (crr[i].ch-'a') + 1; 
        hashrr[i] = amodb(hashrr[i-1]*base + mp[{dig, c}], M); 
    }

    dig = drr[1].d; 
    c = (drr[1].ch - 'a') + 1; 

    hashkey = mp[{dig, c}]; 

    for(i=2;i<m-1; i++)
    {
        dig = drr[i].d; 
        c = (drr[i].ch-'a') + 1; 
        hashkey = amodb(hashkey*base + mp[{dig, c}], M); 
    }
}


ll searchstr()
{
    ll i, j, cnt = 0, l, r; 
    for(i = 0;i<=n-m; i++)
    {
        if(crr[i].ch == drr[0].ch and crr[i].d >= drr[0].d and crr[(m+i)-1].ch == drr[m-1].ch and crr[(m+i)-1].d >= drr[m-1].d)
        {
            l = i+1; 
            r = m+i-2; 
            ll baad = amodb(hashrr[l-1]*p[r-l+1], M);
            ll hashv = amodb(hashrr[r]-baad + M, M); 

            if(hashv==hashkey) cnt++;
        }
    }

    return cnt; 
}

void solve()
{
    pcal();

    ll i, j; 
    scanf("%lld %lld", &n, &m); 

    for(int i=0;i<n; i++)
    {
        scanf("%lld %c %c", &arr[i].num, &arr[i].c, &arr[i].lat);  
    }

    for(int i=0;i<m; i++)
    {
        scanf("%lld %c %c", &brr[i].num, &brr[i].c, &brr[i].lat); 
    }

    j = 0; 

    ll sum = arr[0].num; 

    for(i = 0; i<n-1; i++)
    {
        if(arr[i].lat == arr[i+1].lat)
        {
            sum += arr[i+1].num; 
        }
        else 
        {
            crr[j].d = sum; 
            crr[j].ch = arr[i].lat; 
            sum = arr[i+1].num; 
            j++; 
        }
    }

    if(sum)
    {
        crr[j].d = sum; 
        crr[j].ch = arr[i].lat; 
    }
    else 
    {
        crr[j].d = arr[i].num; 
        crr[j].ch = arr[i].lat; 
    }

    n = j+1; 

    j = 0; 
    sum = brr[0].num; 
    
    for(i = 0; i<m-1; i++)
    {
        if(brr[i].lat == brr[i+1].lat)
        {
            sum += brr[i+1].num; 
        }
        else 
        {
            drr[j].d = sum; 
            drr[j].ch = brr[i].lat; 
            sum = brr[i+1].num; 
            j++; 
        }
    }

    if(sum)
    {
        drr[j].d = sum; 
        drr[j].ch = brr[i].lat; 
    }
    else 
    {
        drr[j].d = brr[i].num; 
        drr[j].ch = brr[i].lat; 
    }
    m = j+1; 

    ll cnt = 0; 
    if(m==2)
    {
        for(i=0;i<=n-m; i++)
        {
            if(crr[i].ch == drr[0].ch and crr[i].d>=drr[0].d and crr[i+1].ch == drr[1].ch and crr[i+1].d >= drr[1].d) cnt++; 
        }
        cout << cnt << endl; 
    }
    else if(m==1)
    {
        for(i=0;i<n; i++)
        {
            if(crr[i].ch == drr[0].ch and crr[i].d>=drr[0].d) cnt += (crr[i].d - drr[0].d) + 1; 
        }
        cout << cnt << endl; 
    }
    else 
    {
        ll inc = 1; 
        vector<pair<ll,ll>> v; 
        ll c, dig; 
        for(i=0;i<n; i++)
        {
            c = (crr[i].ch-'a'+1); 
            dig = crr[i].d; 
            v.push_back({dig, c}); 
        }
        for(i=0;i<m;i++)
        {
            c = (drr[i].ch-'a'+1); 
            dig = drr[i].d; 
            v.push_back({dig, c});
        }

        sort(v.begin(), v.end()); 

        for(i=0;i<n+m; i++)
        {
            dig = v[i].first; 
            c = v[i].second; 
            if(!mp[{dig, c}])
            {
                mp[{dig, c}] = inc; 
                inc++; 
            }
        }

        hashFunc(); 

        printf("%lld\n", searchstr()); 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}