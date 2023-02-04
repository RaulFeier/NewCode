
def main():

    x1, y1 = input().split()
    x2, y2 = input().split()
    x3, y3 = input().split()
    
    x1, y1, x2, y2, x3, y3 = int(x1), int(y1), int(x2), int(y2), int(x3), int(y3)

    if x1 == x2:
        print(x3, end=" ")
    elif x2 == x3:
        print(x1, end=" ")
    else:
        print(x2, end=" ")
    
    if y1 == y2:
        print(y3, end="")
    elif y2 == y3:
        print(y1, end="")
    else:
        print(y2, end="")

if __name__ == "__main__":
    main()
