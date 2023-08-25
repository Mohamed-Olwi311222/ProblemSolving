#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t);
    }
};

int main()
{
    string s = "a";
    string t = "ab";
    cout << Solution::isAnagram(s, t) << endl;
}
