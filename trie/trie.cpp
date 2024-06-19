#include <bits/stdc++.h>
using namespace std;

class trieNode {
public:
    char data;
    unordered_map<char, trieNode*> children;
    bool isTerminal;

    trieNode(char ch) {
        data = ch;
        isTerminal = false;
    }
};

class trie {
public:
    trieNode* root;

    trie() {
        root = new trieNode('\0');
    }

    void insertUtil(trieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        if (root->children.find(ch) != root->children.end()) {
            insertUtil(root->children[ch], word.substr(1));
        }
        else {
            trieNode* newNode = new trieNode(ch);
            root->children[ch] = newNode;
            insertUtil(newNode, word.substr(1));
        }
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(trieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        char ch = word[0];
        if (root->children.find(ch) != root->children.end()) {
            return searchUtil(root->children[ch], word.substr(1));
        }
        else {
            return false;
        }
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool removeUtil(trieNode* root, string word) {
        if (word.length() == 0) {
            if (root->isTerminal) {
                root->isTerminal = false;
                return root->children.empty();
            }
            return false;
        }

        char ch = word[0];
        if (root->children.find(ch) != root->children.end()) {
            bool shouldRemoveChild = removeUtil(root->children[ch], word.substr(1));
            if (shouldRemoveChild) {
                delete root->children[ch];
                root->children.erase(ch);
                return root->isTerminal && root->children.empty();
            }
            return false;
        }
        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};

int main() {
    trie t;
    t.insertWord("ABCD");
    t.insertWord("DO");
    t.insertWord("TIME");
    t.insertWord("WINE");

    cout << "Present or not: " << t.search("ABCD") << endl;
    cout << "Present or not: " << t.search("WINE") << endl;

    t.removeWord("ABCD");
    cout << "Present or not: " << t.search("ABCD") << endl;

    return 0;
}
