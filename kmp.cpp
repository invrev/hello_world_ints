#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

//1.Naive solution
//2.KMP search
//3.Rabin-Karp solution
//Other solution build suffix tree 
//Naive solution O(mn)
bool is_pattern_in_text (string p,string t) {
    int m = p.length();
    int n = t.length();
    bool is_match = true;
    for (int i=0;i<(n-m);i++) {
        is_match = true;
        for (int j=0,k=i;j<m;j++,k++) {
            if (p[j] != t[k]) {
                is_match = false;
                break;
            }
        }
        if (is_match) {
            break;
        }
    }
    if (is_match) {
        cout << "pattern = " << p << " is in text = " << t << endl;
    } else {
        cout << "not found" << endl;
    }
    return (is_match);
}


bool is_pattern_in_text_v2(string pattern,string text) {
    int m = pattern.length();
    int n = text.length();
    int j = 0;
    //NOTE : After every mismatch string shift incremented by 1
    for (int i=0;i<(n-m);i++) {
        for (;j<m;j++) {
            if (pattern[j] != text[i+j]) {
                j = 0;  //After mismatch we reset the j to original position KMP gains here
                break;
            }
        }
        if (j == m) {  //All characters from the strings are matched.
            cout << "pattern = "<< pattern << " is part of text = " << text << endl;
            return true;
        }
    }
    cout << "pattern = "<< pattern << " is not part of text = " << text << endl;
    return false;
}

vector<int> compute_prefix_for_kmp (string pattern) {
    int m = pattern.length();
    vector<int> prefix(m);
    //init prefix 
    prefix[0] = 0;
    int k = 0; //# of matched characters
    int q = 0;  //Take out first q charcs
    for (q=1;q<m;q++) {
       while (k > 0 && pattern[q] != pattern[k]) {
           k = prefix[k]; //Get previous # of matched chars prefix*[k]
       }
       if (pattern[q] == pattern[k]) {
           k += 1;
       }
       prefix[q] = k;
    }
    cout << "returning the prefix " << endl;
    for (int i=0;i < prefix.size(); i++) {
        cout << prefix[i] << " " ;
    }
    cout << endl;
    return (prefix);
}

bool use_kmp_search (string pattern,string text) {
    int m = pattern.length();
    int n = text.length();
    int j = 0;
    //compute prefix function 
    vector<int> prefix_val = compute_prefix_for_kmp (pattern);
    int q = 0; 
    for (int i = 0 ;i < n ;i ++) {
       while (q > 0 && pattern[q] != text[i]) {
           q = prefix_val[q]; //If no match then next position of char in the pattern
       } 
       if (pattern[q] == text[i]) {
            q = q + 1;
       } 
       if (q == m) {
        cout << "text = " << text << "is part of pattern = " << pattern << endl;
        return true;
       }
    }

    cout << "text = " << text << "is not part of pattern = " << pattern << endl;
    return false;
}

int get_ascii (char a) {
    if (a - 'a' > 0 )  {
        return (a - 'a' + 1);
    } else {
        return (a - 'A' + 1);
    }
}

bool use_RB_karp (string pattern,string text) {
    int d = 32;
    int q = 13;
    int m = pattern.length(); 
    int n = text.length();
    //The prop of mod operation
    //all_arithmetic_operation % q = individual operation % q
    //dm_minus_one is used to subtract the LSB
    int dm_minus_one = 1;
    int hp = 0 ,ht = 0;
    for (int i = 0;i < m;i++)  {
        dm_minus_one = (d * dm_minus_one) % q; 
    }
    //compute hp and ht (for first m charcs)
    for (int i=0;i<m;i++) {
        hp = (d * hp + get_ascii (pattern[i]) ) % q;
        ht = (d * ht + get_ascii (text[i]) ) % q;
    }

    cout << "at T0 dm_minus_one = " << dm_minus_one << "hp = " << hp << "ht = " << ht << endl;
    int j = 0;
    for (int i = 0;i<n;i++) {
        
        if (hp == ht) {
            for (;j<m;j++) {
                if (pattern[j] != text[i+j]) {
                    //compute the next hash
                    cout << "NOT MATCH" << i << " = " << text[i+j] << j  << " = " << pattern[j] << endl;
                    j = 0;
                    break;
                }
            }
        }
        if (j == m) {
            cout << "match found" << endl;
            return true;
        } else {
            ht = (ht + d*q - get_ascii(text[i]) * dm_minus_one) % q;
            ht = (ht*d + get_ascii(text[i+m])) % q;
            cout << "1 : " << ht << " = " << text[i] << endl;
            //ht = ( (ht - (dm_minus_one * get_ascii(text[i]))) * d);
            //ht = ( (ht % q) + (get_ascii(text[i+m]) % q));
        }
    }
    //cout << "hp = " << hp << "ht = " << ht << endl;
    
    return true;
}

int main () {
    //is_pattern_in_text ("abcde","abcdabcdef");
    //is_pattern_in_text ("abcde","abcdabcdff");
    //is_pattern_in_text_v2 ("abcde","abcdabcdef");
    //is_pattern_in_text_v2 ("abcde","abcdabcdff");
    use_kmp_search ("abababca","abababcaabcdabcdef");
    use_kmp_search ("abcde","abcdabcdff");
    //use_RB_karp ("abcde","abcdabcdff") ;
    //use_RB_karp ("abababca","abababcaabcdabcdef");
    //use_RB_karp ("abcde","abcdabcdef");
    //kmp_search ("1010011","10100111011101");

}
