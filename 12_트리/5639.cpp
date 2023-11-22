#include <iostream>

using namespace std;

struct Node // 노드 구조체
{
    int data;
    Node* left;
    Node* right;
};

void insert(Node*& node, int data){
    if (node == nullptr) { // 첫 노드 삽입
        node = new Node();
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
    } else if (data < node->data) { // 작으면 왼쪽 서브트리
        insert(node->left, data);
    } else { // 크면 오른쪽 서브트리
        insert(node->right, data);
    }
}

void postorder(Node* node){ // 후위 순회
    if(node != nullptr){
        postorder(node->left); // L
        postorder(node->right); // R
        cout << node->data << '\n'; // V
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int data;
    Node* root = nullptr;
    
    // 입력
    while(cin >> data){ // 끝날 때까지
        insert(root, data);
    }

    // 연산 & 출력
    postorder(root);
}