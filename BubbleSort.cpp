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

    /*

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

    */

    // Strivers logic ( Complexity O(n^2) for average and worst case and O(n) for Best case ) 
    for (int i = n-1; i >= 0 ; i--)
    {
        int didswap = 0;
        for (int j = 0; j <= i-1 ; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                ++didswap;
            }
        }
        // iss case me agar array sorted hai to aage nahi chalega iss se best case ka complexity O(n) rahega
        if (didswap == 0) 
        {
            break;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl; 
    }

    return 0;
}