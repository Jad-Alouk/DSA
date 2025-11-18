def selection_sort(arr):

    n = len(arr)

    for i in range(n - 1): # Last element is trivially sorted

        min_idx = i # Select i to be the smallest value

        for j in range(i + 1, n): # Loop over all elements ahead of i

            if arr[j] < arr[min_idx]: # Find the true smallest value

                min_idx = j

        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# Time:
#   O(n^2) => Nested loops

# Space:
#   O(1) => No extra space needed