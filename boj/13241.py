A, B = map(int, input().split())
if A < B:
    A, B = B, A

prod = A * B
while B != 0:
    A, B = B, A % B
lcm = prod / A
print(int(lcm))
