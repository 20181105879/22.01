#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#define MAX 1000000000
#define inf 0x3f3f3f3f
#define FRE() freopen("in.txt","r",stdin)

using namespace std;
typedef long long ll;
const int maxn = 10005;
struct Node
{
    char date;
    Node* rt;
    Node* lt;
};
typedef Node* Tree;
int len,idx;
string str;

void build(Tree& root)
{
    if(str[idx]=='#'||idx==len) return;
    root = new Node;
    root->date = str[idx];
    root->lt = NULL;
    root->rt = NULL;
    idx++;//因为在字符串中是一直向后走的，所以这里用一个全局变量表示字符串你的下标就ok了
    build(root->lt);
    idx++;
    build(root->rt);
    return;
}

void exchangeNode(Tree& root)//从根节点一次交换左右子树就搞定！
{
    if(root->lt==NULL && root->rt==NULL)
        return;
    Node* temp;
    temp = root->lt;
    root->lt = root->rt;
    root->rt = temp;
    if(root->lt!=NULL)
        exchangeNode(root->lt);
    if(root->rt!=NULL)
        exchangeNode(root->rt);
}

void midTravel(Tree root)//中序遍历二叉树
{
    if(root->lt!=NULL)
        midTravel(root->lt);
    printf("%c",root->date);
    if(root->rt!=NULL)
        midTravel(root->rt);
}

int main()
{
   // FRE();
    cin>>str;
    len = str.length();
    idx = 0;
    Tree root = NULL;
    build(root);
    midTravel(root);
    printf("\n");
    exchangeNode(root);
    midTravel(root);
    return 0;
}
