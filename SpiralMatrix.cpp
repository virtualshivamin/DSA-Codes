#include<iostream>
using namespace std;

int main(){
    int arr[4][4] = {
        {3  ,4  ,5  ,6  },
        {7  ,8  ,9  ,10 },
        {11 ,12 ,13 ,14 },
        {15 ,16 ,17 ,18 }
    };
    int size = 4;
    int top = 0;
    int left = 0;
    int right = size-1;
    int bottom = size-1;
    //Time complexity O(n^2)
    while(top<=bottom && left <= right){
        for(int i = left; i<= right; i++)
            cout<<arr[top][i]<<" ";
        for(int i = top+1; i<=bottom; i++)
            cout<<arr[i][right]<<" ";
        for(int j = right-1; j>=left; j--)
            cout<<arr[bottom][j]<<" ";
        for(int j = bottom-1; j> top; j--)
            cout<<arr[j][left]<<" ";
        top++;
        bottom--;
        left++;
        right--;

    }
    
    return 0;
}