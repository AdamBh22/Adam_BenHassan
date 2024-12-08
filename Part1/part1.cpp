#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define make_pair mp 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vl vector<long long int>
#define pi pair<int,int>
#define pl pair<long long int ,long long int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define endl '\n'
const double eps=1e-12;
int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
const int mod=1e9+7;


 
int main() {
    fast;
    string str;
    cin>>str;
    int n = str.size();
    vector<char> characters;
    // in this vector I am pushing only the alphabatic characters in the form lower
    for(int i=0;i<n;i++){
    	if(isalpha(str[i])){
    		characters.push_back(tolower(str[i]));
    	}
    }
    // if there is no alphabatic character in the string 
    if(characters.size()==0){
    	cout<<"True"<<endl;
    	return 0;
    }
    // I am using the two-pointers method to compare the symetric characters with each others 
    int l = 0 , r = characters.size()-1;
    bool is_palindrome = 1;
    while(l<=r){
    	if(characters[l]!=characters[r]) is_palindrome = 0 ;
    	l++;
    	r--;
    }
    // if I don't find any different symetric characters so that's ok , but if I find two different ones the string is not palindrome
    // this is indicated by the booleen is_palindrome
    if(is_palindrome) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}
