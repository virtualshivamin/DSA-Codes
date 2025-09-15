/*
Selection Sort
*/

#include <iostream>
using namespace std;

int main()
{
    int n,temp; 
    cout << "Input array size.";
    cin >> n;

    int a[n]; 

    cout << "Input array no : " << endl; 

    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; 
    }

    cout << "Array display : " << endl; 

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl; 
    }

    cout << "Array after sorting." << endl; 

    // Strivers logic ( Complexity O(n^2) for best, average and worst case ) 
    for (int i = 0; i < n - 1 ; i++)
    {
        int mini = i; 
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[mini])
            {
                mini = j;
            }
            temp = a[mini];
            a[mini] = a[i];
            a[i] = temp;
        }
        
    }
    
    /* My logic 

    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        
    }
    
    */
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl; 
    }

    return 0;
}