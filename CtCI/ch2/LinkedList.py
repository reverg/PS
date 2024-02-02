class Node:
    def __init__(self, data, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev

    def __str__(self):
        return str(self.data)


class LinkedList:
    def __init__(self, datas=None):
        self.head = None
        self.tail = None
        if datas is not None:
            for data in datas:
                self.insert(data)

    def __iter__(self):
        curr = self.head
        while curr:
            yield curr
            curr = curr.next

    def __str__(self):
        values = [str(x) for x in self]
        return " ".join(values)

    def insert(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
        else:
            self.tail.next = Node(data)
            self.tail = self.tail.next
