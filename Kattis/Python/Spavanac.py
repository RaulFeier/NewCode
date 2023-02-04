
def main():
    h, m = input().split()
    h, m = int(h), int(m)
    if(m >= 45):
        m -= 45
    else:
        m += 15
        h -= 1
    
    if(h < 0):
        h += 24

    print(h, m, end="\n")

if __name__ == "__main__":
    main()