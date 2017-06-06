#include <string>
#include <vector>
#include <algorithm>


using namespace std;

void process_tsv(string& s,
                   const string& p) {
   int n = p.length();

   for (int i = s.find(p);
        i != string::npos;
        i = s.find(p))
        s.replace(i, n, " ");



//erase the punctuation characters, convert all to capital to count
    for (int i = 0; i < s.length(); i++)
    {
        if ((isalnum(s[i]))||
            s[i] == '\n' ||
            s[i] == '\t' ||
            s[i] == ' ') s[i] = toupper(s[i]);
        else s[i] = ' ';
    }
}


