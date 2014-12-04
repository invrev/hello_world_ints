#include<iostream>
#include<unordered_map>
using namespace std;


vector<int> findSubstring(string S, const vector<string> &L) {
    vector<int> result;
    if (S.length() == 0 || L.size() == 0) {
        return result;
    }
    unordered_map<string, int> total;
    unordered_map<string, int> has;
    int total_words = L.size();
    int word_size = L[0].size();
    int searchEnd = S.size() - word_size * total_words;
    
    // store the words and frequencies in a hash table  
    for (int i = 0; i < total_words; ++i) {
        total[L[i]]++;
    }

    //Find concatenation
    for (int i = 0; i <= searchEnd; ++i) {
        int j = i;
        //Clear the has "hashmap before"
        has.clear();
        int iword = 0;
        for (; iword < total_words; ++iword) {

            //For current index get all substring
            //Get the substring from original string
            string sub = S.substr(j, word_size);
            
            //not in L
            if(total[sub] == 0) {
              break;
            }
            //in L, but redundancy
            //increase the has frequency
            if(++has[sub] > total[sub]) {
              break;
            }
            
            j += word_size;
        }
        //found all substrings 
        if(iword == total_words) {
            result.push_back(i);
        }
  }
  return result;

}

