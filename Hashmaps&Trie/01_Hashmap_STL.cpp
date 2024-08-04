#include <iostream>
#include <unordered_map>
using namespace std;

// Map two types -> Ordered & Unordered

// imp question -> insertion,deletion,searching,random O(1) mein perform krke dikhao --> use unordered_map

int main(){
    // creation
    unordered_map<string,int>m;

    // insertion
    pair<string,int>p = make_pair("Scorpio",9);
    m.insert(p);

    pair<string,int>p2("Alto",2);
    m.insert(p2);

    // we can directly insert like this
    m["Fortuner"] = 45;

    // access
    cout<<m.at("Alto")<<endl;
    cout<<m.at("Fortuner")<<endl;

    cout<<m["Fortuner"]<<endl; 

    // search
    // if present ans is 1 otherwise 0
    cout<<m.count("Scorpio")<<endl;

    if(m.find("Fortuner") != m.end()){
        cout<<"Fortuner Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    cout<<m.size()<<endl;
    // important
    cout<<m["hummer"]<<endl;
    cout<<m.size()<<endl;

    cout<<"Printing all entries: "<<endl;

    for(auto i:m){
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    return 0;
} 

