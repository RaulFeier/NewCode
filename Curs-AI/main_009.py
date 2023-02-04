
def main():
    t = [('ca',('cat', 'car', 'fear', 'center')), ('o',('cat', 'dog', 'shatter', 'donut', 'at', 'todo', ''))]
    for i in t:
        (a, b) = i

        ln = []
        for e in b:
            if a in e:
                ln.append(e)
        
        print(ln)


if __name__ == "__main__":
    main()