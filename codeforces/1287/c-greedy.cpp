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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<bool> vb;

void io(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
template<typename K>unordered_set<K>hashset(){unordered_set<K>s;s.max_load_factor(0.25);s.reserve(512);return s;}
template<typename K,typename V>unordered_map<K,V>hashmap(){unordered_map<K,V>m;m.max_load_factor(0.25);m.reserve(512);return m;}

const ll inf = 10000000000000ll;

#define MISSING 0
#define NONE -1
#define ODD 0
#define EVN 1

int main() {
    io();
    int n; cin >> n;
    
    int odd=n/2+n%2; 
    int evn=n/2;

    int ans=0;

    vi p(n);

    // read p and store number of odds and evens available
    for (int i=0; i<n; i++) {
        cin >> p[i];
        if (p[i]!=0) {
            if (p[i]%2==0) evn--;
            else odd--;
        }
    }
    
    int s=NONE;
    int e=NONE;
    int sz=0;

    int s_sz=0;
    int e_sz=0;
    int s_p=NONE;
    int e_p=NONE;

    for (int i=0; i<n; i++) {

        // update the start of the sequence
        if (s_p==NONE) {
            if (p[i]==MISSING) {
                s_sz++;
            } else {
                s_p=p[i]%2;
            }
        }

        // update the end of the sequence
        if (p[i]==MISSING) {
            e_sz++;
        } else {
            e_sz=0;
            e_p=p[i]%2;
        }

        // skip the blanks
        if (p[i]==MISSING) {
            sz++;
            continue;
        }

        // update the start and end as required
        if (s==NONE) {
            s=p[i]%2;
        } else if (e==NONE) {
            e=p[i]%2;
        }

        // handle even and even cases
        if (s==EVN && e==EVN) { 
            if (evn >= sz) {
                evn -= sz;
            } else {
                ans+=2;
            }
        }

        // handle odd and odd cases
        if (s==ODD && e==ODD) { 
            if (odd >= sz) {
                odd -= sz;
            } else {
                ans+=2;
            }
        }

        // handle even/odd and odd/even cases
        if ((s==ODD && e==EVN) || (s==EVN && e==ODD)) {
            ans++;
        }

        // reset if a case is found
        if (s!=NONE && e!=NONE) {
            s=p[i]%2;
            e=NONE;
            sz=0;
        }
    }

    // account for the start of the sequence
    if (s_sz>0) {
        if (s_p==ODD) {
            if (odd >= s_sz) {
                odd -= s_sz;
            } else {
                ans++;
            }
        } else {
            if (evn >= s_sz) {
                evn -= s_sz;
            } else {
                ans++;
            }
        }
    }

    // account for the end of the sequence
    if (e_sz>0) {
        if (e_p==ODD) {
            if (odd >= e_sz) {
                odd -= e_sz;
            } else {
                ans++;
            }
        } else {
            if (evn >= e_sz) {
                evn -= e_sz;
            } else {
                ans++;
            }
        }
    }

    cout << ans << endl;
}