#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
    int profit,weight;
    float ratio;
};
bool compare (Item a ,Item b)
{
    return a.ratio > b.ratio;
}
int main ()
{
    int n, capacity;
    float totalProfit = 0;
    cout << "Enter no of items: ";
    cin >> n;
    Item item [20];
    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << ":\n";
        cout << "Profit: ";
        cin >> item[i].profit;
        cout << "Weight: ";
        cin >> item[i].weight;
        item[i].ratio = (float)item[i].profit /
                        item[i].weight;
    }
    cout << "Enter knapsack capacity: ";
    cin >> capacity;
    sort(item,item+n,compare);
    cout << "\nSelected Items:\n";
    for(int i = 0; i < n; i++)
    {
        if(capacity == 0)
        break;
        if(item[i].weight <= capacity)
        {
            capacity = capacity - item[i].weight;
            totalProfit = totalProfit + item[i].profit;
            cout << "Profit: " << item[i].profit
                 << "Weight: " << item[i].weight
                 << "Fraction: 1\n";
        }
        else
        {
            float fraction = (float) capacity /
                             item[i].weight;
            totalProfit = totalProfit +
                          item[i].profit * fraction;
            cout << "Profit: " << item[i].profit
                 << "Weight: " << item[i].weight
                 << "Fraction: " << fraction << "\n";
            capacity = 0;
        }
    }
    cout << "\nMaximum Profit = " << totalProfit;
    return 0;
}
