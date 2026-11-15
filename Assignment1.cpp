/*PROBLEM STAEMENT :  There are flight paths between cities. If there is a flight betweencity A and city B, then there is an edge between the cities. 
The cost of the edge canbethe time that flight takes to reach city B from A, or the amount of fuel used for thejourney. 
Write a menu driven C++ program to represent this as a graph using adjacency matrixand adjacency list. 
The node can be represented by the airport name or name of the city. Check whether cities are connected through flight or not. Compare the storagerepresentation.
NAME : JAY SANGLE 
ROLL NO : 52
DIV : A
CLASS : COMPUTER SCIENCE AND DESIGN*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n, choice, cost;
    string city[20];
    
    cout << "Enter number of cities: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter city " << i + 1 << ": ";
        cin >> city[i];
    }

    int adj[20][20] = {0};
    vector<pair<int, int>> list[20];

    do
    {
        cout << "\n----- FLIGHT GRAPH MENU -----";
        cout << "\n1. Add Flight";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. Display Adjacency List";
        cout << "\n4. Check Flight Connection";
        cout << "\n5. Compare Storage";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int u, v;

                cout << "Enter source city index (0 to "
                     << n-1 << "): ";
                cin >> u;

                cout << "Enter destination city index (0 to "
                     << n-1 << "): ";
                cin >> v;

                if(u < 0 || u >= n || v < 0 || v >= n)
                {
                    cout << "Invalid city index!";
                    break;
                }

                cout << "Enter flight cost: ";
                cin >> cost;

                adj[u][v] = cost;

                bool found = false;

                for(int i = 0; i < list[u].size(); i++)
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

                cout << "Flight added successfully!";
                break;
            }

            case 2:
            {
                cout << "\nAdjacency Matrix:\n";

                cout << "\t";
                for(int i = 0; i < n; i++)
                    cout << city[i] << "\t";

                cout << "\n";

                for(int i = 0; i < n; i++)
                {
                    cout << city[i] << "\t";

                    for(int j = 0; j < n; j++)
                    {
                        cout << adj[i][j] << "\t";
                    }

                    cout << "\n";
                }
                break;
            }

            case 3:
            {
                cout << "\nAdjacency List:\n";

                for(int i = 0; i < n; i++)
                {
                    cout << city[i] << " -> ";

                    for(int j = 0; j < list[i].size(); j++)
                    {
                        int v = list[i][j].first;
                        int c = list[i][j].second;

                        cout << city[v] << "(" << c << ") ";
                    }

                    cout << "\n";
                }
                break;
            }

            case 4:
            {
                int u, v;

                cout << "Enter source city index: ";
                cin >> u;

                cout << "Enter destination city index: ";
                cin >> v;

                if(u < 0 || u >= n || v < 0 || v >= n)
                {
                    cout << "Invalid city index!";
                }
                else if(adj[u][v] != 0)
                {
                    cout << "Flight exists between "
                         << city[u] << " and " << city[v];
                }
                else
                {
                    cout << "No direct flight exists between "
                         << city[u] << " and " << city[v];
                }
                break;
            }

            case 5:
            {
                cout << "\nStorage Comparison:\n";

                cout << "Adjacency Matrix: "
                     << n * n << " entries\n";

                int edges = 0;

                for(int i = 0; i < n; i++)
                    edges += list[i].size();

                cout << "Adjacency List: "
                     << n << " city lists and "
                     << edges << " edges\n";

                cout << "\nMatrix requires O(V*V) space.";
                cout << "\nList requires O(V+E) space.";
                break;
            }

            case 6:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while(choice != 6);

    return 0;
}
/* OUTPUT:
Enter number of cities: 4

Enter city 1: Mumbai
Enter city 2: Delhi
Enter city 3: Pune
Enter city 4: Chennai

----- FLIGHT GRAPH MENU -----
1. Add Flight
2. Display Adjacency Matrix
3. Display Adjacency List
4. Check Flight Connection
5. Compare Storage
6. Exit

Enter your choice: 1

Enter source city index: 0
Enter destination city index: 1
Enter flight cost: 1200

Flight added successfully!
Enter your choice: 1
Enter source city index: 0
Enter destination city index: 2
Enter flight cost: 500

Flight added successfully!
Adjacency Matrix:

        Mumbai  Delhi   Pune    Chennai
Mumbai    0     1200    500       0
Delhi     0       0       0       0
Pune      0       0       0       0
Chennai   0       0       0       0

Adjacency List:

Mumbai -> Delhi(1200) Pune(500)
Delhi ->
Pune ->
Chennai ->
Enter source city index: 0
Enter destination city index: 1

Flight exists between Mumbai and Delhi*/