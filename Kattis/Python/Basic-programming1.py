from itertools import count
import math

def main():
    n, t = input().split()
    n = int(n)
    t = int(t)
    
    a = input().split()
    a = [int(i) for i in a]

    if t == 1:

        print("7\n")
    
    elif t == 2:

        if a[0] > a[1]:
            print("Bigger\n")
        elif a[0] < a[1]:
            print("Smaller\n")
        else:
            print("Equal\n")

    elif t == 3:
        
        c = []
        for i in range(3):
            c.append(a[i])
        c.sort()

        print(c[1], end="\n")

    elif t == 4:

        ans = sum(a)
        print(ans, end="\n")

    elif t == 5:

        ans = 0
        for i in range(n):
            if a[i] % 2 == 0:
                ans += a[i]

        print(ans, end="\n")


    elif t == 6:

        for i in range(n):
            a[i] = a[i] % 26
            print(chr(97 + a[i]), end="")

        print("\n")

    elif t == 7:

        i = 0
        count = 0
        while count < 2 * n:
            i = a[i]
            count += 1
            if i >= n:
                print("Out\n")
                return 0
            elif i == n - 1:
                print("Done\n")
                return 0
        
        print("Cyclic\n")
    
    return 0


if __name__ == "__main__":
    main()