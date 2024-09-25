#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<size_t> entries(7);
    for (size_t i=0; i<7; ++i){
        cin >> entries[i];
    }
    auto minimum = min_element(entries.begin(), entries.end());
    auto maximum = max_element(entries.begin(), entries.end());
    size_t A = *minimum;
    size_t ABC = *maximum;
    entries.erase(minimum);
    size_t B = *min_element(entries.begin(), entries.end());
    cout << A << " "<< B << " "<< ABC-A-B;
}