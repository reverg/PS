word = input()

isPalindrome = 1
for i in range(len(word) // 2):
    if word[i] != word[len(word) - i - 1]:
        isPalindrome = 0
        break

print(isPalindrome)
