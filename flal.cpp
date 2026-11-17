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
    vector<pair<int,int>> list[20];
    do
    {
        cout << "\n------Flight Graph Menu------";
        cout << "\n1. Add Flight";
        cout << "\n3. Display Adjacenecy List";
        cout << "\n6. Exit";
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
                bool found = false;
                for (int i = 0;i < list[u].size();i++)
                {
                    if(list[u][i].first == v)
                    {
                        list[u][i].second = cost;
                        found = true;
                        break;
                    }
                }
                if(!found)
                {
                    list[u].push_back({v, cost});
                }
                cout << "Flight added successfully";
                break;
            }
            case 2:
            {
                cout << "\nAdjacency List:\n";
                for(int i = 0;i < n;i++)
                {
                    cout << city[i] << " -> ";
                    for(int j = 0;j < list[i].size();j++)
                    {
                        int v = list[i][j].first;
                        int c = list[i][j].second;
                        cout << city[v] << "(" << c << ") ";
                    }
                    cout << "\n";
                }
                break;
            }
            case 3:
            {
                cout << "\nStorage Comparison:\n";
                cout << "Adjacency Matrix: " << n * n << " entries\n";
                int edges = 0;
                for(int i = 0;i < n;i++)
                edges += list[i].size();
                cout << "Adjacency List: " << n << " city list and " << edges << " edges\n";
                cout << "\nMatrix requires O(V*V) space";
                cout << "\nList requires O(V+E space)";
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