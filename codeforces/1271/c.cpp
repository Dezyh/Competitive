#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    int n, sx, sy;
    cin >> n >> sx >> sy;
    int u=0, d=0, l=0, r=0;
    
    for (int i=0; i<n; i++) {

        cin >> x >> y;
        if (y>sy) {
            u++;
        }
        if (y<sy) {
            d++;
        }
        if (x>sx) {
            r++;
        }
        if (x<sx) {
            l++;
        }
    }

    if (u>d && u>r && u>l) {
        cout << u << "\n" << sx << " " << sy+1;
    } else if (r>d && r>l) {
        cout << r << "\n" << sx+1 << " " << sy;
    } else if (d>l) {
        cout << d << "\n" << sx << " " << sy-1;
    } else {
        cout << l << "\n" << sx-1 << " " << sy;
    }
}