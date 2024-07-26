isPrime = [True for _ in range(1000001)]


def CheckPrime():
    for i in range(2, 1001):
        if isPrime[i]:
            for j in range(2 * i, 1000001, i):
                isPrime[j] = False


T = int(input())
CheckPrime()

for _ in range(T):
    n = int(input())
    goldbach = 0
    for i in range(2, n // 2 + 1):
        if isPrime[i] and isPrime[n - i]:
            goldbach += 1
    print(goldbach)
