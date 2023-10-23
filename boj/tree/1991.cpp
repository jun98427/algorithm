#include <iostream>

using namespace std;

struct Node {
    char a;
    Node* left;
    Node* right;
};

Node arr[26];
int n;

void preorder(Node*cur) {
    if(cur == nullptr) return;
    cout << cur->a;
    preorder(cur->left);
    preorder(cur->right);
}

void postorder(Node*cur) {
    if(cur == nullptr) return;
    postorder(cur->left);
    postorder(cur->right);
    cout << cur->a;
}

void midorder(Node*cur) {
    if(cur == nullptr) return ;
    midorder(cur->left);
    cout << cur->a;
    midorder(cur->right);
}

int main() {
    cin >> n;

    char c, l, r;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> l >> r;

        Node* cur = &arr[c-'A'];
        cur->a = c;
        cur->left = cur->right = nullptr;
        if(l != '.') cur->left = &arr[l-'A'];
        if(r != '.') cur->right = &arr[r-'A'];
    }
    
    
    preorder(&arr[0]);
    cout << "\n";
    midorder(&arr[0]);
    cout << "\n";
    postorder(&arr[0]);
    cout << "\n";

    return 0;
}