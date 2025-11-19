def merge_sort(arr):

    if len(arr) <= 1: # Base case
        return arr
    
    # Slice in two
    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]

    # Keep calling the function until the base case is reached
    left = merge_sort(left)
    right = merge_sort(right)

    # When arr slices are of length 1, merge the sorted arr up
    return merge(left, right)


def merge(left, right):

    l = [] # Merged list
    i = 0 # Left arr pointer
    j = 0 # Right arr pointer

    while (i < len(left) and j < len(right)):

        if left[i] <= right[j]:
            l.append(left[i])
            i += 1

        else:
            l.append(right[j])
            j += 1

    
    # Clean up code
    while i < len(left):
        l.append(left[i])
        i += 1

    while j < len(right):
        l.append(right[j])
        j += 1

    # Return the merged list back to the caller
    return l


# Time:
#   O(n logn) => Slicing and then merging are logn, but sorting is n

# Space:
#   O(n) => Extra space is needed to store the sorted sub-arr's