def binary_search(arr, target):

    l = 0
    r = len(arr) - 1

    # Keep shrinking until there are no values to check in each half
    while l <= r:

        mid = l + (r - l) // 2

        if arr[mid] == target:
            return mid
        
        # Shift the l to mid + 1 if the target is in the right half
        elif arr[mid] < target:
            l = mid + 1

        # Shift the r to mid - 1 if the target is in the left half
        else:
            r = mid - 1

    return None


# Time:
#   O(logn) => Number of steps until n becomes 1 is log_2(n)

# Space:
#   O(1) => No extra space needed