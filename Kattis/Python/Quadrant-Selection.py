
def main():
    
    x = int(input())
    y = int(input())
    
    if x > 0 and y > 0:
        print("1\n")
    elif x < 0 and y > 0:
        print("2\n")
    elif x < 0 and y < 0:
        print("3\n")
    elif x > 0 and y < 0:
        print("4\n")

if __name__ == '__main__':
    main()