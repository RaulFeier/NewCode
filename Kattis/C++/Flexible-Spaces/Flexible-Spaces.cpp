#include <cmath>
#include <iostream>

using namespace ::std;

int main()
{
    int a, n;
    cin >> a >> n;
    int arr[n];
  
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
  
    int room[a];
  
    for (int i = 0; i < a; i++)
    {
        room[i] = 0;
    }
  
    room[a - 1] = a;
  
    for (int i = 0; i < n; i++)
    {
        room[arr[i] - 1] = arr[i];
        room[a - arr[i] - 1] = a - arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            room[abs(arr[i] - arr[j]) - 1] = abs(arr[i] - arr[j]);
        }
    }

    for (int i = 0; i < a; i++)
    {
        if (room[i] > 0)
        {
            cout << room[i] << " ";
        }
    }

    return 0;
}