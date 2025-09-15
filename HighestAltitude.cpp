/* C++ program to print

Example 1:

Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.
Example 2:

Input: gain = [-4,-3,-2,-1,4,3,2]
Output: 0
Explanation: The altitudes are [0,-4,-7,-9,-10,-6,-3,-1]. The highest is 0.

*/


#include <iostream>
using namespace std;

int main()
{
    int size,highest=0; 
    cout << "Input array size : "; 
    cin >> size; 
    int arr[size];
    cout << "Input array numbers :"; 
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            arr[i] = 0 + arr[i]; 
        }
        if(i!=0){
            arr[i] = arr[i-1] + arr[i]; 
        }
    }
    
    cout << "New array is :"; 
    for (int i = 0; i < size; i++)
    {
        if (highest < arr[i])
        {
            highest = arr[i]; 
        }
        
        cout<<arr[i] << " ";
    }

    cout << endl << "Highest No. : " << highest << "."; 

	return 0;
}
