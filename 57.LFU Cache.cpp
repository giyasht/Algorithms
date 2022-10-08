#include<bits/stdc++.h>
using namespace std;

class LFUCache {
    public:
        class node {
            public:
                int key;
                int val;
                node *next;
                node *prev;
            
                node(int _key, int _val) {
                    key = _key;
                    val = _val;
                }
        };
    
        int cap;
        node *head = new node(-1,-1);
        node *tail = new node(-1,-1);
        unordered_map<int,node*> m;
        unordered_map<int,int> freq;
    
    public:
        LFUCache(int capacity) {
            cap = capacity;
            head -> next = tail;
            tail -> prev = head;
        }
    
        void addnode(node *newnode){
            node *tempnode = head->next;
            head->next = newnode;
            newnode->next = tempnode;
            tempnode->prev = newnode;
            newnode->prev = head;
        }

        void deletenode(node *delnode){
            node *delprev = delnode->prev;
            node *delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
        }

        int get(int key) {
            if(cap == 0) return -1;
            if(m.find(key) != m.end()) {
                int result = 0;
                node *tempnode = m[key];
                result = tempnode->val;
                m.erase(key);
                deletenode(tempnode);
                addnode(tempnode);
                m[key] = head->next;
                freq[key]++;
                return result;
            }
            return -1;
        }

        void put(int key, int value) {
            if(m.find(key) != m.end()){
                node *newnode = m[key];
                deletenode(newnode);
                m.erase(key);
                freq[key]++;
            }
            if(m.size() == cap && cap != 0){
                int minimum = 1000;
                node *delnode;
                
                for(auto x:freq){
                    minimum = min(minimum,x.second);
                }
                
                int count = 0;
                
                for(auto x:freq){
                    if(x.second == minimum) count++;
                }
                
                if(count == 1){
                
                    int keyvalue = 0;
                    
                    for(auto x:freq){
                        if(x.second == minimum){
                            delnode = m[x.first];
                            keyvalue = x.first;
                            break;
                        }
                    }
                    
                    m.erase(keyvalue);
                    freq.erase(keyvalue);
                    deletenode(delnode);
                }
                else{
                    m.erase(tail->prev->key);
                    deletenode(tail->prev);
                    freq.erase(tail->prev->key);
                }
            }
            addnode(new node(key,value));
            m[key] = head->next;
            freq[key]++;
        }
};
