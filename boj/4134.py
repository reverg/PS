import math


def IsPrime(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


def GetNextPrime(n):
    if n == 0 or n == 1:
        return 2
    result = n
    while not IsPrime(result):
        result += 1
    return result


t = int(input())

for _ in range(t):
    n = int(input())
    print(GetNextPrime(n))
