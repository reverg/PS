import sys

input = sys.stdin.readline

month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
week = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]

x, y = map(int, input().split())

diff = (y - 1)
for i in range(x-1):
    diff += month[i]
print(week[diff % 7])