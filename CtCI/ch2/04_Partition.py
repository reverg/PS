from LinkedList import LinkedList


def partition(ll, x):
    # make new linked list
    curr = ll.tail = ll.head

    while not (curr is None):
        next = curr.next
        if curr.data < x:
            curr.next = ll.head
            ll.head = curr
        else:
            ll.tail.next = curr
            ll.tail = curr
        curr = next
    ll.tail.next = None


ll = LinkedList([10, 0, 99])
print(ll)
partition(ll, ll.head.data)
print(ll)
