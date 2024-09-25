#include <bits/stdc++.h>
using namespace std;

int main(){
    string alphabet; cin >> alphabet;
    string hum; cin >> hum;
    size_t alphaIdx = 0;
    size_t humIdx = 0;
    while (humIdx < hum.size()){
        if (alphabet[alphaIdx % 26] == hum[humIdx]){
            ++humIdx;
        }
        ++alphaIdx;
    }
    if (alphaIdx % 26 == 0){
        cout << alphaIdx/26;
    }
    else{
        cout << alphaIdx/26 + 1;
    }
}