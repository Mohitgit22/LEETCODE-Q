class Solution {
public:
    struct trieNode {
        int idx;
        trieNode* children[26];
    };

    trieNode* getNode(int i) {
        trieNode *newnode = new trieNode();
        newnode->idx = i;

        for(int i = 0 ; i < 26; i++) {
            newnode->children[i] = NULL;
        }
        return newnode;
    }

    void insertTrie(trieNode* crawler, int i,vector<string>& wordsContainer ) {
        string word = wordsContainer[i];
        int n = word.size();

        for(int j = n-1; j >= 0; j--) {
              int ch_idx = word[j] - 'a';

              if(crawler -> children[ch_idx] == NULL){
                crawler->children[ch_idx] = getNode(i);
              }
             crawler = crawler->children[ch_idx];
 

           if(wordsContainer[crawler->idx].size() > n){
            crawler->idx = i;
           }
        }
    }


    int search(trieNode* crawler, string& word){
        int n = word.size();
        int result_idx = crawler -> idx;

        for(int i = n-1; i>= 0; i--) {
            int ch_idx = word[i] - 'a';

            if(crawler->children[ch_idx] == nullptr){
                return result_idx;
            }
            crawler = crawler->children[ch_idx];
            result_idx = crawler->idx;
        }
        return result_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> result(n);
        trieNode* root = getNode(0);

        for(int i = 0 ; i < m; i++) {
            //storing the size of smallest string , if for any string of wordsquery, any letter is  not found
            if(wordsContainer[i].size() < wordsContainer[root->idx].size()){
                root->idx = i;
            }
            insertTrie(root, i, wordsContainer);
        }

        for(int i = 0; i < n; i++) {
            result[i] = search(root, wordsQuery[i]);
        }

        return result;
    }
};