    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define pb push_back
    #define mp make_pair
    #define MOD 998244353
     
    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef unordered_map<int, int> mii;
     
    inline int power(ll a, int m){
        ll ans=1;
        while(m) {
            if (m&1) ans=(a*ans)%MOD;
            a=(a*a)%MOD;
            m>>=1;
        }
        return ans;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
     
        int n; cin >> n;
        vi k(n);
        vvi l(n);
        mii cnts;
        for (int i=0; i<n; i++) {
            cin >> k[i]; 
            for (int j=0; j<k[i]; j++) {
                int v; cin >> v; 
                cnts[v]++;
                l[i].pb(v); 
            }
        }   
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<l[i].size(); j++) {
                int p = l[i][j];
                int inv_n = power(n, MOD-2);
                int inv_ki = power(k[i], MOD-2);
                ll s = cnts[p];
                s = (s*inv_ki)%MOD;
                s = (s*inv_n)%MOD;
                s = (s*inv_n)%MOD;
                ans = (ans+s)%MOD;
            }
        }

        cout << ans << "\n";
    }