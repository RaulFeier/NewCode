tc = int(input())

for i in range(tc):
    a, b = map(int, input().split())
    t = input()
    s = input()

    total = 0
    while True:
        if total > 10:
            print(-1)
            break

        if s in t:
            print(total)
            break
        else:
            t += t
            total += 1
