//
//  main.cpp
//  卫星搜索树
//
//  Created by Joker Hook on 2019/5/28.
//  Copyright © 2019 Joker Hook. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
/**
  @BiTnode, 声明我们的树
  它包含树的种类名称、树的个数、左子树和右子树
 */
struct Tree {
    char name[202];
    int  count;
    Tree *lchild,*rchild;
};

// n 代表用户输入的树的个数
int n;

/**
  @CreatBitree(BiTnode*,char*)
  创建我们的树，如果新添加的树在已有的种类里面找不到，就重新添加一个子树
 */
Tree * CreatTree(Tree * root,char *s) {
    if(!root) {
        root = new Tree;
        root->lchild=NULL;
        root->rchild=NULL;
        strcpy(root->name,s);
        root->count=1;
    } else {
        int cmp=strcmp(root->name,s);
        if(cmp>0) root->lchild=CreatTree(root->lchild,s);
        else if(cmp<0) root->rchild=CreatTree(root->rchild,s);
        else root->count++;
    }
    return root;
}

/**
  @InOrder(BiTnode*)
  树的中序遍历，采用递归的方法完成
 */
void InOrder(Tree *root) {
    if(root) {
        InOrder(root->lchild);
        printf("The number of %s tree is %d, Its proportion is %.2lf%c\n",root->name,root->count,root->count*100.0/n,'%');
        InOrder(root->rchild);
    }
}

int main() {
    // str数组用来存储用户写的树的名字
    char str[202];
    Tree *root;
    root = NULL;
    printf("Please enter the number of all trees: \n");
    // 用户写下树的总个数
    scanf("%d\n",&n);
    for(int i=0;i<n;i++) {
        /**
         此处使用scanf()来输入树的名字
         如果输入的名字有包含空格，可以使用fgets(str, 202, stdin);
         */
        scanf("%s",str);
        // 循环是为了将树名字统一转换为小写
        for(int j=0;str[j];j++)
            if(str[j]>='A' && str[j]<='Z')
                str[j]+=32;
        root=CreatTree(root,str);
    }
    InOrder(root);
    return 0;
}
