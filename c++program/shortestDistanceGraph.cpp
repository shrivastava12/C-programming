#include<iostream>
#include<string.h>
#define infinity 9999

class Graph
{

private:
    char vertices[10][15];
    int n;
    int cost[10][10];

public:
    Graph()
    {
        n = 0;
        for(int i = 0;i<10;i++)
            for(int j = 0;j<10;j++)
                {
                    if(i == j)
                        cost[i][j] = 0;
                    else
                        cost[i][j] = infinity;
                }
    }

    int edgeExist()
    {
        for(int i =0;i<10;i++)
            for(int j = 0;j<10;j++)
                {
                    if((cost[i][j] !=0) && (cost[i][j] != infinity))
                        return 1;

                }
        return 0;
    }
    int getIndex(char *vname)
    {
        for(int i = 0;i<n;i++)
            if(strcmp(vertices[i],vname)==0)
                return i;
            return -1;
    }
    void addVertices()
    {
        char vname[15];
        cout<<"\n Enter vertex name:";
        cin>>vname;
        int i = getIndex(vname);
        if(i != -1)
        {
            cout<<endl<<"Vertex already exist"<<endl;
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
            cout<<"\n No vertex exist you must have to add a vertex"<<endl;
            return;
        }
        while(1)
        {
            cout<<endl<<"Enter the source vertex";
            cin>>v1;
            i1 = getIndex(v1);
            if(i1 == -1)
                cout<<endl<<"source vertex does not exist ,You must first add a vertex"<<endl;
            else
                break;
        }
        while(1)
        {
            cout<<endl<<"Enter the destination vertex";
            cin>>v2;
            i2 =  getIndex(v2);
            if(i2 == -1)
                cout<<endl<<"Destination vertex does not exist,you must first have to add a vertex"<<endl;
            else
                break;
        }
        cout<<"\nEnter the edge of the cost";
        cin>>cost[i1][i2];

    }
    void display()
    {
        if(n==0)
        {
            cout<<"Graph does not exist\n";
            return;
        }
        cout<<endl<<"Vertices:"<<endl;
        for(int i = 0;i<n;i++)
            cout<<vertices[i]<<endl;

        if(edgeExist())
        {
            cout<<endl<<"Edges:"<<endl;
            for(int i =0;i<n;i++)
                for(int j =0;j<n;j++)
                {
                    if((cost[i][j] !=0) &&(cost[i][j] != infinity))
                        cout<<vertices[i]<<" -> "<<vertices[j]<<" -> "<<cost[i][j]<<endl;
                }
        }
    }

    void findShortestPath()
    {
        int Distance[10];
        int Final[10];
        char Source[15];
        int src;
        if(n==0)
        {
            cout<<"\n Graph does not exist.You must have to first insert some edge and vertices";
            return;
        }
        while(1)
        {

        }
    }
};

