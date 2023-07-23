def can_cover_area(sizes, w, c):
    required_area = 0
    for size in sizes:
        required_area += (size + 2 * w) ** 2
        if required_area > c:
            return False
    return True


def find_w_for_cardboard(test_cases):
    results = []
    for sizes, c in test_cases:
        lo, hi = 0, 10**9
        while lo < hi:
            mid = (lo + hi) // 2
            if can_cover_area(sizes, mid, c):
                lo = mid + 1
            else:
                hi = mid
        results.append(lo - 1)
    return results


t = int(input())
test_cases = []
for _ in range(t):
    n, c = map(int, input().split())
    sizes = list(map(int, input().split()))
    test_cases.append((sizes, c))

for result in find_w_for_cardboard(test_cases):
    print(result)
