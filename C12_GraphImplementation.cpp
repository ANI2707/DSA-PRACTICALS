/*
Problem statement(Graph) :=
Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
list to perform BFS. Use the map of the area around the college as the graph. Identify
the prominent land marks as nodes and perform DFS and BFS on that.

*/
#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
class queue1
{
public:
    int r, f;
    int arr[20];
    queue1()
    {
        r = f = -1;
    }
    int empty()
    {
        if (r == -1 && f == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void insert(int p)
    {
        if (empty() == 1)
        {
            r = f = 0;
            arr[r] = p;
        }
        else
        {
            r = r + 1;
            arr[r] = p;
        }
    }
    int remove()
    {
        int temp = arr[f];
        if (r == f)
        {
            r = f = -1;
        }
        else
        {
            f++;
        }
        return temp;
    }
};

class graph
{
public:
    node *adjList[10];
    int adj[10][10];
    int vis[10];
    int edges;
    graph()
    {
        for (int i = 0; i < 10; i++)
        {
            vis[i] = 0;
            adjList[i] = NULL;
            for (int j = 0; j < 10; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void adjMatrix()
    {

        cout << "Enter Number of edges :" << endl;
        cin >> edges;

        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cout << "Enter edge between two vertices u and v :" << endl;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        cout << "printing adj Matrix for our understanding" << endl;
        for (int i = 0; i < edges; i++)
        {
            for (int j = 0; j < edges; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void insertList()
    {
        int u;
        int v;
        cout << "Enter edge between two vertices u and v :" << endl;
        cin >> u >> v;
        node *p = new node(v);
        if (adjList[u] == NULL)
        {
            adjList[u] = p;
        }
        else
        {
            node *temp = adjList[u];

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
        }
    }

    void dfs(int node)
    {
        cout << node << " ";
        vis[node] = 1;

        for (int i = 0; i < edges; i++)
        {
            if (adj[node][i] == 1 && vis[i] == 0)
            {
                dfs(i);
            }
        }
    }
    void dfs1(int i)
    {
        cout << i << " ";
        vis[i] = 1;

        node *t = adjList[i];
        while (t != NULL)
        {
            if (vis[t->data] == 0)
            {
                dfs1(t->data);
            }
            t = t->next;
        }
    }
    void bfs(int i)
    {
        queue1 q;

        vis[i] = 1;
        q.insert(i);

        while (!q.empty())
        {
            int node = q.remove();
            cout << node << " ";
            for (int i = 0; i < edges; i++)
            {
                if (adj[node][i] == 1 && vis[i] == 0)
                {
                    vis[i] = 1;
                    q.insert(i);
                }
            }
        }
    }
    void bfs1(int i)
    {
        vis[i] = 1;
        queue1 q;
        q.insert(i);
        cout << i << " ";
        while (!q.empty())
        {
            int j = q.remove();
            node *temp = adjList[j];
            while (temp != NULL)
            {
                if (vis[temp->data] == 0)
                {
                    vis[temp->data] = 1;
                    cout << temp->data << " ";
                    q.insert(temp->data);
                }
                temp = temp->next;
            }
        }
    }
};
int main()
{
    graph g1;
    graph g2;
    graph g3;
    graph g4;
    int ch;
    int v;
    cout << "1.DFS using matrix\n2.DFS using list\n3.BFS Using matrix\n4.BFS Using List\n5.Exit";
    while (1)
    {
        cout << "\nEnter a choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            g1.adjMatrix();
            cout << "Enter vertex to call dfs :" << endl;
            cin >> v;
            g1.dfs(v);
            break;
        case 2:
            cout << "Enter number of edges :" << endl;
            cin >> g2.edges;

            for (int i = 0; i < (2 * g2.edges); i++)
            {
                g2.insertList();
            }
            cout << "Enter vertex to call dfs :" << endl;
            cin >> v;

            g2.dfs1(v);
            cout << endl;
            cout << "printing adj List for our understanding" << endl;
            for (int i = 0; i < 10; i++)
            {
                node *t = g2.adjList[i];

                while (t != NULL)
                {
                    cout << t->data << " ";
                    t = t->next;
                }
                cout << endl;
            }
            break;
        case 3:
            g3.adjMatrix();
            int v;
            cout << "Enter vertex to perform bfs :" << endl;
            cin >> v;

            g3.bfs(v);
            break;
        case 4:
            cout << "Enter number of edges :" << endl;
            cin >> g4.edges;

            for (int i = 0; i < (2 * g4.edges); i++)
            {
                g4.insertList();
            }
            cout << "Enter vertex to call dfs :" << endl;
            cin >> v;

            g4.bfs1(v);
        case 5:
            exit(1);
        }
    }

    return 0;
}
