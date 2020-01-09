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



// sum a-j          (0 < a-j <= a)
// xor j            (0 < j < ?)

// else { add j }

// sum = a
// xor = 0

// if (xor==0) { add a }

// sum = 2a
// xor = a

// if (sum==2xor) { done }


        // cout << "s: " << s << endl;
        // cout << "x: " << x << endl;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t; while (t--) {
        int n; cin >> n;
        ll x = 0;
        ll s = 0;
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            x = x^a;
            s += a;
        }
        if (s==2*x) {
            cout << 0 << endl;
            cout << endl;
        } else if (x==0) {
            cout << 1 << endl;
            cout << s << endl;
        } else {
            cout << 2 << endl;
            cout << x << " " << s+x << endl;
        }
    }
}