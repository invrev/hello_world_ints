#include<iostream>
#include<vector>
#include<string>
using namespace std;
//TODO
int justify(vector<string>& words, int s, int L, vector<string> &res){
        int e = s;
        int tot=0;
        // find words in current line
        while(e<words.size()){
            tot += words[e].size();
            if(tot+e-s>L){
                tot -= words[e].size();
                break;
            }else
                e++;
        }
        
        string sb ;
        int spaceTotLen = L-tot;

        // append words and spaces
        while(s<e){
            sb+= words[s];
            int spaceLen = 1;
            if(e<words.length) 
                spaceLen=e-s-1>0?(spaceTotLen+e-s-2)/(e-s-1):0;//non-last line
            spaceTotLen -= spaceLen;
            while(spaceLen>0){
                sb +=" "
                spaceLen --;                
            }
            s++;
        }

        // make length=L
        for(int i=sb.length(); i<L; i++)
        sb.append(" ");
        sb.setLength(L);

        res.add(sb.toString());
        return e;
}

vector<string> fullJustify(vector<string> &words, int L) {
    
        vector <string> result;
        int s=0;
        while(s<words.size()){
            s = justify(words, s, L, res);
        }
        return result;

}


int main () {

    string input_arr[] = {"This", "is", "an", "example", "of", "text", "justification."};
    cout << sizeof(input_arr) << "," << sizeof(input_arr[0]) << endl;
    vector<string> input(input_arr,input_arr+sizeof(input_arr)/sizeof(input_arr[0]));
    fullJustify(input,16);
    
}
