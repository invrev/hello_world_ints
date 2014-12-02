#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> generateParenthesis(int n) {
        vector<string> results;
        vector<char> output;
        GetParentheses(n, n, output, results);
        return results;
}
 
void GetParentheses(int l, int r, vector<char>& output, vector<string>& results) {
    if (l == 0 && r == 0) {
        results.push_back(string(output.begin(), output.end()));
    }
    if (l > 0) {
            output.push_back('(');
            GetParentheses(l - 1, r, output, results); //Add "(" so l-1
            output.pop_back(); //Backtrack
    }
    // When adding right bracket, check validity.
    if (r > 0 && r > l) {
            output.push_back(')');
            GetParentheses(l, r - 1, output, results); //Add ")" so r-1
            output.pop_back(); //Backtrack
    }
}

//PART II

vector<string> generateParenthesis(int n) {
    vector<string> res;
    generate(n,n,res,"");
    return res;
}

void generate(int l, int r, vector<string>& res, string s)
{
    if (l > r) return;
    if (l == 0)
    {
        for (int i = 0; i < r; i++) s+= ")";
        res.push_back(s);
        return;
    }
    generate(l - 1, r, res, s + "(");
    generate(l, r - 1, res, s + ")");
}



//My method is DP. First consider how to get the result f(n) from previous result f(0)...f(n-1). Actually, the result f(n) will be put an extra () pair to f(n-1). Let the "(" always at the first position, to produce a valid result, we can only put ")" in a way that there will be i pairs () inside the extra () and n - 1 - i pairs () outside the extra pair.
//Let us consider an example to get clear view:
//f(0): ""
//f(1): "("f(0)")"
//f(2): "("f(0)")"f(1), "("f(1)")"
//f(3): "("f(0)")"f(2), "("f(1)")"f(1), "("f(2)")"
//So f(n) = "("f(0)")"f(n-1) , "("f(1)")"f(n-2) "("f(2)")"f(n-3) ... "("f(i)")"f(n-1-i) ... "(f(n-1)")"
//Below is my code:
//public class Solution
//{
//    public List<String> generateParenthesis(int n)
//    {
//        List<List<String>> lists = new ArrayList<>();
//        lists.add(Collections.singletonList(""));
//        for (int i = 1; i <= n; ++i)
//        {
//            final List<String> list = new ArrayList<>();
//            for (int j = 0; j < i; ++j)
//            {
//                for (final String first : lists.get(j))
//                {
//                    for (final String second : lists.get(i - 1 - j))
//                    {
//                        list.add("(" + first + ")" + second);
//                    }
//                }
//            }
//            lists.add(list);
//        }
//        return lists.get(lists.size() - 1);
//    }
//}

int main () {

}
