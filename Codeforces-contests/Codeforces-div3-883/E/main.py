t = int(input())

for _ in range(t):
    n = int(input())

    found = False
    if n >= 7:
        n1 = n - 1
        if n1 % 2 == 0:
            for i in range(3, 1000000):
                if n1 % int(i) == 0:
                    print("YES")
                    found = True
                    break

    if found == False:
        print("NO")
