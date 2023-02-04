def main():
    
    x, y = input().split()
    x, y = int(x), int(y)

    if x == 0 and y == 0:
        return 0 

    while True:

        if x + y == 13:
            print("Never speak again.")
        elif x > y:
            print("To the convention.")
        elif x < y:
            print("Left beehind.")
        else:
            print("Undecided.")
        
        x, y = input().split()
        x, y = int(x), int(y)
        
        if x == 0 and y == 0:
            break
    

if __name__ == '__main__':
    main()