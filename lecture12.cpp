#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
// void fun(int *p){
//   *p=45;
//   cout<<*p<<"\n";
// }
// void fun1(int &k){
//   k=k+1;
//   cout<<k<<"\n";
// }
// void fun2(vector<int>&arr){
//   arr[4]=1000;
//   cout<<arr[4]<<"\n";
// }


class student{
  public:
  string name;
  int roll;
  int marks;

  //Default Constructor
  student(){
    cout<<"Default Constructor"<<"\n";
  }

  // Parameterized Constructor
  student(string name,int roll,int marks){
    this->name=name;
    this->roll=roll;
    this->marks=marks;
  }
  void play(){
    cout<<name<<" can play"<<"\n";
  }

};

int main() {
    // int a=10;
    // int *p=&a;
    // int **q=&p;
    // int ***r=&q;

    // int arr[]={1,13,45,2,17};
    // int *p=arr;
    // cout<<p<<" "<<arr<<"\n";
    // cout<<*(p+0)<<" "<<*(arr+0)<<" "<<arr[0]<<"\n";
    // cout<<*(p+1)<<" "<<*(arr+1)<<" "<<arr[1]<<"\n";
    // cout<<*(p+2)<<" "<<*(arr+2)<<" "<<arr[2]<<"\n";
    // cout<<*(p+3)<<" "<<*(arr+3)<<" "<<arr[3]<<"\n";

    // int a=10;
    // fun(&a);
    // cout<<a<<"\n";

    // int a=10;
    // int &k=a;
    // fun1(a);
    // cout<<a<<"\n";


    // vector<int>arr={10,13,145,1,54,45};
    // int *p=arr.data();
    // *(p+1)=100;
    // cout<<arr[1]<<"\n";
    // fun2(arr);
    // cout<<arr[4]<<"\n";
    // student st1;
    // st1.name="Jethalal";
    // st1.roll=16;
    // st1.marks=99;

    // cout<<st1.name<<" "<<st1.roll<<" "<<st1.marks<<"\n";

    student st1={"Jetahalal",16,99};
    vector<student>arr={{"Jetahalal",16,99},{"Bhide",4,83},{"Iyer",13,89},{"Popatlal",26,84}};
    for(int i=0;i<arr.size();i++){
      cout<<arr[i].name<<" "<<arr[i].roll<<" "<<arr[i].marks<<"\n";
    }
    cout<<"\n";
    sort(arr.begin(),arr.end(),[](student &a,student &b){
      return a.marks<b.marks;
    });
    for(student ele: arr){
      cout<<ele.name<<" "<<ele.roll<<" "<<ele.marks<<"\n";
    }
    return 0;
}
