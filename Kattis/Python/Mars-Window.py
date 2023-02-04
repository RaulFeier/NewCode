
def main():

    t = bool(False)
    y = int(input())

    x = (y - 1) * 12 + 1
    z = y * 12

    for i in range(x, z + 1):
        if i % 26 == 2:
            t = True
    
    if(t):
        print("yes\n")
    else:
        print("no\n")

    return 0

if __name__ == "__main__":
    main()