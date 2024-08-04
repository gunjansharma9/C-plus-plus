#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>&v,int size){
    for(int round=1;round<size;round++){
        bool swapped = false;
        for(int j=0;j<size-round-1;j++){
            if(v[j] > v[j+1]){
                swapped = true;
                swap(v[j],v[j+1]);
            }
        }

        if(swapped == false){
            // sort ho chuka hai,no need to check further rounds
            break;
        }
    }
}
// ith largest element ko uski shi position pr le aao
int main(){
    vector<int>v{2,2,2,6,7,6,7,4,15,12,65,47,89,90,99};
    int size = v.size();

    BubbleSort(v,size);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}

// O(n2)