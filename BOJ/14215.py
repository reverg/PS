sides = []
sides = list(map(int, input().split()))
sides.sort()

print(sides[0] + sides[1] + min(sides[2], sides[0] + sides[1] - 1))
