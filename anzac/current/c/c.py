x = int(input())

def gen_primes(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return ([2] + [i for i in range(3,n,2) if sieve[i]])

def difference(x, ps):
    steps = 0
    while x > 2:
        prime = ps.pop()
        while (prime > x-2):
            prime = ps.pop()
        small = x-prime
        print(small, prime)
        x = prime-small
        steps += 1
    return steps
      	
primes = gen_primes(x)
print(difference(x, primes))