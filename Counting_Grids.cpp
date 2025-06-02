#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
/* Custom hash function for pair<ll, ll>
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
}; */
const ll mod = 1e9 + 7;
ll exp(ll x, ll y, ll md)
{
    ll ans = 1;
    x = x % md;
    while (y > 0)
    {
        if (y & 1)
            ans = ans * x % md;
        y = y >> 1;
        x = x * x % md;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    // burnside's lemma
    if (!(n & 1))
    {
        ll p = n * n;
        ll ans = 0;
        ans = (ans + exp(2, p, mod)) % mod;
        ans = (ans + 2 * exp(2, p / 4, mod)) % mod;
        ans = (ans + exp(2, p / 2, mod)) % mod;
        ans = (ans % mod * exp(4, mod - 2, mod) % mod) % mod;
        cout<<ans<<endl;
    }
    else
    {
        ll p = n * n;
        ll ans = 0;
        ans = (ans + exp(2, p, mod)) % mod;
        ans = (ans + 2 *( exp(2, (p-1) / 4, mod)%mod +exp(2,(p-1)/2,mod)%mod + exp(2, (p-1) / 4, mod) )%mod)% mod;
        ans = (ans % mod * exp(4, mod - 2, mod) % mod) % mod;
        cout<<ans<<endl;
    }
}