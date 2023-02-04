
def main():
    ar = input().split()
    a = [int(x) for x in ar]
    for i in range(len(a) - 1):
        if a[i] == a[i + 1] - 10:
            continue
        print("False")
        return 0
    print("True")

if __name__ == "__main__":
    main()