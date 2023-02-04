def sum(v):
    sum = 0
    for i in v:
        sum += i
    return sum

def main():
    v = [int(i) for i in input().split()]
    s = sum(v)

    for i in v:
        print(i, end = " ")

    print()

    print(s)

if __name__ == "__main__":
    main()