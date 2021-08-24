//
//  main.cpp
//  SimpleStack
//
//  Created by Albert Jurkoit on 2021-08-24.
//

#include <iostream>

struct StackNode
{
    int data;
    StackNode* next;
};

StackNode* CreateNewNode(int data)
{
    StackNode* newNode = new StackNode();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool IsEmpty(StackNode* root)
{
    return !root;
}

void Push (StackNode** root, int data)
{
    StackNode* newNode = CreateNewNode(data);
    newNode->next = *root;
    *root = newNode;
}

int Pop(StackNode** root)
{
    if (IsEmpty(*root))
        return INT_MIN;
    StackNode* tempNode = *root;
    *root = (*root)->next;
    int value = tempNode->data;
    delete tempNode;
    return value;
}

int Peek (StackNode* root)
{
    if (IsEmpty(root))
        return INT_MIN;
    return root->data;
}

int main() {
    StackNode* root = NULL;
    
    Push(&root, 5);
    Push(&root, 8);
    Push(&root, 7);
    
    std::cout << "Popped value: " << Pop(&root) << std::endl;
    std::cout << "Peek value: " << Peek(root) << std::endl;
    
    
}
