class Node:
    def __init__(self, value, next: type['Node']=None):
        self.value = value
        self.next = next


class SinglyLinkedList:
    def __init__(self, root: Node = None):
        self.root: Node = root
        self.last: Node = root

    def append(self, node: Node):
        self.last.next = node
        self.last = node
