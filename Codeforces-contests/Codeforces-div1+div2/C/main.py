def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
 
    while low <= high:
 
        mid = (high + low) // 2
 
        # If x is greater, ignore left half
        if arr[mid] < x:
            low = mid + 1
 
        # If x is smaller, ignore right half
        elif arr[mid] > x:
            high = mid - 1
 
        # means x is present at mid
        else:
            return True
 
    # If we reach here, then the element was not present
    return False

def main():
    tc = int(input())

    while tc > 0:
      n, x, f = map(int, input().split())

      l = []

      for i in range(0, f):
         l.append((i + 1) * (1 + (1 + i)) / 2)

      res = n - x

      while True:
        if res > l[-1]:
            print("No", end='\n')
            break
         
        if binary_search(l, res):
             print("Yes", end='\n')
             break
        else:
            res += n
      tc -= 1

if __name__ == "__main__":
    main()