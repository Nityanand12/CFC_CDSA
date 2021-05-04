#include <iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>&arr){
    for(int i=1;i<arr.size();i++){
        int key= arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

void bubbleSort(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        bool swap=false;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap=true;
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(swap==false){
            break;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
void MaximumSumOfSubarray(vector<int>&arr){
    int ans=-1000000,sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        ans=max(ans,sum);
        if(sum<0){
             sum=0;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    int ans=-1000000;
    vector<int>arr={3,-1,-5,2,-1,7};
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum=sum+arr[j];
            ans=max(ans,sum);
        }
    }
    cout<<ans<<"\n";
    MaximumSumOfSubarray(arr);
    vector<int>narr={5,4,3,2,1};
    insertionSort(narr);
    cout<<"\n";
    bubbleSort(narr);
    return 0;
}
