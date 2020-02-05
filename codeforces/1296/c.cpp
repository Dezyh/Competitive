#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define mod9 998244353
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define tests int t; cin>>t; while(t--)

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<bool> vb;

void io(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
template<typename K>unordered_set<K>hashset(){unordered_set<K>s;s.max_load_factor(0.25);s.reserve(512);return s;}
template<typename K,typename V>unordered_map<K,V>hashmap(){unordered_map<K,V>m;m.max_load_factor(0.25);m.reserve(512);return m;}

const ll inf = 10000000000000ll;

int main() {
    io();
    tests {

        int o = 200001;
        int l = -1;
        int r = -1;

        pi c = {0,0};

        auto ps = map<pi,int>();
        ps[c] = t;

        int n; cin >> n;
        for (int i=0; i<n; i++) {

            int t = i+1;
            char m; cin >> m;
            
            if (m=='U') {
                c.ss++;
            } else if (m=='D') {
                c.ss--;
            } else if (m=='L') {
                c.ff--;
            } else if (m=='R') {
                c.ff++;
            }

            if (ps.find(c) == ps.end()) {
                ps[c] = t;
            } else {
                if (t-ps[c] < o) {
                    l = ps[c];
                    r = t;
                    o = t-ps[c];
                } else {
                    ps[c] = t;
                }
            }
        }

        if (o == 200001) {
            cout << -1 << endl;
        } else {
            cout << l+1 << " " << r << endl;
        }
    }
}