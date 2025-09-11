// bubble sort
// tc...best=O(N)....avg=O(n**2)...worst=O(n**2)
// sc....O(1)
#include <iostream>
using namespace std;

// void bubbleSort(vector<int>& arr) {
//         // code here
//         int n=arr.size();
//         for (int i = n-2; i >=0; i--)
//         {
//             bool swapped = 0;
//             for (int j = 0; j <=i; j++)
//             {
//                 if (arr[j] > arr[j + 1])
//                 {
//                     swap(arr[j],arr[j + 1]);
//                     swapped = 1;
//                 }
//             }
//             if (swapped==0)
//             break;
//         }
//     }

int main()
{
    int arr[1000];
    int n;
    cout << "enter the size of array:";
    cin >> n;
    cout << "enter the element in array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        bool swapped = 0;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}