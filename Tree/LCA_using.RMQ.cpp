/* Author : Jyotish Bhaskar
   Github-Profile : starboy-jb
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <iomanip>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll , ll> PLL;
typedef long double ld;
 
#define pb push_back
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
int mod = 1000000007;
const int inf = 1034567891;
const ll LL_INF = 1234567890123456789ll;
#define PI 3.14159265
#define endl '\n'
#define F first
#define S second
#define debug(x) cout << #x << " = " << x << endl;
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
 
#define out(container) for (auto it : container) cout << it << " "; cout << endl;
 
 
template < typename T > T GCD(T a, T b)            { ll t; while(a) { t = a; a = b % a; b = t; } return b; }
template < typename T > string toString(T a)       { return to_string(a); }
template < typename T > void toInt(string s, T &x) { stringstream str(s); str >> x;}
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
  int x = 1 % mod;
  while(b){
    if(b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

const int N = 2e3 + 5;

vector <int> adj[N];
int level[N], firstIndex[N];
vector <int> eulerTour;
bool vis[N];

void dfs(int s) {
  vis[s] = true;
  for (auto it : adj[s]) {
    if (!vis[it]) {
      level[it] = level[s] + 1;
      eulerTour.pb(s);
      if (firstIndex[s] == -1) firstIndex[s] = eulerTour.size() - 1;
      dfs(it);
      eulerTour.pb(it);
      if (firstIndex[it] == -1) firstIndex[it] = eulerTour.size() - 1;
    }
  }
}

struct SegTree {
  int seg[4 * N];

  void build(int l, int r, int pos) {
    if (l == r) {
      seg[pos] = l;
      return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * pos + 1);
    build(mid + 1, r, 2 * pos + 2);
    if (level[eulerTour[seg[2 * pos + 1]]] < level[eulerTour[seg[2 * pos + 2]]]) {
      seg[pos] = seg[2 * pos + 1];
    } else {
      seg[pos] = seg[2 * pos + 2];
    }
  }

  int query(int ql, int qr, int l, int r, int pos) {
    if (l >= ql && r <= qr) {
      return seg[pos];
    }
    if (r < ql || l > qr) {
      return -1;
    }
    int mid = (l + r) / 2;
    int u = query(ql, qr, l, mid, 2 * pos + 1);
    int v = query(ql, qr, mid + 1, r, 2 * pos + 2);
    if (u == -1) return v;
    if (v == -1) return u;
    return (level[eulerTour[u]] < level[eulerTour[v]]? u: v);
  }
  int lca(int, int);
};

int SegTree :: lca(int ind1, int ind2) {
  int ans = query(ind1, ind2, 0, eulerTour.size() - 1, 0);
  return eulerTour[ans];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  memset(firstIndex, -1, sizeof(firstIndex));
  level[1] = 0;
  dfs(1);
  eulerTour.pb(1);
  if (firstIndex[1] == -1) firstIndex[1] = 0;
  SegTree seg;
  seg.build(0, eulerTour.size() - 1, 0);
  int q;
  cin >> q;
  while (q--) {
    cin >> u >> v;
    if (firstIndex[u] > firstIndex[v]) swap(u, v);
    int ans = seg.lca(firstIndex[u], firstIndex[v]);
    cout << ans << endl;
  }


  return 0;
}
