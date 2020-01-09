#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mod 1000000007

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pi> vp;
typedef vector<pl> vpl;

const ll inf = 10000000000000ll;

//       | s e | 
// 2 3 2 | 3 5 | 4

// e=      3 4 
// 2 2 2 | 2 2 | 2
// 2 2 2 | 3 4 | 4
// s=      3 4
void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n-1; i++) {
        int l=a[i], h=a[i];
        for (int j=i+1; j<n; j++) {
            l=min(l,a[j]);
            h=max(h,a[j]);
            if (h-l>=j-i+1) {
                cout << "YES" << endl;
                cout << i+1 << " " << j+1 << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}