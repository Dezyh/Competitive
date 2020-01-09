#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define mod 1000000007
#define mod2 998244353
#define tests int t; cin>>t; while(t--)

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vl> vvl;

void io(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
template<typename K>unordered_set<K>hashset(){unordered_set<K>s;s.max_load_factor(0.25);s.reserve(512);return s;}
template<typename K,typename V>unordered_map<K,V>hashmap(){unordered_map<K,V>m;m.max_load_factor(0.25);m.reserve(512);return m;}

const ll inf = 1000000000000000ll;

int dst(pi a, pi b) {
    return abs(a.first-b.first)+(abs(a.second-b.second));
}

ll cst(pi ap, pi bp, int ak, int bk) {
    return 1LL*(ak+bk)*dst(ap,bp);
}

vpi prims(int n, vvl edge) {
    vi parent(n);
    vl key(n);
    vb used(n);
    for (int i=0; i<n; i++) {
        key[i] = inf;
        used[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int c=0; c<n-1; c++) {
        int u = -1;
        ll min = inf;
        for (int v=0; v<n; v++) {
            if (used[v]==false && key[v]<min) {
                u=v;
                min=key[v];
            }
        }
        used[u] = true;
        for (int v=0; v<n; v++) {
            if (edge[u][v] && !used[v] && edge[u][v] < key[v]) {
                parent[v] = u;
                key[v] = edge[u][v];
            }
        }
    }
    vpi mst;
    for (int i=0; i<n; i++) {
        mst.pb({parent[i],i});
    }
    return mst;
}

int main() {
    io();
    
    // read input
    int n; cin >> n;
    vpi p(n+1); for (int i=1; i<n+1; i++) cin >> p[i].first >> p[i].second;
    vi c(n+1); for (int i=1; i<n+1; i++) cin >> c[i];
    vi k(n+1); for (int i=1; i<n+1; i++) cin >> k[i];

    // create graph
    vvl edge(n+1, vl(n+1));
    for (int i=0; i<n+1; i++) {
        edge[0][i] = c[i];
        for (int j=0; j<n+1; j++) {
            if (i==j || j==0) continue;
            if (i==0) {
                edge[i][j] = c[i];
            } else {
                edge[i][j] = cst(p[i],p[j],k[i],k[j]);
            }
        }
    }
    
    // find mst
    vpi mst = prims(n+1, edge);

    // parse mst into answer
    ll res=0; 
    int v=0; vi vs;
    int e=0; vpi es;
    for (int i=1; i<n+1; i++) {
        if (mst[i].first == -1) continue;
        if (mst[i].first == 0) {
            v++;
            vs.pb(mst[i].second);
            res += c[mst[i].second];
        } else {
            e++;
            es.pb({mst[i].first, mst[i].second});
            res += edge[mst[i].first][mst[i].second];
        }
    }

    // write answer
    cout << res << endl << v << endl;
    for (int i=0; i<v; i++) cout << vs[i] << ' ';
    cout << endl << e << endl;
    for (int i=0; i<e; i++) cout << es[i].first << ' ' << es[i].second << endl;
}