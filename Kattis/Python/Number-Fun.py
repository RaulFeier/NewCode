
def main():
    
    t = int(input())

    while t > 0:

        a, b, c = input().split()
        a, b, c = int(a), int(b), int(c)

        pos = False

        if a + b == c:
            pos = True
        if a * b == c:
            pos = True
        if a - b == c:
            pos = True
        if b - a == c:
            pos = True
        if a % b == 0 and a / b == c:
            pos = True
        if b % a == 0 and b / a == c:
            pos = True
        
        if pos:
            print("Possible")
        else:
            print("Impossible")

        t -= 1
    
if __name__ == '__main__':
    main()