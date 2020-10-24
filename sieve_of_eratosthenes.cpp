#include <iostream>
#include <string.h>

using namespace std;

void find_prime (int n) {
    bool primes[n+1];
    memset(primes, true, sizeof(primes));
    for (int i = 2; i*i <= n; i++) {
        if (primes[i]) {
            for (int j = i*i; j <= n; j += i) {
                    primes[j] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (primes[p])
            cout << p << " ";
    } 
}

int main() {
    int n;
    cin >> n;
    find_prime(n);
    return 0;
}