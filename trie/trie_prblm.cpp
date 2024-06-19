/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class trieNode{

    public:

    char data;

    trieNode *children[26];

    bool isTerminal;

    trieNode(char ch){

        data=ch;

        for(int i=0; i<26; i++){

            children[i]=NULL;

        }

        isTerminal=false;

    }

};

 

class Trie {

     trieNode* root;

public:

    Trie() {

       root=new trieNode('\0');

    }

    

    void insertUtil(trieNode* root, string word){

        if(word.length()==0){

            root->isTerminal=true;

            return;

        }

        int index=word[0]-'a';

        trieNode* child;

        if(root->children[index]!=NULL){

            child=root->children[index];

        }

        else{

            child=new trieNode(word[0]);

            root->children[index]=child;

        }

        insertUtil(child, word.substr(1));

    }

    

    void insert(string word) {

        insertUtil(root, word);

    }

 

    bool searchUtil(trieNode* root, string word){

        if(word.length()==0){

            return root->isTerminal;

        }

        int index=word[0]-'a';

        trieNode* child;

        if(root->children[index]!=NULL){

            child=root->children[index];

        }

        else{

            return false;

        }

        return searchUtil(child, word.substr(1));

    }

    

    bool search(string word) {

        return searchUtil(root, word);

    }

 

    bool startsWithUtil(trieNode* root, string prefix){

        if(prefix.length()==0){

            return true;

        }

            int index=prefix[0]-'a';

            trieNode* child;

            if(root->children[index]!=NULL){

                child=root->children[index];

            }

            else{

                return false;

            }

            return startsWithUtil(child, prefix.substr(1));

        }

 

    bool startsWith(string prefix) {

        return startsWithUtil(root, prefix);

    }

};