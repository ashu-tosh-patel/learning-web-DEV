#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <cstring>

using namespace std;
int main(){
    int t;
    cin>>t;
   one: while(t--){
        string s;
        cin>>s;
        int n = s.length();
        set<char> hs;
        for(int i=0; i<n; i++){
            hs.insert(s[i]);
        }
        int mx = hs.size();
        map<char, int> hm;
        for(int i=0; i<n; i++){
            if (hm.find(s[i])!=hm.end())
            {
                auto t = hm.find(s[i]);
                if (i-t<mx)     
                {
                    cout<<"NO"<<endl;
                    // continue one;
                }
                
            }
            
        }
     }
}