import math


def minimum_balls_needed(n):
    x = (1 + math.sqrt(1 + 8 * n)) / 2
    return math.ceil(x)


# Read the number of test cases
t = int(input())

# Iterate through each test case
for _ in range(t):
    n = int(input())
    result = minimum_balls_needed(n)
    print(result)
