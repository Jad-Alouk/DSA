from math import sqrt

# Helper to determine the number of buckets
def bucket_count(n, limit = 10_000):

    if n <= limit: # Small to medium n's: just create n buckets
        return n
    
    # Large n's: take (k) the square root of n, and create k buckets
    return max(1, int(sqrt(n))) # We use max(...) to ensure n > 0


def bucket_sort(arr, sort_func):

    n = len(arr)

    if n <= 1:
        return arr

    # Find min and max (normalization step)
    min_v = min(arr)
    max_v = max(arr)

    # Edge case: all values are equal
    if min_v == max_v:
        return arr

    # Create buckets
    k = bucket_count(n)
    buckets = [[] for _ in range(k)]

    # Cache the data range
    range_v = max_v - min_v

    # Distribute elements into buckets
    for num in arr:

        normalized = (num - min_v) / range_v  # Linear normalization

        # Edge case: normalized num == 1.0 => bi = n (index out of bound)
        bi = min(int(k * normalized), k - 1)

        buckets[bi].append(num)

    # Sort and concat all buckets
    i = 0
    for bucket in buckets:

        # Soting helper must sort in place
        sort_func(bucket)

        for num in bucket:
            arr[i] = num
            i += 1

    return arr


# Time:
#   n = input size
#   k = number of buckets
#
#   Best case: O(n + k) => Data is perfectly distributed
#   Average case: O(n + k) => Data is uniformly distributed (each bucket has about n/k elements)
#   Worst case: O(n^2) => All elements fall into a single bucket

# Space:
#   O(n + k) => Extra space is needed to store n elements across k auxiliary buckets