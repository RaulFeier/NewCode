
def main():
    x = list(range(11, 20))
    y = list(range(21, 30))
    z = list(range(31, 40))

    d = {
      'x' : x,
      'y' : y,
      'z' : z
    }

    print(d['x'][3])
    print(d['y'][2])

if __name__ == "__main__":
    main()