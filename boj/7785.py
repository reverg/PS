n = int(input())
names = set([])

for _ in range(n):
    name, status = input().split()
    if status == "enter":
        names.add(name)
    else:
        names.remove(name)

sorted_names = sorted(names, reverse=True)
print("\n".join(sorted_names))
