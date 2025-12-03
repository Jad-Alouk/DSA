import random
from Data_Structures import *

def get_random_ints(list_size: int, start_v: int, end_v: int):
    
    arr = []
    for _ in range(list_size):
        arr.append(random.randint(start_v, end_v))

    return arr

def is_valid_min_heap(arr: list):

    n = len(arr)

    for i in range(n):

        left = 2 * i + 1
        right = 2  *i + 2

        if left < n and arr[i] > arr[left]:
            return False
        
        if right < n and arr[i] > arr[right]:
            return False
        
    return True

def is_heap_valid_after_push(heap: MinHeap, rand_int_count: int, start_v: int, end_v: int):

    for _ in range(rand_int_count):

        v = random.randint(start_v, end_v)
        heap.heap_push(v)

    if not is_valid_min_heap(heap.heap):
        raise AssertionError("Heap property violated after heap_push")
    
    print(f"Pushing {rand_int_count} elements was successful\n")

def is_heap_valid_after_pop(heap: MinHeap, heap_size: int):

    for _ in range(heap_size):

        heap.heap_pop()

    if not is_valid_min_heap(heap.heap):
        raise AssertionError("Heap property violated after heap_pop")
    
    print(f"Popping {heap_size} elements was successful\n")
