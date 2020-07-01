#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef vector<bool> vb;

void io(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

vi sieve(int n) {
    vb k(n-1, true);  
    k[0]=false;
    k[1]=false;
    auto sq=sqrt(n)+1;
    for (int i=2;i<sq;i++) {                                                               
        if (k[i]==true) {                                                            
            for (int j=i+i;j<n;j+=i) {                                                       
                k[j]=false; 
            }
        }
    }
    vi primes;
    for (int i=0;i<n-2;i++) {
        if (k[i]==true) {
            primes.pb(i);
        }
    }
    return primes;
}

int main() {
    io();
    int x; cin >> x;

    // generate primes
    vi primes=sieve(x);

    // generate primes with O(logn) lookup
    set<int> lookup;
    for (int i=0; i<(int)primes.size(); i++) {
        lookup.insert(primes[i]);
    }

    int steps=0;
    int back=primes.size()-1;

    // step through until reaching the end
    while (x>2) {

        // ensure the prime is smaller than x
        int prime=primes[back--];
        while (prime>x) {
            prime=primes[back--];
        }

        // ensure that the x-prime is also a prime
        int small=x-prime;
        while (lookup.find(small)==lookup.end()) {
            prime=primes[back--];
            small=x-prime;
        }

        // update the new x and steps
        x=prime-small;
        steps++;
    }
    cout << steps << endl;
}