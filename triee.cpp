
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct Node {
    bool isWord;
    Node* next[ALPHABET_SIZE+1];

    Node() {
        isWord = false;
        for( int i = 0; i <= ALPHABET_SIZE; i++ ) {
            next[i] = NULL;
        }
    }
}*root;

int getId(char c) {
    return c-'a';
}

void insert( string s ) {
    Node* curr = root;
    for( int i = 0; i < s.size(); i++ ) {
        int id = getId(s[i]);
        if( curr->next[id] == NULL ) {
            curr->next[id] = new Node();
        }
        curr=curr->next[id];
    }
    curr->isWord = true;
}

bool searchWord( string s ) {
    Node* curr = root;
    for( int i = 0; i < s.size(); i++ ) {
        int id = getId(s[i]);
        if( curr->next[id] == NULL ) {
            return false;
        }
        curr=curr->next[id];
    }
    return curr->isWord;
}

bool searchPrefix( string s ) {
    Node* curr = root;
    for( int i = 0; i < s.size(); i++ ) {
        int id = getId(s[i]);
        if( curr->next[id] == NULL ) {
            return false;
        }
        curr=curr->next[id];
    }
    return true;
}

int main()
{
    
        root = new Node();
        int n,i,j;
        cin>>n;

        vector<string> v;
        for(i=0; i<n; i++){
            string s;
            cin>>s;

            v.push_back(s);
            insert(s);
        }

      
}

