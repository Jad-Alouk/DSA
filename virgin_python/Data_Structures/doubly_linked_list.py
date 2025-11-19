class Node:
    
    def __init__(self, prev = None, data = None, next = None):
        self.prev = prev
        self.data = data
        self.next = next

    def __repr__(self):
        return f"<Node: {self.data}>"


class DoublyLinkedList:
    
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

        return " <--> ".join(nodes)
    

    def prepend(self, data):
        new_node = Node(None, data, self.head)

        if self.head is not None:
            self.head.prev = new_node
        else:
            self.tail = new_node

        self.head = new_node
        self.size += 1

        return new_node

    def append(self, data):
        new_node = Node(self.tail, data, None)

        if self.tail is not None:
            self.tail.next = new_node
        else:
            self.head = new_node

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

        new_node = Node(curr, data, curr.next)
        curr.next.prev = new_node
        curr.next = new_node

        self.size += 1
        return new_node

    def remove(self, key):

        if self.head is None:
            return None
        
        curr = self.head

        while curr:

            if curr.data == key:

                if curr is self.head:
                    self.head = curr.next

                    if self.head:
                        self.head.prev = None
                    else:
                        self.tail = None

                else:
                    curr.prev.next = curr.next
                    
                    if curr.next:
                        curr.next.prev = curr.prev
                    else:
                        self.tail = curr.prev

                self.size -= 1
                return curr

            curr = curr.next

        return None