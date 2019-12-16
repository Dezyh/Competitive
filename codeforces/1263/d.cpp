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
    
void make_set(int v, int parent[], int rank[], int sets) {
    parent[v] = v;
    rank[v] = 0;
    sets++;
}

int find_set(int v, int parent[]) {
    if (v == parent[v])
        return v;
    parent[v] = find_set(parent[v], parent);
    return parent[v];
}

void union_sets(int a, int b, int parent[], int rank[], int sets) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        sets--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sets = 0;
    int rank[26];
    int parent[26];

    for (int p=0; p<26; p++) {
        parent[p] = -1;
    }

    int np;
    cin >> np;

    for (int pi=0; pi<np; pi++) {

        string p;
        cin >> p;

        for (int pc=0; pc<(int)(p.size()-1); pc++) {

            int c1 = p[pc]-'0';
            int c2 = p[pc+1]-'0';

            int sc1 = find_set(c1, parent);
            int sc2 = find_set(c2, parent);

            if (sc1 == -1) {
                make_set(c1, parent, rank, sets);
            }

            if (sc2 == -1) {
                make_set(c2, parent, rank, sets);
            }

            sc1 = find_set(c1, parent);
            sc2 = find_set(c2, parent);

            union_sets(sc1, sc2, parent, rank, sets);
        }       
    }

    cout << sets << "\n";
}