#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>

using namespace std;

bool isPrime(int a)
{
    if(a < 2)
        return false;

    for(int i=2; i*i<=a; i++)
        if(a%i == 0)
            return false;
    return true;
}

vector<int> primes(vector<int>a, vector<int>b){
    vector<int> c;
    unordered_map<int, int> cntB; 
    unordered_set<int> showedUpPrime;
    //Bucket sort but pretty.
    for(int i: b)
        cntB[i]++;

    //Sieve of Eratosthenes might be faster but im not sure.
    for(auto i: cntB)
        if(isPrime(i.second))
            showedUpPrime.insert(i.first);
    
    for(int i: a)
        if(showedUpPrime.find(i) == showedUpPrime.end())
            c.push_back(i);
    return c;
}

int main(){
    vector<int> A{2,3,9,2,5,1,3,7,10};
    vector<int> B{2,1,3,4,3,10,6,6,1,7,10,10,10};
    vector<int> C = primes(A, B);
    for(int c: C)
        cout<<c<<" ";
    return 0;
}