words = []
max_length = 0

for _ in range(5):
    word = input()
    words.append(word)
    max_length = max(max_length, len(word))

result = ""
for i in range(max_length):
    for j in range(5):
        if i < len(words[j]):
            result += words[j][i]

print(result)
