def bubble_sort(arr):

    n = len(arr)

    for i in range(n - 1): # Last element is trivially sorted

        swapped = False # Optimization to break early in case the arr is sorted

        # -1 because inside we have [j + 1] and -i to not loop over already sorted elements
        for j in range(n - i - 1):

            if arr[j] > arr[j + 1]:

                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True

        if not swapped: # If no elements are swapped then arr is sorted
            break

# Time:
#   O(n^2) => Nested loops
#   O(n) => If arr is already sorted the "swapped" flag would stop the execution

# Space:
#   O(1) => No extra space needed