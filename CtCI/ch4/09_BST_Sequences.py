from collections import deque
from Tree import *


def weaveLists(first, second, results, prefix):
    if not first or not second:
        result = prefix + list(first) + list(second)
        results.append(result)
        return

    headFirst = first.popleft()
    prefix.append(headFirst)
    weaveLists(first, second, results, prefix)
    prefix.pop()
    first.appendleft(headFirst)

    headSecond = second.popleft()
    prefix.append(headSecond)
    weaveLists(first, second, results, prefix)
    prefix.pop()
    second.appendleft(headSecond)


def allSequences(node):
    if not node:
        return [[]]

    result = []
    prefix = [node.key]

    leftSeq = allSequences(node.left)
    rightSeq = allSequences(node.right)

    for left in leftSeq:
        for right in rightSeq:
            weaved = []
            weaveLists(deque(left), deque(right), weaved, prefix)
            result.extend(weaved)

    return result


if __name__ == "__main__":
    tree = BinaryTree()
    array = [100, 50, 20, 75, 150, 120, 170]
    for a in array:
        tree.insert(a)

    allSeq = allSequences(tree.root)
    for lst in allSeq:
        print(lst)

    print(len(allSeq))
