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


def heap_tester():

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

def sll_tester():

    print("\n")
    print("----- Singly Linked List Test -----\n")

    s = -10**6
    e = 10**6
    op_count = 10**4

    print(f"Creating {op_count} nodes...\n")

    start_t = time.perf_counter()
    for i in range(op_count):
        SingleNode(i)
    end_t = time.perf_counter()

    print(f"Creating {op_count} nodes O(1): {end_t - start_t}\n")

    sll = SinglyLinkedList()

    print(f"Prepending {op_count} nodes...\n")

    start_t = time.perf_counter()
    for _ in range(op_count):
        sll.prepend(random.randint(s, e))
    end_t = time.perf_counter()

    print(f"Prepending nodes O(1): {end_t - start_t}\n")

    print(f"Appending {op_count} nodes...\n")

    start_t = time.perf_counter()
    for _ in range(op_count):
        sll.append(random.randint(s, e))
    end_t = time.perf_counter()

    print(f"Appending {op_count} nodes O(1): {end_t - start_t}\n")

    print(f"Inserting {op_count} nodes in random spots...\n")

    start_t = time.perf_counter()
    for i in range(op_count):
        sll.insert(i, random.randint(0, sll.size))
    end_t = time.perf_counter()

    print(f"Inserting {op_count} nodes O(1)")
    print(f"Traversing {op_count} nodes O(n)")
    print(f"Total time: {end_t - start_t}\n")

    print(f"Removing {op_count} nodes in random spots...\n")

    start_t = time.perf_counter()
    for i in range(op_count):
        sll.remove(i)
    end_t = time.perf_counter()

    print(f"Removing {op_count} nodes O(1)")
    print(f"Traversing {op_count} nodes O(n)")
    print(f"Total time: {end_t - start_t}\n")

    print("----- Passed -----\n")

    start_t = None
    end_t = None
    s = 0
    e = 0
    op_count = 0
    sll = None

def test_runner(argv: list):

    if len(argv) == 1:
        print("No args provided. Try \"all\" to run all tests")
        return 0
    
    if len(argv) == 2 and argv[1] == "all":

        heap_tester()
        sll_tester()

        return 0
    
    for i in range(1, len(argv)):

        choice = argv[i]

        match choice:

            case "heap":
                heap_tester()

            case "sll":
                sll_tester()

            case _:
                print("Invalid command line arg")
                return 1
    return 0
