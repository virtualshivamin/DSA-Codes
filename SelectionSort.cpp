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
    
    for (int i = 0; i < n; i++)
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
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl; 
    }

    return 0;
}