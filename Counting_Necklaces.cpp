#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
/* Custom hash function for pair<ll, ll>
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
}; */
const ll mod=1e9+7;
ll power(ll a,ll b)
{
    if(b==0) return 1;
    ll ans=power(a,b/2);
    if(b%2) return (ans%mod*ans%mod*a%mod)%mod;
    else (ans%mod*ans%mod)%mod;
}
ll exp(ll x,ll y,ll md)
{
    ll ans=1;
    x=x%md;
    while(y>0)
    {
        if(y&1)ans=ans*x%md;
        y=y>>1;
        x=x*x%md;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans=(ans+exp(m,__gcd(i,n),mod))%mod;
    }
    ans=ans*exp(n,mod-2,mod)%mod;
    cout<<ans<<endl;
}