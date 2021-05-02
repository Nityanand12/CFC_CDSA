#include<iostream>
using namespace std;

void ques1(){
  int id=0;
  int nst=1;
  while(id<5){
    int cst=1;
    while(cst<=nst){
      cout<<"*";
      cst++;
    }
    cout<<"\n";
    nst=nst+1;
    id=id+1;
  }
}
void ques2(){
  int id=0;
  int nst=1;
  while(id<5){
    int cst=1;
    while(cst<=nst){
      cout<<cst;
      cst++;
    }
    cout<<"\n";
    nst=nst+1;
    id=id+1;
  }
}
void nques1(){
  int n=5;
  int nsp=n-1,nst=1,id=0;
  while(id<5){
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
    nsp=nsp-1;
    nst=nst+1;
    id++;
  }
}
void nques2(){
  int n=5;
  int nsp=n-1,nst=1,id=0;
  while(id<5){
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
    nsp=nsp-1;
    nst=nst+2;
    id++;
  }
}
void nques3(){
  int n=5;
  int nsp=n-1,nst=1,id=0;
  while(id<5){
    int csp=1;
    while(csp<=nsp){
      cout<<" ";
      csp++;
    }
    int cst=1;
    while(cst<=nst){
      cout<<cst;
      cst++;
    }
    cout<<"\n";
    nsp=nsp-1;
    nst=nst+2;
    id++;
  }
}
void ques3(){
   int n=5;
  int nsp=n-1,nst=1,id=0;
  while(id<5){
    int csp=1;
    while(csp<=nsp){
      cout<<" ";
      csp++;
    }
    int cst=1;
    while(cst<=nst){
      int k=cst;
      if(k>(nst+1)/2){
        k= nst-cst+1;
      }
      cout<<k;
      cst++;
    }
    cout<<"\n";
    nsp=nsp-1;
    nst=nst+2;
    id++;
  }
}

int main(){
  //*****;
  // int id=1;
  // while(id<=5){
  //   cout<<"*";
  //   id=id+1;
  // }
  // ques1();
  // ques2();
  // nques1();
  // nques2();
  // nques3();

  ques3();
}
