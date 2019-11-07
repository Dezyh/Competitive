// https://codeforces.com/contest/1251/problem/C
    
#include <bits/stdc++.h>
    
using namespace std;
    
#define pb push_back

typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; 
    cin >> t;
    
    while(t-->0) {
    
        vi a;
        string s;
        cin >> s;
        int n = s.size();
        
        int i = 0; //odd 
        int j = 0; //even
    
        while(i<n || j<n) {
    
            // find next odd
            int o = s[i]-'0';
            while(i<n && o%2==0) {
                o = s[++i]-'0';
            }
    
            // find next even
            int e = s[j]-'0';
            while(j<n && e%2==1) {
                e = s[++j]-'0';
            }
    
            // use min of next odd or even
            if (i >= n) {
                a.push_back(e);
                j++;
            } else if (j >= n) {
                a.push_back(o);
                i++;
            } else if (o <= e) {
                a.push_back(o);
                i++;
            } else {
                a.push_back(e);
                j++;
            }
        }
    
        // output test case
        for (int k=0; k<n; k++) {
            cout << a.at(k);
        }
        cout << '\n';
    }
    return 0;
}