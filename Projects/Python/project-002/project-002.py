
def main():
    a = input().split()
    a = [int(i) for i in a]

    ans = 0
    for i in range(4):
        if a[i] % 2 == 0:
            ans += a[i]
    print(ans)

if __name__ == "__main__":
    main()