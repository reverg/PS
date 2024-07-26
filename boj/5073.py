while True:
    sides = []
    sides = list(map(int, input().split()))
    if sides[0] == sides[1] == sides[2] == 0:
        break
    sides.sort()

    if sides[0] + sides[1] <= sides[2]:
        print("Invalid")
    elif sides[0] == sides[1] == sides[2]:
        print("Equilateral")
    elif sides[0] == sides[1] or sides[1] == sides[2] or sides[2] == sides[0]:
        print("Isosceles")
    else:
        print("Scalene")
