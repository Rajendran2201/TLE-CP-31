#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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

// to traverse the knight in all 4 directions, we can use the coordinates
// this coordinates is designed in terms of 4 quadrants.

int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

void solve() {

    ll a, b;
    cin >> a >> b;
    ll x_king, y_king;
    cin >> x_king >> y_king;
    ll x_queen, y_queen;
    cin >> x_queen >> y_queen;

    // to store the hits of the king and queen, let's use a set
    // we use a set because, it provides a way to do these operations 
    // in a logarithmic time. 
    set<pll> king_hits, queen_hits;


    // find all possible hits by the king and queen and store them into the set
    // this can be done by using the direction vectors
    // here, the knight can move in (a,b) or (b,a) directions. 
    for(int i=0; i<4; i++){
        king_hits.insert({x_king + dx[i] * a, y_king + dy[i] * b});
        king_hits.insert({x_king + dx[i] * b, y_king + dy[i] * a});

        queen_hits.insert({x_queen + dx[i] * a, y_queen + dy[i] * b});
        queen_hits.insert({x_queen + dx[i] * b, y_queen + dy[i] * a});
    }

    // now, find the intersection of king_hits and queen_hits
    // for this, we have to count the similar entries in both sets
    int ans = 0;
    for(auto position : king_hits){
        if(queen_hits.find(position) != queen_hits.end())
            ans++;
    }

    cout << ans << endl;

}

int main() {
    fastIO();
    
    int t = 1;
    cin >> t; 
    
    while(t--) {
        solve();
    }
    
    return 0;
}