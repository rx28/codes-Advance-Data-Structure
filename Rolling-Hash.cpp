//Rabin karp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<stack>
#include <sstream>
#include<unordered_map>
#include<cmath>
using namespace std;

int main(){
    string s="babaa";
    string pat="baa";
    int p=5381,d=26,win_size=3;
    int hash_pat=0,pwr=0,hash_s=0;
    for(int i=pat.size()-1;i>=0;i--){
        hash_pat+=(pat[i]-'a'+1) * (static_cast<int>(pow(d,pwr++)));
        hash_pat%=p;
    }   
    for(int i=0;i<s.size();i++){
        if(i<win_size){
          hash_s+=((s[i]-'a'+1)) * static_cast<int>(pow(d,win_size-i-1));
          hash_s%=p;
          if(hash_s==hash_pat){cout<<i; break;}
        }
        else{
            hash_s-=(s[i-win_size]-'a'+1) * static_cast<int>(pow(d,win_size-1));
            
            hash_s*=d;
            hash_s+=((s[i]-'a'+1)) ;
            hash_s%=p;

            if(hash_s==hash_pat){cout<<"pattern found at "<<i-win_size; break;}
        }
    }
    
    return 0;
}