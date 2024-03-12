#include <bits/stdc++.h>
#define int               long long
#define f(i,a,b)          for(int i=a;i<b;i++)
#define mp                make_pair
#define pb                push_back
#define rall(a)           a.rbegin(),a.rend()
#define all(a)            a.begin(),a.end()
#define arraysort(a,n)      sort(a,a+n)
#define endl              "\n"    
#define inputarray(a, n)  f(i, 0, n) { cin >> a[i]; }
#define printarray(a,n)   f(i, 0, n) { cout << a[i] << " "; } cout << endl;
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAfter(Node* prevNode, int data, map<int, Node*>&mp) {
        if (prevNode == nullptr) {
            return;
        }
        
        Node* newNode = new Node(data);
        mp[data]=newNode;
        newNode->next = prevNode->next;
        if (prevNode->next != nullptr) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        newNode->prev = prevNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void deleteNode(Node* nodeToDelete) {
        if (nodeToDelete == nullptr || head == nullptr) {
            return;
        }
        
        if (nodeToDelete == head) {
            head = head->next;
        }
        if (nodeToDelete == tail) {
            tail = tail->prev;
        }

        if (nodeToDelete->prev != nullptr) {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
        
        if (nodeToDelete->next != nullptr) {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        delete nodeToDelete;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

void solve(){
    int n, m;
    cin >> n;
    int a[n];
    inputarray(a,n);
    DoublyLinkedList dll;
    map<int,Node*>mp;
    f(i,0,n){
        dll.insertAtEnd(a[i]);
        mp[a[i]] = dll.tail;
    }
    cin >> m;
    vector<vector<int>>vp;
    f(i,0,m){
        int x,y,z;
        cin >> x;
        if(x==2){
            cin >> y;
            vp.pb({x,y});
        }
        else{
            cin >> y >> z;
            vp.pb({x,y,z});
        }
    }
    
    for(auto query : vp) {
        if(query[0] == 2) {
            dll.deleteNode(mp[query[1]]);
            mp.erase(query[1]);
        } 
        else{
            dll.insertAfter(mp[query[1]], query[2], mp);
        }
    }
    dll.display();
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcases=1;
    // cin >> testcases;
    while (testcases--){
        solve();
    }
}
