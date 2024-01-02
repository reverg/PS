numbers = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

N, B = input().split()
answer = 0
for pow, num in enumerate(N[::-1]):
    answer += (int(B) ** pow) * numbers.index(num)

print(answer)
# same result: print(int(N, int(B))) 