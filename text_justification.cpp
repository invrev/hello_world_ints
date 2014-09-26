#include<iostream>
#include<vector>
#include<string>
using namespace std;

string format_string(int start_index,int end_index,vector<string> &words) {
    string fmt_str = "";
    for (int i=start_index;i<=end_index;i++) {
        fmt_str += words[i];
        fmt_str += " ";
    }
    return fmt_str;
}


vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> to_print_vec;
    int t_len = words.size();
    int total_no_of_spaces = L;
    int start_index =  0;
    int end_index = 0;
    string fmt_str = "";
    for (int i=0;i<t_len;i++) {
        int remaining_spaces = total_no_of_spaces - (words[i].size() + 1);
        end_index = i;
        if (remaining_spaces <= 0) {
            string fmt_str = "";
            if (remaining_spaces == 0) {
                fmt_str  = format_string (start_index,end_index,words);
                start_index = i+1;
                end_index = start_index;
                total_no_of_spaces = L;
            } 
            if (remaining_spaces == -1) {
                //don't add space
                fmt_str  = format_string (start_index,end_index-1,words);
                fmt_str += words[end_index];
                start_index = i+1;
                end_index = start_index;
                total_no_of_spaces = L;
            }
            if (remaining_spaces < -1) {
                end_index = end_index - 1;
                int total_space = L - total_no_of_spaces;
                int total_words = (end_index - start_index) + 1; //index starts from 0
                int no_spaces_after_word = total_space / total_words;
                int tmp_space = no_spaces_after_word ;
                for (int l=start_index;l<=end_index;l++) {
                    fmt_str += words[l];
                    while (tmp_space != 0) {
                        fmt_str += " ";
                        tmp_space -= 1;
                    }
                    tmp_space = no_spaces_after_word ;
                }
                start_index = i;
                end_index = start_index;
                total_no_of_spaces = L - (words[i].size() + 1);
            }
        to_print_vec.push_back(fmt_str);
        } else {
            total_no_of_spaces  = total_no_of_spaces - (words[i].size() + 1);
        }
    }
    if (total_no_of_spaces < L) {
        //string new_fmt_str = "";
        string new_fmt_str  = format_string (start_index,end_index,words);
        total_no_of_spaces = new_fmt_str.length();
        while (total_no_of_spaces != L ) {
            new_fmt_str += " ";
            total_no_of_spaces += 1;
        }
        to_print_vec.push_back(new_fmt_str);
    }
    return to_print_vec;
}

int main () {
    vector<string> words;
    //words.push_back("");
    //vector<string> result = fullJustify (words,3);
    words.push_back("a");
    words.push_back("b");
    words.push_back("c");
    words.push_back("d");
    words.push_back("e");
    vector<string> result = fullJustify (words,3);
    //words.push_back("This");
    //words.push_back("is");
    //words.push_back("an");
    //words.push_back("example");
    //words.push_back("of");
    //words.push_back("text");
    //words.push_back("justification.");
    //vector<string> result = fullJustify (words,16);
    int t_len = result.size();
    cout << "The total len = " << t_len << endl;
    for (int i=0;i<t_len;i++) {
        cout << "result = " << result[i] << endl;
    }
}
