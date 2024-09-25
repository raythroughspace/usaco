#include <bits/stdc++.h>
using namespace std;

// let t1 and t2 be # of USED intransitive verbs and transitive verbs
// want t1 + 2*t2 <= nouns -> that way can form t1+ t2 "sentences"
// max # of conj used is min(T/2, conj), if t1 + t2 <= P + min(T/2, conj) then have enough periods to form sentences
// So loop through possible pairs of t1 and t2, check conditions, keep track of max # of words and max sentence
// max # of words is t1 +t2 + t1 + 2*t2 + min(T/2, conj) + min(C, remaining nouns)
// Construct sentence:
// make t1 + t2 sentences all with periods, in t2 sentence #1: add min(C, remaining nouns). 
int main(){
    size_t T; cin >> T;
    for (size_t t=0; t< T; ++t){
        size_t N,C,P; cin >> N >> C >> P;
        stack<string> conj;
        stack<string> tverb;
        stack<string> iverb;
        stack<string> noun;
        for (size_t n=0; n<N; ++n){
            string word, type; cin >> word >> type;
            if (type == "transitive-verb"){
                tverb.push(word);
            }
            else if (type == "intransitive-verb"){
                iverb.push(word);
            }
            else if (type == "noun"){
                noun.push(word);
            }
            else{
                conj.push(word);
            }
        }
        size_t maxWords = 0;
        size_t T1,T2; T1 = T2 = 0;
        for (size_t t1 = 0; t1 <= iverb.size(); ++t1){
            for (long t2=tverb.size(); t2 >= 0; --t2){
                if (t1+2*t2 > noun.size() || t1 + t2 > P + min((t1 + t2)/2, conj.size()) || t1 + t2 ==0){
                    continue;
                }
                size_t nWords = 2*t1 + 3*t2 + min((t1+t2)/2, conj.size());
                if (t2 != 0){
                    nWords += min(C, noun.size() - t1 - 2*t2);
                }
                if (nWords > maxWords){
                    T1 = t1; T2 = t2;
                    maxWords = nWords;
                }
            }
        }
        cout << maxWords << "\n";
        string largestStr = "";
        size_t nconj = min((T1 + T2)/2, conj.size());
        size_t ncommas = min(C, noun.size() - T1 - 2*T2);
        size_t odd = true;
        for (size_t i=0; i<T2; ++i){
            largestStr += noun.top(); noun.pop();
            largestStr += " ";
            largestStr += tverb.top(); tverb.pop();
            largestStr += " ";
            largestStr += noun.top(); noun.pop();
            if (i==0){
                for (size_t j=0; j< ncommas; ++j){
                    largestStr += ", ";
                    largestStr += noun.top(); noun.pop();
                }
            }
            if (odd && nconj > 0){
                largestStr += " ";
                largestStr += conj.top(); conj.pop();
                largestStr += " ";
                odd = false;
                nconj--;
            }
            else{
                largestStr += ". ";
                odd = true;
            }
        }
        for (size_t i=0; i<T1; ++i){
            largestStr += noun.top(); noun.pop();
            largestStr += " ";
            largestStr += iverb.top(); iverb.pop();
            if (odd && nconj > 0){
                largestStr += " ";
                largestStr += conj.top(); conj.pop();
                largestStr += " ";
                odd = false;
                nconj--;
            }
            else{
                largestStr += ". ";
                odd = true;
            }
        }
        if (maxWords >0){
            largestStr.pop_back();
        }
        cout << largestStr << "\n";
    }
}