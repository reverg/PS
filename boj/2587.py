numbers = []
for _ in range(5):
    numbers.append(int(input()))

for i in range(4):
    for j in range(i + 1, 5):
        if numbers[i] > numbers[j]:
            tmp = numbers[i]
            numbers[i] = numbers[j]
            numbers[j] = tmp

sum = 0
for i in range(5):
    sum += numbers[i]

print(sum // 5)
print(numbers[2])
