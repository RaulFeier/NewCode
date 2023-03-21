
def main():
    tc = int(input())

    while tc > 0:
        tc -= 1

        n = int(input())
        s = input()

        check = False
        for i in range(n):
            if i < n - 1 and s[i] == s[i + 1]:
                check = True
                break

        if check:
            print("NO")
        else:
            print("YES")

main()