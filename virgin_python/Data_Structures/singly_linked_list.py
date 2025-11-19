class Node:

    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

    def __repr__(self):
        return f"<Node: {self.data}>"


class SinglyLinkedList:

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def __len__(self):
        return self.size

    def __repr__(self):

        if self.head is None:
            return "[]"
        
        nodes = []
        curr = self.head

        while curr:

            if curr is self.head:
                nodes.append(f"[Head: {curr.data}]")

            elif curr is self.tail:
                nodes.append(f"[Tail: {curr.data}]")

            else:
                nodes.append(f"[{curr.data}]")

            curr = curr.next

        return " --> ".join(nodes)
    

    def prepend(self, data):
        new_node = Node(data, self.head)
        self.head = new_node

        if self.tail is None:
            self.tail = new_node

        self.size += 1
        return new_node

    def append(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            self.tail = new_node
        
        else:
            self.tail.next = new_node
            self.tail = new_node

        self.size += 1
        return new_node

    def insert(self, data, i):

        if i < 0 or i > self.size:
            raise IndexError("Position is out of bound")

        if i == 0:
            return self.prepend(data)

        if i == self.size:
            return self.append(data)


        curr = self.head

        for _ in range(i - 1):
            curr = curr.next

        new_node = Node(data, curr.next)
        curr.next = new_node

        self.size += 1
        return new_node

    def remove(self, key):
        
        if self.head is None:
            return None
        
        curr = self.head
        prev = None

        while curr:

            if curr.data == key:

                if curr is self.head:
                    self.head = curr.next

                    if self.head is None:
                        self.tail = None

                else:
                    prev.next = curr.next

                    if curr is self.tail:
                        self.tail = prev

                self.size -= 1
                return curr

            prev = curr
            curr = curr.next

        return None