# Competitive Programming C++ Template Guide

## Overview

This template is designed to save time and reduce boilerplate code in competitive programming contests. It includes commonly used macros, utility functions, and a clean structure that works for most problems on platforms like Codeforces, AtCoder, LeetCode, and CSES.

## Template Structure

### 1. Header and Namespace

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- `bits/stdc++.h` includes all standard C++ libraries in one line
- Supported by most online judges (GCC compiler)
- Saves time during contests by avoiding multiple includes

### 2. Macros

#### Loop Macros
- `rep(i, a, b)` - Loop from `a` to `b-1` (similar to `for(int i=a; i<b; i++)`)
- `per(i, a, b)` - Reverse loop from `a` to `b` (similar to `for(int i=a; i>=b; i--)`)

**Example:**
```cpp
rep(i, 0, n) {  // i goes from 0 to n-1
    cout << arr[i] << " ";
}
```

#### Container Macros
- `all(x)` - Returns `x.begin(), x.end()` for sorting/algorithms
- `rall(x)` - Returns reverse iterators for reverse operations
- `sz(x)` - Returns size of container as integer
- `pb` - Short for `push_back()`
- `mp` - Short for `make_pair()`
- `fi`, `se` - Access first and second elements of pair

**Example:**
```cpp
vector<int> v = {3, 1, 4, 1, 5};
sort(all(v));  // Sorts the entire vector
vi result;
result.pb(10);  // Pushes 10 to vector
```

#### Type Shortcuts
- `ll` - long long (for large integers)
- `ull` - unsigned long long
- `ld` - long double
- `pii` - pair<int, int>
- `vi` - vector<int>
- `vll` - vector<long long>

**Example:**
```cpp
ll n = 1000000000000LL;  // Large number
vi arr(n);  // Vector of integers
pii point = {3, 5};  // Pair representing coordinates
```

### 3. Constants

```cpp
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
```

- `MOD` - Common modulo value for problems requiring modular arithmetic
- `INF` - Infinity value for int (useful for initializing min/max operations)
- `LINF` - Infinity value for long long

**When to modify:**
- Some problems use `MOD = 998244353` instead
- Adjust `INF` based on problem constraints

### 4. Fast I/O

```cpp
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
```

**Purpose:** Speeds up `cin` and `cout` operations significantly.

**Important:** After enabling fast I/O, don't mix `cin/cout` with `scanf/printf`.

### 5. Utility Functions

#### GCD and LCM
```cpp
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
```

**Usage:**
```cpp
ll g = gcd(24, 36);  // Returns 12
ll l = lcm(24, 36);  // Returns 72
```

#### Modular Exponentiation
```cpp
ll power(ll x, ll y, ll mod = MOD)
```

Computes `(x^y) % mod` efficiently in O(log y) time.

**Usage:**
```cpp
ll result = power(2, 10);  // 2^10 mod MOD
ll custom = power(3, 5, 13);  // 3^5 mod 13
```

### 6. Debug Macros

```cpp
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl;
#else
#define debug(x)
#endif
```

**Usage:**
- Compile locally with `-DLOCAL` flag to enable debugging
- Debug output goes to `cerr` (won't affect solution output)
- Automatically disabled when submitting to online judges

**Example:**
```cpp
int x = 42;
debug(x);  // Prints: x = 42 (only when LOCAL is defined)
```

## How to Use the Template

### Basic Workflow

1. **Copy the template** to your code editor
2. **Write your solution** inside the `solve()` function
3. **Handle test cases** appropriately

### Single Test Case Problems

If the problem has only one test case, comment out or remove this line:

```cpp
int main() {
    fastIO();
    
    int t = 1;
    // cin >> t;  // COMMENT THIS LINE for single test case
    
    while(t--) {
        solve();
    }
    return 0;
}
```

### Multiple Test Case Problems

Keep the template as is - it will read the number of test cases and run `solve()` for each.

### Example Problem Solution

**Problem:** Given an array of n integers, find the sum of all elements.

```cpp
void solve() {
    int n;
    cin >> n;
    
    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }
    
    ll sum = 0;
    for(int x : arr) {
        sum += x;
    }
    
    cout << sum << "\n";
}
```

## Compilation Tips

### Local Compilation with Debug

```bash
g++ -std=c++17 -O2 -DLOCAL solution.cpp -o solution
```

### Online Judge Compilation (no debug)

```bash
g++ -std=c++17 -O2 solution.cpp -o solution
```

### With Warnings (recommended for catching errors)

```bash
g++ -std=c++17 -O2 -Wall -Wextra -DLOCAL solution.cpp -o solution
```

## Common Patterns

### Reading Input

```cpp
// Single integer
int n;
cin >> n;

// Array
vi arr(n);
rep(i, 0, n) cin >> arr[i];

// Pair
pii p;
cin >> p.fi >> p.se;

// 2D array
vvi grid(n, vi(m));
rep(i, 0, n) rep(j, 0, m) cin >> grid[i][j];
```

### Sorting

```cpp
vi arr = {3, 1, 4, 1, 5};
sort(all(arr));  // Ascending order
sort(rall(arr));  // Descending order

// Custom comparator for pairs (sort by second element)
vpii points = {{1, 3}, {2, 1}, {3, 2}};
sort(all(points), [](pii a, pii b) { return a.se < b.se; });
```

### Binary Search

```cpp
vi arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int x = 5;

// Check if element exists
bool exists = binary_search(all(arr), x);

// Find position
auto it = lower_bound(all(arr), x);  // First element >= x
auto it2 = upper_bound(all(arr), x);  // First element > x
```

## Best Practices

1. **Test with sample inputs** before submitting
2. **Use debug macros** to print intermediate values locally
3. **Check for integer overflow** - use `ll` when needed
4. **Initialize variables** to avoid undefined behavior
5. **Read problem constraints** carefully to choose appropriate data types
6. **Time complexity matters** - ensure your solution fits within time limits
7. **Edge cases** - test with n=1, n=0 (if applicable), maximum constraints

## Common Modifications

### Different MOD Value

```cpp
const int MOD = 998244353;  // Alternative common MOD
```

### Additional Utility Functions

You can add more functions based on your needs:

```cpp
// Check if number is prime
bool isPrime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

// Count set bits
int countBits(ll n) {
    return __builtin_popcountll(n);
}
```

## Platform-Specific Notes

- **Codeforces:** Template works perfectly as-is
- **AtCoder:** Works well, but some problems may need custom MOD values
- **LeetCode:** Not applicable (uses function-based submission)
- **CSES:** Compatible with this template
- **Google Code Jam/Meta Hacker Cup:** Works, but may need output format adjustments

