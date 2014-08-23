#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;
enum State {
    UNVISITED = 0,
    VISITING,
    VISITED,
};

typedef struct Node {
    int val;
    State status;    
    list<struct Node*> adj;
}node; 

class graph {
    public:
        graph(){};
        ~graph(){};
        
        void addNode(int n);   
        int addEdgeDir(node* n1, node* n2);
        void addEdgeUndir(int idx1, int idx2);
        node* getNode(int idx);
        void displayDFS(void);
        void printLevelWise(void);
        
    private:
        vector<node*> gp;
};

void graph::displayDFS(void) {
   
     
    for(vector<node*>::iterator itr_n = gp.begin(); itr_n != gp.end(); itr_n++)
        (*itr_n)->status = UNVISITED;

    stack<node*> st;
    st.push(gp[0]);
    while(!st.empty())
    {
        node *curN = st.top();
        st.pop();
        cout << "\t" << curN->val;
        for(list<node*>::iterator it = curN->adj.begin(); it != curN->adj.end(); it++)
        {
            if((*it)->status == UNVISITED) {
                (*it)->status = VISITING;
                st.push((*it));
            }
        }
        curN->status = VISITED;
    }
}

void graph::addNode(int n)
{   
    node *n_node = new node;
    n_node->val = n;
    gp.push_back(n_node);
}

node* graph::getNode(int idx)
{
    if(idx <= gp.size())
        return(gp[idx - 1]);
    return NULL;
}

void graph::addEdgeUndir(int idx1, int idx2)
{
    if(idx1 > gp.size() || idx2 > gp.size())
        return;

    gp[idx1-1]->adj.push_back(gp[idx2-1]); 
    gp[idx2-1]->adj.push_back(gp[idx1-1]); 
}

int graph::addEdgeDir(node* n1, node *n2)
{   
     if(n1 == NULL || n2 == NULL)
        return -1;
     for(vector<node*>::iterator itr_n = gp.begin(); itr_n != gp.end(); itr_n++)
     {   
        if(*itr_n == n1)
        {   
            (*itr_n)->adj.push_back(n2);
            return 1;
        }
    }
    return -1;
}
    
        
int main(int argc, char **argv) {
    graph g;
    for(int i=1; i<=5; i++)
        g.addNode(i);
    
    g.addEdgeUndir(1, 2);
    g.addEdgeUndir(1, 3);
    g.addEdgeUndir(1, 4);
    g.addEdgeUndir(3, 4);
    g.addEdgeUndir(3, 5);
    g.addEdgeUndir(4, 5);
    
    g.displayDFS();
}
    
       

    
