changes = [25, 10, 5, 1]
T = int(input())

for _ in range(T):
    money = int(input())
    result = []
    for coin in changes:
        result.append(money // coin)
        money %= coin
    print(*result)
