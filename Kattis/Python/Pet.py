from re import A


def main():
    w = 0
    p = 0
    
    for i in range(1, 6):
        a,b,c,d = input().split()
        a = int(a)
        b = int(b)
        c = int(c)
        d = int(d)
        if a + b + c + d > p:
            w = i
            p = a + b + c + d
    
    print(w, p, end="\n")

if __name__ == "__main__":
    main()