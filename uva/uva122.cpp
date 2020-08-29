#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>


using namespace std;
const int maxn=10000;

struct Node{
    bool have_value;
    int v;
    Node * left, *right;
    Node():have_value(false),left(NULL),right(NULL) {}
};

char s[maxn];
Node*  root;
bool failed = false;

Node* newNode(){return new Node();}

void add_node(int v, char * s)
{
    Node * u =root;
    int n= strlen(s);

    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            if(u->left==NULL)
                u->left = newNode();
            u=u->left;
        }else if(s[i] == 'R'){
            if(u->right == NULL)
                u->right = newNode();
            u=u->right;
        }
    }
    if(u->have_value)
        failed = true;
    else u->v = v;
    u->have_value = true;
}


bool read_input()
{
    int v;
    failed = false;
    root= newNode();
    for(;;)
    {
        if(scanf("%s",s)!=1)
            return false;
        if(strcmp(s,"()")==0)
            break;
        sscanf(&s[1],"%d",&v);
        add_node(v,strchr(s,',')+1);
            //find the address after ','
    }
    return true;
}

void remove_tree(Node * temp)
{
    if(temp == NULL)
        return ;
    Node *  u = temp;

    remove_tree(u->left);
    remove_tree(u->right);
    
    delete(u);
}

bool bfs(vector<int> & ans)
{
    queue<Node*> q;
    q.push(root);
    ans.clear();

    while(!q.empty())
    {
        Node * u = q.front();
        q.pop();
        if(u->have_value == false)
            return false;
        ans.push_back(u -> v);
        if(u -> left != NULL)
            q.push(u -> left);
        if(u -> right != NULL)
            q.push(u -> right);
    }
    remove_tree(root);
    return true;
}
int main()
{
    vector<int> ans;
    while(read_input())
    {

        if(failed || !bfs(ans))
        {
            printf("not complete\n");
            continue;
        }        
        int temp_1 = 1;
        for(auto temp:ans)
        {
           if(temp_1!=1)
               putchar(' ');
           temp_1++;
            printf("%d",temp);
        }
        putchar('\n');
    }
    return 0;
}
