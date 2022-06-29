 #include <iostream>
using namespace std;
bool graph[100][100];
int display[100][100];

bool max(int u, bool visited[], int a[],int x,int y) {
for (int v = 0; v < y; v++) {
if (graph[u][v] && !visited[v]) {
visited[v] = true;
if (a[v] < 0 || max(a[v], visited, a,x,y)) {
a[v] = u;
display[u][v]=1;
return true;
}
}
}
return false;
}

int maxPair(int x,int y) {
int a[y];
for(int i = 0; i<y; i++)
a[i] = -1;
int Count = 0;
for (int u = 0; u < x; u++) {
bool visited[y];
for(int i = 0; i<y; i++)
visited[i] = false;
if (max(u, visited, a,x,y))
Count++;
}
return Count;
}

int main() {
int x,y;
cout<<"enter number of elements of first set\n";
cin>>x;
cout<<"enter number of elements of second set\n";
cin>>y;
cout<<"Enter the adjacency matrix:"<<endl;
for(int i=0;i<x;i++)
{
    cout<<"Row "<<i+1<<" Elements :"<<endl; 
    for(int j=0;j<y;j++)
    {
        cin>>graph[i][j];
    }
}
cout << "Maximum number of matching pairs is "<< maxPair(x,y)<<endl;
return 0;
}

