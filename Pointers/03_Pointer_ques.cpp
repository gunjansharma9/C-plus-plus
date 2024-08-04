#include  "bits/stdc++.h"
using namespace std;

void changeSign(int *p){
    *p = (*p) * -1;
}

void fun(int a[]){
    cout<<a[0]<<" ";
}

void square(int *p){
    int a=10;
    p = &a;
    *p = (*p)*(*p);
    cout<<*p<<" ";
}

void Q(int z){
    z += z;
    cout<<z<<" ";
}

void P(int *y){
    int x = *y + 2;
    Q(x);
    *y = x - 1;
    cout<<x<<" ";
}

int f(int x,int *py,int **ppz){
    int y,z;
    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;
    return x+y+z;
}

void increment(int **p){
    (**p)++;
}
int main(){
    // // ques 1
    // float f = 10.5;
    // float p = 2.5;
    // float* ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout<<*ptr<<" "<<f<<" "<<p;

    // // ques 2
    // int a = 7;
    // int b = 17;
    // int *c = &b;
    // *c = 7;
    // cout<<a<<" "<<b<<endl;

    // // ques 3
    // int *ptr = 0;
    // int a = 10;
    // *ptr = a;
    // cout<<*ptr<<endl;
    // this code will give error as we r trying to dereference a null pointer

    // //ques 4
    // int b = 10;
    // int *a = &b;
    // cout<<a<<endl;
    // cout<<&b<<endl;


    // // ques 5
    // char ch = 'a';
    // char* ptr = &ch;
    // ch++;
    // cout<<*ptr<<endl;


    // // ques 6
    // int a = 7;
    // int *c = &a;
    // c = c+1;
    // cout<<a<<" "<<*c<<endl;


    // // ques 7
    // int a = 7;
    // int *c = &a;
    // c = c+3;
    // cout<<c<<endl;

    // // ques 8
    // double a = 10.54;
    // double *d = &a;
    // d = d+1;
    // cout<<d<<endl;

    // // ques 9
    // int a[5];
    // int *c;
    // cout<<sizeof(a)<<" "<<sizeof(c);

    
    // // ques 10
    // int a[] = {1,2,3,4};
    // cout<<*(a)<<" "<<*(a+1);


    // // ques 11
    // int a[3] = {1,2,3};
    // cout<<*(a+2)<<endl;


    // // ques 12
    // int a[] = {1,2,3,4};
    // int *p = a++;
    // cout<<*p<<endl;
    // // error bcoz a is a constant pointer we can't change it


    // // ques 13
    // int arr[] = {4,5,6,7};
    // int *p = (arr+1);
    // cout<<*arr+9;
    // // *arr toh first element pr hi point kr rha h


    // // ques 14
    // char b[] = "xyz";
    // char *c = &b[0];
    // cout<<c<<endl;
    // // it will print xyz bcoz character array nature is different


    // // ques 15
    // char s[] = "hello";
    // char *p = s;
    // cout<<s[0]<<" "<<p[0];


    // // ques 16
    // char arr[20];
    // int i;
    // for(i=0;i<10;i++){
    //     *(arr+i) = 65 + i;
    // }
    // *(arr+i) = '\0';
    // cout<<arr;


    // // ques 17
    // char *ptr;
    // char Str[] = "abcdefg";
    // ptr = Str;
    // ptr += 5;
    // cout<<ptr;


    // // ques 18
    // int numbers[5];
    // int *p;
    // p = numbers;
    // *p =  10;
    // p = &numbers[2];
    // *p = 20;
    // p--;
    // *p = 30;
    // p = numbers + 3;
    // *p = 40;
    // p = numbers;
    // *(p+4) = 50;
    // for(int n=0;n<5;n++){
    //     cout<<numbers[n]<<",";
    // }


    // // ques 19
    // char st[] = "ABCD";
    // for(int i=0;st[i] != '\0';i++){
    //     cout<<st[i]<<*(st)+i<<*(i+st)<<i[st];
    // }



    // // ques 20
    // float arr[5] = {12.5,10.0,13.5,90.5,0.5};
    // float *ptr1 = &arr[0];
    // float *ptr2 = ptr1 + 3;
    // cout<<*ptr2<<" ";
    // cout<<ptr2 - ptr1;


    // // ques 21
    // int a = 10;
    // changeSign(&a);
    // cout<<a<<endl;


    // // ques 22
    // int a[] = {1,2,3,4};
    // fun(a+1);
    // cout<<a[0];


    // // ques 23
    // int a = 10;
    // square(&a);
    // cout<<a<<endl;


    // // ques 24
    // int x = 5;
    // P(&x);
    // cout<<x;


    // // ques 25
    // int a = 10;
    // int *p = &a;
    // int **q = &p;
    // int b = 20;
    // *q = &b;
    // (*p)++;
    // cout<<a<<" "<<b<<endl;
    // // this is imp ques


    // // ques 26
    // int c,*b,**a;
    // c = 4;
    // b = &c;
    // a = &b;
    // cout<<f(c,b,a);
    // return 0;


    // // ques 27
    // int ***r,**q,*p,i=8;
    // p = &i;
    // (*p)++;
    // q = &p;
    // (**q)++;
    // r = &q;
    // cout<<*p<<" "<<**q<<" "<<***r;


    // // ques 28
    // int num = 10;
    // int *ptr = &num;
    // increment(&ptr);
    // cout<<num<<endl;
}