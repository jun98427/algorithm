#include <iostream>

using namespace std;

const int MAX_N = 100'000;

int inorder[MAX_N];
int postorder[MAX_N];
int idx[MAX_N+1];

void preorder(int ins, int ine, int pos, int poe) {  
    if(ins > ine) return ;

    int target = postorder[poe];
    cout << target << " ";

    int stand = idx[target];
    int l = stand - ins;

    preorder(ins, stand-1, pos, pos+l-1);
    preorder(stand+1, ine, pos+l, poe-1);
}   


int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    preorder(0, n-1, 0, n-1);
    cout << "\n";

    return 0;
}