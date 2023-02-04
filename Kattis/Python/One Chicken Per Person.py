

def main():
    a, b = input().split()
    a = int(a)
    b = int(b)

    b -= a

    if b < 0:
        if(b == -1):
            print("Dr. Chaz needs", -b, "more piece of chicken!\n")
        else:
            print("Dr. Chaz needs", -b, "more pieces of chicken!\n")
    else:
        if(b == 1):
            print("Dr. Chaz will have", b, "piece of chicken left over!\n")
        else:
            print("Dr. Chaz will have", b, "pieces of chicken left over!\n")
    
if __name__ == '__main__':
    main()
