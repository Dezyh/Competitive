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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; int k1; int k2;
        cin >> n >> k1 >> k2;
        int p1=0; int p2=0;
        for (int i=0; i<k1; i++) {
            int c; cin >> c;
            if (c > p1) {
                p1 = c;
            }
        }
        for (int i=0; i<k2; i++) {
            int c; cin >> c;
            if (c > p2) {
                p2 = c;
            }
        }
        if (p1 > p2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}