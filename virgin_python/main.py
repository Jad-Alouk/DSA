import time
from helpers import *
from Algorithms import *
from Data_Structures import *

# Time perf
start_t = None
end_t = None

# Size of random int arr
s = 0
e = 0

# Op counter
op_count = 0

# Helpers
arr = []


# ----- Heap -----

print("\n")
print("----- MinHeap Test -----\n")

s = -10**6
e = 10**6
op_count = abs(s) + abs(e)
arr = get_random_ints(list_size = op_count, start_v = s, end_v = e)

print(f"Heapify a random list of ints (size: {op_count}):\n")

heap = MinHeap()

start_t = time.perf_counter()
heap.heapify(arr)
end_t = time.perf_counter()

print(f"The resulting min heap is {"valid" if (is_valid_min_heap(arr = heap.heap)) else "invalid"}\n")
print(f"Heapify O(n): {end_t - start_t}\n")

print(f"Pushing {op_count} elements...\n")

start_t = time.perf_counter()
is_heap_valid_after_push(heap = heap, rand_int_count = op_count, start_v = s, end_v = e)
end_t = time.perf_counter()

print(f"Heap push O(logn): {end_t - start_t}\n")

op_count = len(heap)

print(f"Popping {op_count} elements...\n")

start_t = time.perf_counter()
is_heap_valid_after_pop(heap = heap, heap_size = op_count)
end_t = time.perf_counter()

print(f"Heap pop O(logn): {end_t - start_t}\n")

print("----- Passed -----\n")

start_t = None
end_t = None
s = 0
e = 0
op_count = 0
arr = []

# ----- Heap -----