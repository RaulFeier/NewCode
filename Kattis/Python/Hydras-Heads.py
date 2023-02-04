
def main():
    h = 1
    t = 1
    c = 0

    while True:
        h, t = input().split()
        h, t = int(h), int(t)
        
        if h == 0 and t == 0:
            break
        
        c = 0

        while t > 1:
            t -= 2
            c += 1
            h += 1

        if t == 1:
            t -= 1
            c += 2
            h += 1
        
        while h > 1:
            h -= 2
            c += 1

        if h == 1:
            c += 4
        
        if c > 0:
            print(c, end="\n")
        else:
            print(-1, end="\n")

    return 0

if __name__ == "__main__":
    main()        