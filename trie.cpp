#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag=false;

    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }

    void put(char c,Node* temp){
        links[c-'a']=temp;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag=true;
    }
};
class Trie{
    private:
        Node * root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        }
        bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->flag;
        }
        bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
int main(){
    Trie trie;
    trie.insert("soumya");
    return 0;
}