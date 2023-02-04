
def main():
    g,s,c = input().split()
    g = int(g)
    s = int(s)
    c = int(c)

    p = 3*g + 2*s + c
    if p >= 8:
        print("Province", "or", end=" ")
    elif p >= 5:
        print("Duchy", "or", end=" ")
    elif p >= 2:
        print("Estate", "or", end=" ")
    elif p < 0:
        print("Copper\n")
    if p >= 6:
        print("Gold\n")
    elif p >= 3:
        print("Silver\n")
    elif p >= 0:
        print("Copper\n")

if __name__ == '__main__':
    main()
