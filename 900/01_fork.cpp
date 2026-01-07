#include <bits/stdc++.h>
using namespace std;

// Macros for faster coding
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)

// Type definitions
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = acos(-1.0);

// Fast I/O
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Utility functions
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll power(ll x, ll y, ll mod = MOD) {
    ll res = 1;
    x %= mod;
    while(y > 0) {
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

// Debug print (only works in local environment)
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debug2(x, y) cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl;
#else
#define debug(x)
#define debug2(x, y)
#endif

// ======================== SOLUTION STARTS HERE ========================

void solve() {

    
}

int main() {
    fastIO();
    
    int t = 1;
    cin >> t;  // Comment this line if single test case
    
    while(t--) {
        solve();
    }
    
    return 0;
}