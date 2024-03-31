//  pattern matching algorithm.

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;


int main (){

string text="abxabcabcaby";
string pat="aabaabaaa";
vector<int>lps(pat.size(),0);
int j=0,i=1;
while (i<pat.size())
{

    
    if(pat[i]!=pat[j] && j!=0 ){
        j=lps[j-1];
        if(i==8){
            cout<<j;
        }
    }
    if(pat[i]==pat[j]) {
        
        lps[i]=j+1;
        j++;
    }
    i++;
}

// for(auto i: lps)cout<<i<<" ";


return 0;

}