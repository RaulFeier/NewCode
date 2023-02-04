
def main():
    while True:
        inputs = list(map(float,input().split(' ')))
        if(len(inputs)==1):
            break

        val = pow(abs((inputs[2] - inputs[0])) ** inputs[4] + abs((inputs[3] - inputs[1])) ** inputs[4], 1 / inputs[4])
        print(val)

if __name__ == main():
    main()
