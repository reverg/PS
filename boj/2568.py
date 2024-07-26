import sys, bisect

input = sys.stdin.readline


if __name__ == "__main__":
    N = int(input())
    lines = []
    for _ in range(N):
        src, dst = map(int, input().split())
        lines.append((src, dst))
    lines.sort()

    # get LIS length
    seq = []
    seq.append(lines[0][1])
    dp_len = [-1] * N
    for i in range(N):
        if seq[-1] < lines[i][1]:
            seq.append(lines[i][1])
            dp_len[i] = len(seq)
        else:
            idx = bisect.bisect_left(seq, lines[i][1])
            seq[idx] = lines[i][1]
            dp_len[i] = idx + 1

    # print the number of removed liens
    print(N - len(seq))

    # get LIS sequence
    LIS = []
    l = len(seq)
    for i in range(N - 1, -1, -1):
        if l == 0:
            break
        if dp_len[i] == l:
            LIS.append(lines[i])
            l -= 1

    # get removed lines
    removed = []
    for line in lines:
        if line not in LIS:
            removed.append(line)

    # sort and print
    removed.sort()
    for i in range(len(removed)):
        print(removed[i][0])
