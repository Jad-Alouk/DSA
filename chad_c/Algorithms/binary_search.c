#include <stddef.h>

int binary_search(int *arr, size_t size, int target)
{
    if (size == 0)
    {
        return -1;
    }

    long l = 0;
    long r = (long)(size - 1);

    while (l <= r)
    {
        long mid = l + (r - l) / 2;

        if (arr[mid] == target)
        {
            return (int)mid;
        }

        else if (arr[mid] < target)
        {
            l = mid + 1;
        }

        else
        {
            r = mid - 1;
        }
    }

    return -1;
}
