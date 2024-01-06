def gcd(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a


a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())

c1 = a1 * b2 + b1 * a2
c2 = a2 * b2
g = gcd(c1, c2)

print(f"{int(c1/g)} {int(c2/g)}")
