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

    print("\n----- MinHeap Test -----\n")

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

    print("\n----- Singly Linked List Test -----\n")

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

def dll_tester():

    print("\n----- Doubly Linked List Test -----\n")

    s = -10**6
    e = 10**6
    op_count = 10**4

    print(f"Creating {op_count} nodes...\n")

    start_t = time.perf_counter()
    for i in range(op_count):
        DoubleNode(None, i)
    end_t = time.perf_counter()

    print(f"Creating {op_count} nodes O(1): {end_t - start_t}\n")

    dll = DoublyLinkedList()

    print(f"Prepending {op_count} nodes...\n")

    start_t = time.perf_counter()
    for _ in range(op_count):
        dll.prepend(random.randint(s, e))
    end_t = time.perf_counter()

    print(f"Prepending nodes O(1): {end_t - start_t}\n")

    print(f"Appending {op_count} nodes...\n")

    start_t = time.perf_counter()
    for _ in range(op_count):
        dll.append(random.randint(s, e))
    end_t = time.perf_counter()

    print(f"Appending {op_count} nodes O(1): {end_t - start_t}\n")

    print(f"Inserting {op_count} nodes in random spots...\n")

    start_t = time.perf_counter()
    for i in range(op_count):
        dll.insert(i, random.randint(0, dll.size))
    end_t = time.perf_counter()

    print(f"Inserting {op_count} nodes O(1)")
    print(f"Traversing {op_count} nodes O(n)")
    print(f"Total time: {end_t - start_t}\n")

    print(f"Removing {op_count} nodes in random spots...\n")

    start_t = time.perf_counter()
    for i in range(op_count):
        dll.remove(i)
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
    dll = None

def sorting_algos_tester():

    print("\n----- Sorting Algorithms Test -----\n")

    s = -10**6
    e = 10**6
    op_count = 10**4

    print("----- Bubble Sort -----\n")

    print(f"Generating {op_count} random numbers...\n")

    arr = get_random_ints(list_size = op_count, start_v = s, end_v = e)

    print("Sorting...\n")

    start_t = time.perf_counter()
    bubble_sort(arr)
    end_t = time.perf_counter()

    print("Checking if the arr is sorted...")
    is_sorted = is_arr_sorted(arr = arr, ascending_order = True)
    print(f"The arr is sorted: {is_sorted}\n")

    print(f"Bubble sort O(n^2): {end_t - start_t}\n")


    print("----- Selection Sort -----\n")

    print(f"Generating {op_count} random numbers...\n")

    arr = get_random_ints(list_size = op_count, start_v = s, end_v = e)

    print("Sorting...\n")

    start_t = time.perf_counter()
    selection_sort(arr)
    end_t = time.perf_counter()

    print("Checking if the arr is sorted...")
    is_sorted = is_arr_sorted(arr = arr, ascending_order = True)
    print(f"The arr is sorted: {is_sorted}\n")

    print(f"Selection sort O(n^2): {end_t - start_t}\n")


    print("----- Insertion Sort -----\n")

    print(f"Generating {op_count} random numbers...\n")

    arr = get_random_ints(list_size = op_count, start_v = s, end_v = e)

    print("Sorting...\n")

    start_t = time.perf_counter()
    insertion_sort(arr)
    end_t = time.perf_counter()

    print("Checking if the arr is sorted...")
    is_sorted = is_arr_sorted(arr = arr, ascending_order = True)
    print(f"The arr is sorted: {is_sorted}\n")

    print(f"Insertion sort O(n^2): {end_t - start_t}\n")


    op_count = 10**7

    print("----- Merge Sort -----\n")

    print(f"Generating {op_count} random numbers...\n")

    arr = get_random_ints(list_size = op_count, start_v = s, end_v = e)

    print("Sorting...\n")

    start_t = time.perf_counter()
    arr = merge_sort(arr)
    end_t = time.perf_counter()

    print("Checking if the arr is sorted...")
    is_sorted = is_arr_sorted(arr = arr, ascending_order = True)
    print(f"The arr is sorted: {is_sorted}\n")

    print(f"Merge sort O(nlogn): {end_t - start_t}\n")


    print("----- Quick Sort -----\n")

    print(f"Generating {op_count} random numbers...\n")

    arr = get_random_ints(list_size = op_count, start_v = s, end_v = e)

    print("Sorting...\n")

    start_t = time.perf_counter()
    quick_sort(arr, 0, len(arr) - 1)
    end_t = time.perf_counter()

    print("Checking if the arr is sorted...")
    is_sorted = is_arr_sorted(arr = arr, ascending_order = True)
    print(f"The arr is sorted: {is_sorted}\n")

    print(f"Quick sort O(nlogn): {end_t - start_t}\n")

    print("----- Bucket Sort Test -----\n")

    s = -10**6
    e = 10**6
    op_count = 10**6

    print(f"Generating {op_count} uniformly distributed numbers...\n")

    arr = get_random_ints(list_size = op_count, start_v = s, end_v = e)

    print("Sorting...\n")

    start_t = time.perf_counter()
    bucket_sort(arr, insertion_sort)
    end_t = time.perf_counter()

    print("Checking if the arr is sorted...")
    is_sorted = is_arr_sorted(arr = arr, ascending_order = True)
    print(f"The arr is sorted: {is_sorted}\n")

    print(f"Bucket sort O(n + k) with uniformly distributed data: {end_t - start_t}\n")

    print("----- Passed -----\n")

    start_t = None
    end_t = None
    s = 0
    e = 0
    op_count = 0
    arr = []

def binary_search_tester():

    print("\n----- Binary Search Test -----\n")

    arr = []
    op_count = 10**8

    print(f"Generating {op_count} consecutive numbers...\n")

    start_t = time.perf_counter()
    for i in range(op_count):
        arr.append(i)
    end_t = time.perf_counter()

    print(f"Generating {op_count} consecutive numbers took: {end_t - start_t}\n")

    t = arr[len(arr) - 1]

    start_t = time.perf_counter()
    res = binary_search(arr, t)
    end_t = time.perf_counter()

    if res is None:
        print("Value was not found")

    print(f"Binary search O(logn): {end_t - start_t}\n")

    print("----- Passed -----\n")

    start_t = None
    end_t = None
    op_count = 0
    arr = []

def test_runner(argv: list):

    if len(argv) == 1:
        print("No args provided. Try \"all\" to run all tests")
        return 0
    
    if len(argv) == 2 and argv[1] == "all":

        heap_tester()
        sll_tester()
        dll_tester()

        sorting_algos_tester()
        binary_search_tester()

        return 0
    
    for i in range(1, len(argv)):

        choice = argv[i]

        match choice:

            case "heap":
                heap_tester()

            case "sll":
                sll_tester()

            case "dll":
                dll_tester()

            case "sorting_algos":
                sorting_algos_tester()

            case "bs":
                binary_search_tester()

            case _:
                print("Invalid command line arg")
                return 1
            
    return 0
