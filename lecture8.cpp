#include<iostream>
#include<vector>
using namespace std;
void checkBit(int num, int m){
    int mask=(1<<(m-1));
    if((num&mask)==0){
        cout<<"Off Bit"<<"\n";
    }
    else{
        cout<<"On Bit"<<"\n";
    }
}
void setOnBit(int num, int m){
    int mask=(1<<(m-1));
    num= num|mask;
    cout<<num<<"\n";
}
void setOffBit(int num, int m){
    int mask=(1<<(m-1));
    num= num&(~mask);
    cout<<num<<"\n";
}
void toggleBit(int num, int m){
    int mask=(1<<(m-1));
    num= num^mask;
    cout<<num<<"\n";
}
void ques1(){
    vector<int>arr={4,6,4,7,2,6,7};
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans=(ans^arr[i]);
    }
    cout<<ans<<"\n";
}

void quesNum2(){
    vector<int>arr={2,5,7,5,11,2,7,4};
    int p=0;
    for(int i=0;i<arr.size();i++){
        p=(p^arr[i]);
    }
    int cnt=0;
    int ans=p;
    while(p%2!=1){
        cnt++;
        p=p/2;
    }
    int mask=(1<<cnt),ans1=0;
    for(int i=0;i<arr.size();i++){
        if((mask&arr[i])!=0){
            ans1=ans1^arr[i];
        }
    }
    cout<<ans1<<" "<<(ans1^ans)<<"\n";
}
int main(){
//    checkBit(5,3);
//    setOnBit(5,2);
//    setOffBit(7,2);
//    toggleBit(5,2);
//    ques1();
//    quesNum2();
}