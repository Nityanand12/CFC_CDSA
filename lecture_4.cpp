#include<iostream>
#include<math.h>
using namespace std;
void quesF(){
  int n=3;
  int id=1,nst=1,nsp=n-1;
  while(id<=2*n-1){
    int csp=1;
    while(csp<=nsp){
      cout<<" ";
      csp++;
    }
    int cst=1;
    while(cst<=nst){
      cout<<"*";
      cst++;
    }
    cout<<"\n";
    if(id<n){
      nsp=nsp-1;
      nst=nst+2;
    }
    else{
      nsp=nsp+1;
      nst=nst-2;
    }
    id++;
  }
}
void baseTenToTwo(){
   int num= 25,power=1,ans=0;
   while(num!=0){
     int rem= num%2;
     ans=power*rem+ans;
     power=power*10;
     num=num/2;
   }

   cout<<ans<<"\n";

}
void baseTwoToTen(){
  int ans=11001;
  int power = 0;
   int nans=0;
   while(ans!=0){
     int rem= ans%10;
     nans=nans+rem*pow(2,power);
     ans=ans/10;
     power=power+1;
   }
   cout<<nans<<"\n";
}
int main(){
  //  quesF();
   baseTenToTwo();
  // baseTwoToTen();     
   return 0;
}