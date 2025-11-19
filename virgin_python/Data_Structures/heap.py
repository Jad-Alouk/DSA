class MinHeap:

    def __init__(self):
        self.heap = []

    def __len__(self):
        return len(self.heap)
    
    def __repr__(self):
        return str(self.heap)
    

    def heapify(self, elements):
        self.heap = list(elements)
        
        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self._sift_down(i)

    def heap_push(self, val):

        self.heap.append(val)
        self._sift_up(len(self.heap) - 1)

    def heap_pop(self):
        
        if not self.heap:
            raise ValueError("Heap is empty")
        
        min_el = self.heap[0]
        last_el = self.heap.pop()

        if self.heap:
            self.heap[0] = last_el
            self._sift_down(0)

        return min_el

    def _parent(self, i):
        return (i - 1) // 2 if i > 0 else None

    def _left(self, i):
        left = 2 * i + 1
        return left if left < len(self.heap) else None

    def _right(self, i):
        right = 2 * i + 2
        return right if right < len(self.heap) else None

    def _sift_up(self, i):
        
        parent_idx = self._parent(i)

        while parent_idx is not None and self.heap[parent_idx] > self.heap[i]:

            self.heap[parent_idx], self.heap[i] = self.heap[i], self.heap[parent_idx]

            i = parent_idx
            parent_idx = self._parent(i)

    def _sift_down(self, i):
        
        while True:

            smallest = i
            left = self._left(i)
            right = self._right(i)

            if left is not None and self.heap[smallest] > self.heap[left]:
                smallest = left

            if right is not None and self.heap[smallest] > self.heap[right]:
                smallest = right

            if smallest == i:
                break

            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            i = smallest