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
    for (int i = n-1; i >= 0 ; i--)
    {
        for (int j = 0; j <= i-1 ; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
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