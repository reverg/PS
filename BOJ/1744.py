import sys

input = sys.stdin.readline


if __name__ == "__main__":
    N = int(input())

    # divide numbers to positiva and negative
    arr_pos, arr_zero, arr_neg = [], 0, []
    for _ in range(N):
        n = int(input())
        if n > 0:
            arr_pos.append(n)
        elif n == 0:
            arr_zero += 1
        else:
            arr_neg.append(n)
    
    ans = 0
    arr_pos.sort()
    arr_neg.sort(reverse=True)
    
    # tie positive numbers
    while len(arr_pos) >= 2:
        n1 = arr_pos.pop()
        n2 = arr_pos.pop()

        if n2 > 1:
            ans += n1 * n2
        else:
            ans += n1 + n2
            break
    while arr_pos:
        ans += arr_pos.pop()

    # tie negative numbers
    while len(arr_neg) >= 2:
        n1 = arr_neg.pop()
        n2 = arr_neg.pop()
        ans += n1 * n2
    if arr_neg and arr_zero == 0:
        ans += arr_neg.pop()

    print(ans)
