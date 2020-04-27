#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
int N;
int nodeCnt = 0;
struct Node {
    Node* left;
    Node* right;
    int value;
};

Node *root;
void Insert(int num) {
    Node* newNode = new Node[1];
    newNode -> right = NULL;
    newNode -> left = NULL;
    newNode -> value = num;
    if(!nodeCnt) root = newNode;
    else {
        Node * temp = root;
        while(1) {
            if(temp -> value < num) {
                if(!(temp -> right)) {
                    temp -> right = newNode;
                    break;
                }
                temp = temp -> right;
            }
            else if(temp -> value > num) {
                if(!(temp -> left)) {
                    temp -> left = newNode;
                    break;
                }
                temp = temp -> left;
            }
        }
    }
    nodeCnt++;
}
void PostOrder(Node *temp) {
    if(temp) {
        PostOrder(temp -> left);
        PostOrder(temp -> right);
        cout << temp -> value << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> N) {
        Insert(N);
    }
    PostOrder(root);

};
