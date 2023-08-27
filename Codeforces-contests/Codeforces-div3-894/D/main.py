def combinations(n):
    return n * (n - 1) // 2

def minimum_balls_needed(n):
    left = 0
    right = n

    while left < right:
        mid = (left + right) // 2
        if combinations(mid) >= n:
            right = mid
        else:
            left = mid + 1

    return left

# Read the number of test cases
t = int(input())

# Iterate through each test case
for _ in range(t):
    n = int(input())
    result = minimum_balls_needed(n)
    print(result)
