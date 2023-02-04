
def main():
    a, b, c = input().split()
    a, b, c = int(a), int(b), int(c)

    if(a + b == c):
        print(a, "+", b, "=", c, "\n", sep="")
    elif(a - b == c):
        print(a, "-", b, "=", c, "\n", sep="")
    elif(a * b == c):
        print(a, "*", b, "=", c, "\n", sep="")
    elif(a / b == c):
        print(a, "/", b, "=", c, "\n", sep="")
    elif(a == b + c):
        print(a, "=", b, "+", c, "\n", sep="")
    elif(a == b - c):
        print(a, "=", b, "-", c, "\n", sep="")
    elif(a == b * c):
        print(a, "=", b, "*", c, "\n", sep="")
    elif(a == b / c):
        print(a, "=", b, "/", c, "\n", sep="")
    
    return 0

if __name__ == '__main__':
    main()