
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void RotateArray(vector<int>&vec){
    int low=0,high=vec.size()-1;
    while(low<high){
        int temp= vec[low];
        vec[low]=vec[high];
        vec[high]= temp;
        low++;
        high--;
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
}

void LinearSearch(vector<int>&abc,int ele){
    bool flag=false;
    for(int i=0;i<abc.size();i++){
        if(abc[i]==ele){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"Found"<<"\n";
    }
    else{
        cout<<"Not Found"<<"\n";
    }
}

void BinarySearch(vector<int>&vec,int ele){
    int low=0,high=vec.size()-1;
    bool flag=false;
    while(low<=high){
        int mid=(low+high)/2;
        if(vec[mid]==ele){
            flag=true;
            break;
        }
        else if(vec[mid]>ele){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(flag){
        cout<<"Found"<<"\n";
    }
    else{
        cout<<"Not Found"<<"\n";
    }
}

int main()
{
    // int arr[]={10,20,30,40,50};
    // cout<<arr[1]<<"\n";
    
    // cout<<sizeof(arr[0])<<"\n";
    
    // cout<<sizeof(arr)<<"\n";
    
    // int lengthOfArray= sizeof(arr)/sizeof(arr[0]);
    
    // for(int i=0;i<lengthOfArray;i++){
    //     cout<<arr[i]<<" ";
    // }
    
    // for(int Daksh: arr){
    //     cout<<Daksh<<" ";
    // }
    
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    
    
    
    // vector
    // vector<int>vec;
    // cout<<vec.capacity()<<"\n";//0
    // cout<<vec.size()<<"\n"; //0
    
    // vec.push_back(10);
    // cout<<vec.capacity()<<"\n";//1
    // cout<<vec.size()<<"\n"; //1
    
    // vec.push_back(20);
    // cout<<vec.capacity()<<"\n";//2
    // cout<<vec.size()<<"\n"; //2
    
    // vec.push_back(30);
    // cout<<vec.capacity()<<"\n";//4
    // cout<<vec.size()<<"\n";//3
    
    // vec.push_back(40);
    // cout<<vec.capacity()<<"\n";//4
    // cout<<vec.size()<<"\n"; //4
    
    // vec.push_back(50);
    // cout<<vec.capacity()<<"\n";//8
    // cout<<vec.size()<<"\n"; //5
    
    // int n=5;
    // vector<int>vec(5,60);
    // vec.push_back(-1);
    // for(int i=0;i<vec.size();i++){
    //     cout<<vec[i]<<" ";
    // }
    
    // int n=5;
    // vector<int>vec(5,0);
    // for(int i=0;i<vec.size();i++){
    //     cin>>vec[i];
    // }
    // for(int i=0;i<vec.size();i++){
    //     cout<<vec[i]<<" ";
    // }
    
    
    vector<int>vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    cout<<vec.capacity()<<"\n";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    
    vec.pop_back();
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
   
    
    vec.insert(vec.begin()+1,60);
     for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    
    vec.insert(vec.begin()+4,70);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    
    vec.erase(vec.begin());
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    
    vec.erase(vec.begin()+3);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    
    vec.push_back(-5);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<"\n";
    
    vector<int>vec2;
    vec2.push_back(10);
    vec2.push_back(0);
    vec2.push_back(-5);
    vec2.push_back(16);
    vec2.push_back(2);
    for(int i=0;i<vec2.size();i++){
        cout<<vec2[i]<<" ";
    }
    cout<<"\n";
    RotateArray(vec2);
    
    LinearSearch(vec2,-5);
    sort(vec2.begin(),vec2.end());
    BinarySearch(vec2,13);
    return 0;
}

