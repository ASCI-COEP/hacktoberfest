/* Author : Jyotish Bhaskar
   Github-Profile : starboy-jb
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll , ll> PLL;
typedef long double ld;

#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define mod 1000000007
#define PI 3.14159265
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl;
#define MAX 100001

template < typename T > T GCD(T a, T b)            { ll t; while(a) { t = a; a = b % a; b = t; } return b; }
template < typename T > string toString(T a)       { return to_string(a); }
template < typename T > void toInt(string s, T &x) { stringstream str(s); str >> x;}
inline int add(ll a, ll b) {a += b; if (a < 0) a += mod; return a;}
inline int sub(ll a, ll b) {a -= b; if (a < 0) a += mod; return a;}
inline int mul(ll a, ll b) {return (a * 1ll * b) % mod;}
inline int pwr(ll x, ll y) {
  int ans = 1 % mod;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
inline int inv(int a) {return pwr(a, mod - 2);}

ll st[MAX][33];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //range min query using parse table
  int n;
  cin >> n;
  ll v;
  vector <ll> vec;
  for (int i = 0; i < n; i++) {
    cin >> v;
    vec.pb(v);
    st[i][0] = v;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    // zero based index
    int k = log2(r - l + 1);
    ll ans = min(st[l][k], st[r - (1 << k) + 1][k]);
    cout << ans << endl;
  }

  return 0;
}
