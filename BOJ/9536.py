import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    sounds = list(map(str, input().rstrip().split()))

    known = []
    while True:
        animal = list(map(str, input().rstrip().split()))
        if animal[0] == "what":  # does the fox say?
            break
        while animal[2] in sounds:
            sounds.remove(animal[2])

    print(" ".join(sounds))
