def insertion_sort(arr):

    n = len(arr)

    for i in range(1, n): # Start from i = 1 to look back at the elements

        # Save the ith value
        key = arr[i]

        # Look at the prev element
        j = i - 1

        # Loop back from ith pos (j) to 0 to find a bigger value than key
        while j >= 0 and arr[j] > key:
            
            # If bigger value is found, shift the prev element one step ahead
            arr[j + 1] = arr[j]

            # Keep looping back
            j -= 1

        # Insert key at the correct pos
        arr[j + 1] = key


# Time:
#   O(n^2) => Nested loops
#   O(n) => If arr is already sorted

# Space:
#   O(1) => No extra space needed