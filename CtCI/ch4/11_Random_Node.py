from Tree import *


if __name__ == "__main__":
    tree = BinaryTree()
    arr = [1, 0, 6, 2, 3, 9, 4, 5, 8, 7]
    for n in arr:
        tree.insert(n)

    cnt = [0 for _ in range(10)]
    for _ in range(1000000):
        d = int(str(tree.get_random_node()))
        cnt[d] += 1

    print(*cnt)
