//used for spell checker , stores characters as nodes 
  
       null
  next[0] ...     next[1 ] ....  next[25]
 next[0]to next[25]

etc
first initialise next to null take a pointer to structer// we take pointer to structure so we get address of structure thus making it easy to do operation
while inserting create new node,find length of string to be inserted , once done set a marker, using endmark variable,this will be used to search efficiently , while deleting , we have to delete everything , first del next entries for ucrrrent , then del curr
//used in prefix matches,longest prefix
#include <bits//stdc++.h>

using namespace std;

struct node
{
    bool endmark;
    node *next[26+1];
    node()
    {
        endmark = false;
        for(int i=0; i<26; i++) next[i] = NULL;
    }
}*root;

void insert(char *str, int len)
{
    node *curr = root;
    for(int i=0; i<len; i++)
    {
        int id = str[i] - 'a';
        if(curr->next[id]==NULL)
            curr->next[id] = new node;
        curr=curr->next[id];
    }
    curr->endmark = true;
}

bool search(char *str, int len)
{
    node *curr = root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL) return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node *cur)
{
    for(int i=0; i<26; i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete(cur);
}

int main()
{
    puts("Enter number of Words");
    root = new node();
    int num_word;
    cin>>num_word;
    for(int i=1; i<=num_word; i++)
    {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }
    puts("Enter Number of Query");
    int query;
    cin>>query;
    for(int i=0; i<=query; i++)
    {
        char str[50];
        scanf("%s", str);
        if(search(str, strlen(str))) puts("Found");
        else puts("NOT FOUND");
    }
    del(root);
    return 0;
}