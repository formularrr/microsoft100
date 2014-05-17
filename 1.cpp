//
//  1.cpp
//  microsoft100
//
//  Created by formula on 14-5-17.
//  Copyright (c) 2014年 formula. All rights reserved.
//

#include "1.h"
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createTree(vector<int> nodes);
void createTree(TreeNode &*root, int val);

int main(){
    vector<int> v{10, 6, 14, 4, 8, 12, 16};
    createTree(v);
    
    cout << 1;
    
    return 0;
}

TreeNode *createTree(vector<int> nodes){
    if(nodes.empty())
        return nullptr;
    
    TreeNode *root = new TreeNode(nodes[0]);
    
    int len = nodes.size();
    
    for(int i = 1; i < len; ++ i){
        createTree(root, nodes[i]);
    }
    
    return root;
}

void createTree(TreeNode &*root, int val){
    if(!root){
        root = new TreeNode(val);
        return;
    }
    
    TreeNode *p = root , pre = root;
    
    while(p){
        pre = p;
        if(p->val < val)
            p = p->right;
        
        else if(p->val > val)
            p = p->left;
    }
    
    if(pre->val > val)
        pre->left = new TreeNode(val);
    else pre->right = new TreeNode(val);
    
    return;
}
