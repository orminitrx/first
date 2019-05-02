//
//  main.cpp
//  非递归遍历二叉树
//
//  Created by 赵祥宇 on 2019/4/23.
//  Copyright © 2019 赵祥宇. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct Bitree
{
    char data;
    Bitree *lChild;
    Bitree *rChild;
};
stack<Bitree*> s;
void preOrder(Bitree *root)
{
    while(!s.empty()||root)
    {
        while(root)
        {
            cout<<root->data;
            s.push(root);
            root = root->lChild;
        }
        if(!s.empty())
        {
            root = s.top();
            s.pop();
            root = root->rChild;
        }
    }
}
void inOrder(Bitree *root)
{
  while(!s.empty()||root)
  {
      while(root)
      {
          s.push(root);
          root = root->lChild;
          
      }
      if(!s.empty())
      {
          root = s.top();
          s.pop();
          cout<<root->data;
          root = root->rChild;
      }
  }
}
void postOrder(Bitree *root)
{
    Bitree *pCur,*pLastVisit;
    pCur = root;
    pLastVisit = NULL;
    while(pCur)
    {
        s.push(pCur);
        pCur = pCur->lChild;
    }
    while(!s.empty())
    {
      
                //走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
                pCur = s.top();
                s.pop();
                //一个根节点被访问的前提是：无右子树或右子树已被访问过
                if (pCur->rChild == NULL || pCur->rChild == pLastVisit)
                {
                    cout<< pCur->data;
                    //修改最近被访问的节点
                    pLastVisit = pCur;
                }
                /*这里的else语句可换成带条件的else if:
                 else if (pCur->lchild == pLastVisit)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
                 因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
                 */
                else
                {
                    //根节点再次入栈
                    s.push(pCur);
                    //进入右子树，且可肯定右子树一定不为空
                    pCur = pCur->rChild;
                    while (pCur)
                    {
                        s.push(pCur);
                        pCur = pCur->lChild;
                    }
        
                }
        
    }
}
void myCreat(Bitree **root)
{
    char ch;
    cin>>ch;
    if(ch =='#')
        *root = NULL;
    else
    {
        *root = new Bitree;
        (*root)->data = ch;
        myCreat(&(*root)->lChild);
        myCreat(&(*root)->rChild);
        
    }
        
}

int main()
{
    stack<string> s;
    
    Bitree *root;
    
    
    myCreat(&root);
    
    cout<<"前序遍历"<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"中序遍历"<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"后序遍历"<<endl;
    postOrder(root);
    cout<<endl;
    
    
    
    
    return 0;
}
