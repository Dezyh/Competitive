#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mod 1000000007
#define tests int t; cin>>t; while(t--)

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
typedef unordered_set<int> hsi;
typedef unordered_map<int,int> hmii;

void io() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
unordered_set<int> hashset() { unordered_set<int> s; s.max_load_factor(0.25); s.reserve(512); return s; }
unordered_map<int,int> hashmap() { unordered_map<int,int> m; m.max_load_factor(0.25); m.reserve(512); return m; }

const ll inf = 10000000000000ll;

int main() {
    io();

    int n, m, p=0;
    cin >> n >> m;

    ll res=0;
    hsi o = hashset();
    queue<int> q; 
    vector<int> ans;

    for (int i=0; i<n; i++) {
        int x; cin >> x;
        q.push(x);
        o.insert(x);
    }

    int dst=1;
    while (p<m) {
        int r = q.size();
        for (int i=0; i<r; i++) {
            if (p>=m) {
                break;
            }
            int x = q.front(); q.pop();
            if (o.find(x-1) == o.end()) {
                p++;
                res += dst;
                ans.pb(x-1);
                q.push(x-1);
                o.insert(x-1);
            }
            if (p>=m) {
                break;
            }
            if (o.find(x+1) == o.end()) {
                p++;
                res += dst;
                ans.pb(x+1);
                q.push(x+1);
                o.insert(x+1);
            }
        }
        dst++; 
    }

    cout << res << endl;
    for (int i=0; i<m; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}