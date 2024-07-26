strokes = [3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1]

a = input()
b = input()

arr = []
for i in range(len(a)):
    arr.append(strokes[ord(a[i]) - 65])
    arr.append(strokes[ord(b[i]) - 65])

while len(arr) != 2:
    tmp = []
    for idx in range(1, len(arr)):
        tmp.append((arr[idx - 1] + arr[idx]) % 10)
    arr = tmp

print(f"{arr[0]}{arr[1]}")
