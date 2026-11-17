#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n,choice,cost;
    string city [20];
    cout << "Enter no. of cities:";
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cout << "Enter city" << i+1 << ":";
        cin >> city[i];
    }
    int adj[20][20] = {0};
    do
    {
        cout << "\n------Flight Graph Menu------";
        cout << "\n1. Add Flight";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. Check Flight Connection";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                int u,v;
                cout << "Enter source city index (0 to " << n-1 << "): ";
                cin >> u;
                cout << "Enter destination city index (0 to " << n-1  << "): ";
                cin >> v;
                if (u < 0 || u >= n || v < 0 || v >= n || u == v )
                {
                    cout << "Invalid city index";
                    break;
                }
                cout << "Enter flight cost";
                cin >> cost;
                adj[u][v] = cost;
                cout << "Flight added successfully";
                break;
            }
            case 2:
            {
                cout << "\nAdjacency Matrix:\n";
                cout << "\t";
                for(int i = 0;i < n;i++)
                cout << city[i] << "\t";
                cout << "\n";
                for(int i = 0;i < n;i++)
                { 
                    cout << city[i] << "\t";
                    for(int j = 0;j < n;j++)
                    {
                      cout << adj[i][j] << "\t";
                    }
                    cout << "\n";
                }
                break;
            }
            case 3:
            {
                int u,v;
                cout << "Enter source city index: ";
                cin >> u;
                cout << "Enter destination city index: ";
                cin >> v;
                if( u < 0 || u >= n || v < 0 || v >= n || u == v)
                {
                    cout << "Invalid Index!";
                }
                else if(adj[u][v] != 0)
                {
                    cout << "Flight exists between " << city[u] << " and " << city[v];
                }
                else
                {
                    cout << "No direct flight exists between " << city[u] << " and " << city[v];
                }
                break;
            }
            case 4:
            cout << "Exiting Program...";
            break;
            default:
            cout << "Invalid Choice!";
        }

    }while(choice!=4);
    return 0;
}