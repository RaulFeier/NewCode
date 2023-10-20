a, b = map(int, (input().split()))

total = 0
for _ in range(a):
    aa = int(input())
    total += aa

if total > b:
    print("Neibb")
else:
    print("Jebb")

