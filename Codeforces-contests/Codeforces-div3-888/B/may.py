def can_sort_array(n, arr):
    # Count the number of odd and even elements
    odd_count = sum(1 for num in arr if num % 2 == 1)
    even_count = n - odd_count

    # Check if it's possible to sort the array
    if (odd_count % 2 == 0 and even_count % 2 == 0) or \
            (odd_count % 2 == 1 and even_count % 2 == 1 and len(set(arr)) < n):
        return "YES"
    else:
        return "NO"


# Read the input and process each test case
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    result = can_sort_array(n, arr)
    print(result)
