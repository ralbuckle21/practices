/*Code 组合数学
Transmitting and memorizing information is a task that requires different coding systems for the best use of the available space. A well known system is that one where a number is associated to a character sequence. It is considered that the words are made only of small characters of the English alphabet a,b,c, ..., z (26 characters). From all these words we consider only those whose letters are in lexigraphical order (each character is smaller than the next character). 

The coding system works like this: 
•	The words are arranged in the increasing order of their length. 
•	The words with the same length are arranged in lexicographical order (the order from the dictionary). 
•	We codify these words by their numbering, starting with a, as follows: 
a - 1 
b - 2 
... 
z - 26 
ab - 27 
... 
az - 51 
bc - 52 
... 
vwxyz - 83681 
... 

Specify for a given word if it can be codified according to this coding system. For the affirmative case specify its code. 
Input

The only line contains a word. There are some constraints: 
•	The word is maximum 10 letters length 
•	The English alphabet has 26 characters. 
Output

The output will contain the code of the given word, or 0 if the word can not be codified.
Sample Input

bf
Sample Output

55
*/
//一层一层的算就可以了，就是先算出s[i]开头，但是比s[i+1]小的有多少，然后一点一点累加
#include <iostream>
using namespace std;

int c[27][27];
void pre() {
    c[0][0] = 1;
    for (int i = 1; i < 27; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
}

char s[15];

bool ok() {
    int len = strlen(s);
    for (int i = 1; i < len; ++i) {
        if (s[i] <= s[i-1])
            return false;
    }
    return true;
}

int main() {
    pre();
    while (scanf("%s", s) != EOF) {
        if (!ok()) {
            printf("0\n");
        }
        else {
            int len = strlen(s);
            int ans = 0;
            for (int i = 1; i < len; ++i) {
                ans += c[26][i];
            }
            for (char ch = 'a'; ch < s[0]; ++ch) {
                ans += c['z'-ch][len-1];
            }
            for (int i = 1; i < len; ++i) {
                for (char ch = s[i-1]+1; ch < s[i]; ++ch) {
                    ans += c['z'-ch][len-i-1];
                }
            }
            printf("%d\n", ans+1);
        }
    }
    return 0;
}