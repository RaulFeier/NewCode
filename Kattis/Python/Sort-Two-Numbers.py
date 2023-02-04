
def main():
    a,b = input().split()
    a = int(a)
    b = int(b)
    if a > b:
        print(b, a, end="\n")
    else:
        print(a, b, end="\n")

if __name__ == "__main__":
    main()