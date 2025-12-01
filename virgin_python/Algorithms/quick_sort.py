import random

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def partition(arr, low, high):

    # Randomizing to avoid worst case
    pi = random.randint(low, high)
    swap(arr, pi, high)

    pivot = arr[high]
    i = low - 1
    
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)

    # Insert pivot at correct spot and return its index
    swap(arr, i + 1, high)
    return i + 1

def quick_sort(arr, low, high):

    if low < high: # Base case
        
        # Get partition index
        pi = partition(arr, low, high)
        
        # Keep calling the function until the base case is reached
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


# Time:
#   O(n logn) => Partitioning is logn and sorting is n

# Space:
#   O(n) => Recursive function calls