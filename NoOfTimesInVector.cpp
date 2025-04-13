#include <iostream>
#include <vector>
using namespace std;

// vector<int> ar is used to give vector as parameter 
int NoOfTimes(int a,vector<int> ar) 
{
    int count=0;
    for (int i = 0; i < ar.size(); i++)
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
    cin >> s; // vector size 
    vector<int> arr(s); //vector create 
    cout << "Input array numbers :"; 
    for (int i = 0; i < s; i++) // for storing no in vector 
    {
        cin >> arr[i];
    }
    int no; // for asking value to know no of times 
    cout << "Input No to check no of times : "; 
    cin >> no; 

    cout << "No. of times " << no << " in array is : " << NoOfTimes(no,arr)<<endl; // Printing no of times 

	return 0;
}
