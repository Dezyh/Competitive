#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define tests int t; cin>>t; while(t--)
typedef pair<uint, uint> pi;
void io(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

bool valid(uint x) {
    for (int p=2; p<32; p++) {
        if (x==(1<<p)-1)
            return true;
    }
    return false;
}

void solve(int _x, int _y) {
    bool hr = (_x<0);
    bool vr = (_y<0);
    uint x = abs(_x);
    uint y = abs(_y);
    uint s = 0;
    uint ba = 0;
    uint bb = 0;
    for (uint a=0; a<x; a++) {
        if ((x|a) != x) continue;
        for (uint b=0; b<y; b++) {
            if ((y|b) != y) continue;
            if (a+b<s) {
                s=a+b;
                ba=a;
                bb=b;
            }
        }
    }




}

pair<uint,uint> solve(uint x, uint y) {
    for (uint a=1; a<x; a++) {
        if ((x|a) != x) continue;
        //cout << "a: " << a << endl;
        for (uint b=1; b<y; b++) {
            if ((y|b) != y) continue;
            //cout << "    b: " << b << endl;
            if ((((a|(x+a))&(b|(y+b)))==0) && correct(a|(x+a)|b|(y+b)))
                return {a,b};
        }
    }
    return {0,0};
}

int main() {
    io();
    tests {
        int x, y; 
        cin >> x >> y;

        

        uint x = (uint)abs(_x);
        uint y = (uint)abs(_y);

        pair<uint,uint> v = solve(x, y);
        uint a = v.ff;
        uint b = v.ss;

        if (a==0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        uint l, r, d, u;

        if (hr) {
            l = x+a;
            r = a;
        } else {
            l = a;
            r = x+a;
        }

        if (vr) {
            d = y+b;
            u = b;
        } else {
            d = b;
            u = y+b;
        }

        uint p = 0;
        uint c = 1;

        while (p++ < 32) {
            if (l&c)
                cout << 'W';
            if (r&c)
                // u&c
                cout << 'N';
            if (u&c)
                // r&c
                cout << 'E';
            if (d&c)
                cout << 'S';
            c <<= 1;
        }
        cout << endl;
    }
}