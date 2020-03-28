#include<iostream>
#include<string.h>

using namespace std;
class Graph
{

private:
    char vertices [10][15]; //This array will store the name of vertices
    int cost[10][10]; //Adjacency matrix containing the cost
    int n; // n is the number of vertices

public:
    Graph()
    {

        n = 0;
        for(int i = 0;i<10;i++)
        {

            for(int j = 0;j<10;j++)
            {
                cost[i][j] = 0; //0 indicates that there is no edge from vertex i to vertex j
            }
        }
    }

    int edgeExist()
    {
        for(int i = 0;i<10;i++)
            for(int j = 0;j<10;j++)
                if(cost[i][j] != 0)
                    return 1;
            return 0;
    }

    int getIndex(char *vname)
    {
        for(int i = 0;i<n;i++)
            if(strcmp(vertices[i],vname) == 0)
                return i;
            return -1; //If vertices not found in the list return -1

    }
    void addVertex()
    {
        char vname[15]; //This array will store the name of the vertex to be added
        cout<<"\n Enter vertex name";
        cin>>vname;
        int i = getIndex(vname);
        if(i != -1)
        {
            cout<<endl<<"vertex already exists"<<endl;
            return;
        }
        strcpy(vertices[n],vname);
        n++;

    }
    void addEdge()
    {
        char v1[15],v2[15];
        int i1,i2;
        if(n==0)
        {
            cout<<"\n No vertex exists.You must first add a vertex \n";
            return;
        }
        while(1)
        {
            cout<<"\n Enter the source vertex";
            cin >> v1;
            i1 = getIndex(v1);
            if(i1 == -1)
                cout<<endl<<"Source vertex does not exist.Try again"<<endl;
            else
                break;
        }
        while(1)
        {

            cout<<"\n Enter the destination vertex";
            cin>>v2;
            i2 =  getIndex(v2);
            if(i2 == -1)
                cout<<endl<<"Destination vertex does not exist.Try again"<<endl;
            else
                break;
        }
        cout<<"\n Enter the cost of the edge:";
        cin>>cost[i1][i2];

    }
    void display()
    {
        if(n==0)
        {
            cout<<"\n Graph does not exist\n";
            return;
        }
        cout<<endl<<"vertices:"<<endl;
        for(int i =0;i<n;i++)
            cout<<vertices[i]<<endl;

        if(edgeExist())
        {
            cout<<endl<<"Edges:"<<endl;
            for(int i =0 ;i<n;i++)
                for(int j=0;j<n;j++)
                    if(cost[i][j] != 0)
                        cout<<vertices[i]<<"->"<<vertices[j]<<" - "<<cost[i][j]<<endl;
        }
    }
};
int main()
{

    Graph g;
    char ch;
    do
    {
        cout<<endl<<"Menu"<<endl;
        cout<<"1. Add a vertex "<<endl;
        cout<<"2. Add an edge"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case '1': g.addVertex();break;
            case '2': g.addEdge();break;
            case '3': g.display();break;
            case '4':break;
            default:cout<<"Invalid choice";
        }

    }while(ch != '4');
return 0;
}
