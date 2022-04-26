/*
    MATHEMATICAL ALGORITHMS

    -- Binary Exponentiation
    -- Modular Exponentiation
    -- Fast Exponentiation
    -- Checking Prime
    -- Sieve of Eratosthenes
    -- Prime Factorization
    -- Segmented Sieve
    -- Eucledian algorithm
    -- Extended Eucledian algorithm
    -- Finding Binomial Coefficient

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

// 1. Binary Exponentiation
int binaryExponentiation(int a, int b)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = res * a;

        a = a * a;
        b >>= 1;
    }

    return res;
}

// 2. Modular Exponentiation
int modularExponentiation(int a, int b, int m)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;

        a = (a * a) % m;
        b >>= 1;
    }

    return res;
}

// 3. Fast Exponentiation
int fastExponentiation(int a, int b, int m)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (res + a) % m;

        a = (a * 2) % m;
        b >>= 1;
    }

    return res;
}

// 4. Prime Checking
bool checkPrime(int n)
{
    if (n <= 1)
        return false;

    bool isPrime = true;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }

    return isPrime;
}

// 5. Sieve of Eratosthenes
vector<int> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    return primes;
}

// 6. Prime Factorization
vector<pair<int, int>> primeFactorization(int n)
{
    vector<pair<int, int>> factors;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }

            factors.push_back({i, cnt});
        }
    }
    if (n != 1)
        factors.push_back({n, 1});

    return factors;
}

// 7. Segmented Sieve Algorithm
vector<int> segmentedSieve(int n)
{
    const int SIZE = 1000;

    vector<int> primes;
    primes = sieve(sqrt(n));

    vector<int> resultPrimes;
    vector<char> block(SIZE);

    for (int k = 0; k * SIZE <= n; k++)
    {
        block.assign(SIZE, '1');
        int start = k * SIZE;

        for (int p : primes)
        {
            int startIndex = (start + p - 1) / p;
            int j = max(startIndex, p) * p - start;

            for (; j < SIZE; j += p)
                block[j] = '0';
        }
        if (k == 0)
            block[0] = block[1] = false;

        for (int i = 0; i < SIZE && start + i <= n; i++)
            if (block[i] == '1')
                resultPrimes.push_back(start + i);
    }

    return resultPrimes;
}

// 8. Eucledian ALgorithm
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 9. Extended Eucledian Algorithm
pair<int, int> extendedEucleadian(int a, int b)
{
    if (b == 0)
        return {1, 0};

    pair<int, int> res = extendedEucleadian(b, a % b);

    int x = res.second;
    int y = res.first - (a / b) * res.second;

    return {x, y};
}

// 10. Finding Binomial Coefficient
int binomialCoefficient(int n, int k)
{
    vector<vector<int>> table(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
                table[i][j] = 1;
            else
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        }
    }
    return table[n][k];
}

// int32_t main() { return 0; }
 
