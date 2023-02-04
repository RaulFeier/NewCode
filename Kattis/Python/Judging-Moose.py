
def main():
    l, r = input().split()
    l = int(l)
    r = int(r)

    if(l > r):
        x = l * 2
        print("Odd", x, end="\n")
    if(r > l):
        x = r * 2
        print("Odd", x, end="\n")
    if(l == r and l != 0 and r != 0):
        x = r * 2
        print("Even", x, end="\n")
    if(l == 0 and r == 0):
        print("Not a moose\n")

if __name__ == "__main__":
    main()