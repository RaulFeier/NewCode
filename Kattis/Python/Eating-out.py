
def main():
    m,a,b,c = input().split()

    m = int(m)
    a = int(a)
    b = int(b)
    c = int(c)

    if (a + b + c)/2 <= m:
        print("possible\n")
    else:
        print("impossible\n")

if __name__ == "__main__":
    main()
