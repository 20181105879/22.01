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
    idx++;//��Ϊ���ַ�������һֱ����ߵģ�����������һ��ȫ�ֱ�����ʾ�ַ�������±��ok��
    build(root->lt);
    idx++;
    build(root->rt);
    return;
}

void exchangeNode(Tree& root)//�Ӹ��ڵ�һ�ν������������͸㶨��
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

void midTravel(Tree root)//�������������
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
