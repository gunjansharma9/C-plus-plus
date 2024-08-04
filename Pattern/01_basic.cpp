#include "bits/stdc++.h"
using namespace std;

int main(){
    // Hollow rectangle
    for(int i=0;i<3;i++){
        if(i==0 || i==2){
            for(int i=0;i<6;i++){
                cout<<"* ";
            }
        }else{
            cout<<"* ";
            for(int i=0;i<4;i++){
                cout<<"  ";
            }
            cout<<"* ";
        }
        cout<<endl;
    }


    // Half Pyramid
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }cout<<endl;
    }

    // Inverted Hald Pyramid
    for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }cout<<endl;
    }

    // Numeric Half pyramid
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }cout<<endl;
    }

    // inverted numeric half pyramid
    for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }cout<<endl;
    }

    // Full Pyramid

    for(int j=5;j>=1;j--){
        for(int k=1;k<=j;k++){
            cout<<" ";
        }
        for(int m=5;m>=j;m--){
            cout<<"* ";
        }
        cout<<endl;
    }

    // inverted full pyramid
    for(int i=1;i<=6;i++){
        for(int j=1;j<=i-1;j++){
            cout<<" ";
        }
        for(int k=6;k>=i;k--){
            cout<<"* ";
        }
        cout<<endl;
    }

    // inverted hollow pyramid
    int n = 6;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || j==n-i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }

    // full pyramid
    int n1=6;
    for(int i=0;i<n1;i++){
        // space
        for(int col=0;col<n-i-1;col++){
            cout<<" ";
        }
        // stars
        for(int j=0;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // inverted full pyramid
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=n;j>i;j--){
            cout<<"* ";
        }
        cout<<endl;
    }

    // hollow full pyramid
    for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<((2*n)-1);j++){
            if(j<n-i-1){
                cout<<" ";
            }else if(k<2*i+1){
                if(k==0 || k==2*i || i==n-1)
                    cout<<"*";
                else{
                    cout<<" ";
                }
                k++;
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    // Hollow Diamond
    cout<<"Printing hollow diamond"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<=2*i;j++){
            if(j==0 || j==2*i){
                cout<<"* ";
            }else{
                cout<<" ";
            }
        }cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<2*n-2*i-1;j++){
            if(j==0 || j==2*n-2*i-2){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    // Flipped Solid Diamond
    cout<<"Printing Flipped Solid Diamond"<<endl;
    for(int i=0;i<5;i++){
        for(int j=5;j>i;j--){
            cout<<"* ";
        }
        for(int j=0;j<=2*i;j++){
            cout<<"  ";
        }
        for(int j=5;j>i;j--){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        for(int j=2*n-2;j>=2*i;j--){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // Fancy Pattern
    cout<<"PRINTING FANCY PATTERN"<<endl;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=i;j++){
            cout<<i;
            if(j != i){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    for(int i=4;i>=1;i--){
        for(int j=i;j>=1;j--){
            cout<<i;
            if(j != 1){
                cout<<"*";
            }
        }
        cout<<endl;
    }

    // Alphabet Palindrome Pyramid
    cout<<"PRINTING Alphabet Palindrome Pyramid"<<endl;
    for(char i=65;i<=70;i++){
        char j;
        for(j=65;j<i;j++){
            cout<<j<<" ";
        }
        for(char k=j-2;k>=65;k--){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    
    // for(int i=1;i<6;i++){
    //     int start = i;
    //     for(int j=1;j<=i;j++){
    //         cout<<start<<" ";
    //         start = start+1;
    //     }cout<<endl;
    // }

    // Numeric Full Pyramid
    cout<<"Printing Numeric Full Pyramid"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            cout<<" ";
        }
        int start = i+1;
        for(int j=0;j<i+1;j++){
            cout<<start;
            start=start+1;
        }


        start = 2*i;
        for(int col=0;col<i;col++){
            cout<<start;
            start = start-1;
        }
        cout<<endl;
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            cout<<" ";
        }
        int start = 1;
        for(int j=0;j<2*i+1;j++){
            if(i==0 || i==5-1){
                if(j%2 == 0){
                    cout<<start;
                    start = start+1;
                }
                else{
                    cout<<" ";
                }
            }
            else{
                if(j==0){
                    cout<<1;
                }
                else if(j==2*i+1-1){
                    cout<<i+1;
                }else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }

    // Numeric Hollow Half Pyramid
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            if(j==1){
                cout<<1<<" ";
            }
            else if(j==i){
                cout<<j<<" ";
            }
            else if(i==5){
                cout<<j<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }

    // Inverted Half Pyramid
    for(int i=1;i<=5;i++){
        for(int j=i;j<=5;j++){
            if(i==1){
                cout<<j<<" ";
            }else if(j==i){
                cout<<i<<" ";
            }else if(j==5){
                cout<<"5"<<" ";
            }else {
                cout<<"  ";
            }
        }
        cout<<endl;
    }


    // Numeric Palindrome Equilateral Pyramid
    for(int i=1;i<=5;i++){
        for(int j=5;j>i;j--){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }
        for(int j=i-1;j>=1;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    // Fancy Pattern 1
    for(int i=1;i<=5;i++){
        for(int j=i;j<=8;j++){
            cout<<"*";
        }
        for(int j=1;j<=i;j++){
            cout<<i<<"*";
        }
        for(int j=7;j>=i;j--){
            cout<<"*";
        }
        cout<<endl;
    }

    // Fancy Pattern 2
    int k=1;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=2*i-1;j++){
            if(j%2 == 0){
                cout<<"*";
            }else{
                cout<<k++;
            }
        }
        cout<<endl;
    }
    k=6;
    for(int i=4;i>=1;i--){
        for(int j=1;j<=2*i-1;j++){
            if(j%2==0){
                cout<<"*";
            }else{
                cout<<++k;
            }
        }
        k = k-2*(i-1)-1;
        cout<<endl;
    }

    // Floyd's Triangle pattern
    cout<<"Printing Floyd's Pattern"<<endl;
    k=1;
    for(int i=1;i<=7;i++){
        for(int j=1;j<=i;j++){
            cout<<k++<<" ";
        }
        cout<<endl;
    }

    // Pascal's Triangle Pattern
    for(int i=1;i<=6;i++){
        int C = 1;
        for(int j=1;j<=i;j++){
            cout<<C<<" ";
            C = C*(i-j)/j;
        }cout<<endl;
    }

    // Butterfly Pattern
    cout<<"Printing Butterfly Pattern"<<endl;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=5;j>i;j--){
            cout<<" ";
        }
        for(int j=5;j>i;j--){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=5;j>i;j--){
            cout<<" ";
        }
        for(int j=5;j>i;j--){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}