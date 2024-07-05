#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string w[n];
    unordered_set<string> word[26]; // 按首字母分组存储单词
    for(int i=0; i<n; i++)
    {
        cin>>w[i];
        word[w[i][0]-'a'].insert(w[i]); // 按首字母分组存储单词
    }
    int ans=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            string wordA=w[i];
            string wordB=w[j];
            if (wordA[0]==wordB[0]) continue;
            swap(wordA[0],wordB[0]);
            if (word[wordA[0]-'a'].find(wordA)==word[wordA[0]-'a'].end()&&word[wordB[0]-'a'].find(wordB) == word[wordB[0]-'a'].end())
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
