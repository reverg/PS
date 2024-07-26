import sys

input = sys.stdin.readline

if __name__ == "__main__":
    A, P = map(int, input().split())

    D = [A]
    tmp = 0
    while True:
        tmp = 0
        for s in str(D[-1]):
            tmp += int(s) ** P
        if tmp in D:
            break
        D.append(tmp)

    print(D.index(tmp))
