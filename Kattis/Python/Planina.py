
def main():
    a = int(input())

    s = 2
    for i in range(a):
        s *= 2
        s -= 1
    
    print(s * s, end="\n")

if __name__ == "__main__":
    main()