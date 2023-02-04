

def main():
    a = input().split()
    a = [int(i) for i in a]

    ans = sum(a)

    print(ans)

if __name__ == "__main__":
    main()