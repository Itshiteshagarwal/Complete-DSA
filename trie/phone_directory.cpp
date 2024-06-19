// #include <iostream>
// #include <vector>
// using namespace std;

// class TrieNode {
// public:
// //class for trie node
//     char data;
//     TrieNode* children[26];
//     bool isTerminal;

//     //constructor of this class
//     TrieNode(char ch) {
//         data = ch;
//         for (int i = 0; i < 26; i++) {
//             children[i] = nullptr;
//         }
//         isTerminal = false;
//     }
// };

// class Trie {
// private:
//     TrieNode* root;

// public:
//     Trie() {
//         root = new TrieNode('\0');
//     }
//     //function for nsertion into trie
//     void insertUtil(TrieNode* root, string word) {
//         //if word reach toh its last position then make it terminal node
//         if (word.length() == 0) {
//             root->isTerminal = true;
//             return;
//         }

//         int index = word[0] - 'a';
//         TrieNode* child;

//         if (root->children[index] != nullptr) {
//             child = root->children[index];
//         } else {
//             child = new TrieNode(word[0]);
//             root->children[index] = child;
//         }
//         //recursive  call
//         insertUtil(child, word.substr(1));
//     }

//     void insert(string word) {
//         insertUtil(root, word);
//     }

//     void printSuggestionsUtil(TrieNode* curr, vector<string>& temp, string prefix) {
//         //if current character is terminal ch
//         if (curr->isTerminal) {
//             //store the data in prefix
//             temp.push_back(prefix);
//         }

//         //traverse for all elements
//         for (char ch = 'a'; ch <= 'z'; ch++) {
//             TrieNode* next = curr->children[ch - 'a'];
//             if (next != NULL) {
//                 string newPrefix = prefix + ch;
//                 printSuggestionsUtil(next, temp, newPrefix);
//             }
//         }
//     }

//     vector<vector<string>> getSuggestions(string str) {
//         TrieNode* prev = root;
//         vector<vector<string>> output;
//         string prefix = "";

//         for (int i = 0; i < str.length(); i++) {
//             char lastCh = str[i];
//             prefix.push_back(lastCh);
//             //check for last character
//             TrieNode* curr = prev->children[lastCh - 'a'];
//             //if last charcter not found
//             if (curr == NULL) {
//                 break;
//             }
//             //if found
//             vector<string> temp;
//             printSuggestionsUtil(curr, temp, prefix);
//             output.push_back(temp);
//             prev = curr;
//         }

//         return output;
//     }
// };

// vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
//     Trie* t = new Trie();

//     // Insert all contacts into the trie
//     for (int i = 0; i < contactList.size(); i++) {
//         string str = contactList[i];
//         t->insert(str);
//     }

//     // Return the suggestions
//     return t->getSuggestions(queryStr);
// }

//sc O(m*n);
//tc ((n*m^2));

