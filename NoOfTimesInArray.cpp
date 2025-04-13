#include <iostream>
using namespace std;

int NoOfTimes(int a,int ar[], int s)
{
    int count=0;
    for (int i = 0; i < s; i++)
    {
        if (ar[i] == a)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int s; 
    cout << "Input array size : "; 
    cin >> s; 
    int arr[s];
    cout << "Input array numbers :"; 
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    int no; 
    cout << "Input No to check no of times : "; 
    cin >> no; 

    cout << "No. of times " << no << " in array is : " << NoOfTimes(no,arr,s)<<endl; 

	return 0;
}
