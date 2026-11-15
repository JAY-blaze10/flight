/*Marks obtained by students of second year in an onlineexamination of a particular subject are stored by the teacher. 
Teacher wants to findtheminimum and maximum marks of the subject. 
Write a menu driven C++ programtofind out maximum and minimum marks obtained in that subject using heapdatastructure.
Analyze the algorithm
NAME : JAY SANGLE 
ROLL NO : 52
DIV : A 
CLASS : COMPUTER SCIENECE AND DESIGN*/

#include <iostream>
using namespace std;

// Max Heap
void maxHeap(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        int j = i;

        while(2*j + 1 < n)
        {
            int child = 2*j + 1;

            if(child + 1 < n && a[child + 1] > a[child])
                child++;

            if(a[j] < a[child])
            {
                swap(a[j], a[child]);
                j = child;
            }
            else
                break;
        }
    }
}

// Min Heap
void minHeap(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        int j = i;

        while(2*j + 1 < n)
        {
            int child = 2*j + 1;

            if(child + 1 < n && a[child + 1] < a[child])
                child++;

            if(a[j] > a[child])
            {
                swap(a[j], a[child]);
                j = child;
            }
            else
                break;
        }
    }
}

int main()
{
    int marks[100], n, choice;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter marks of students:\n";

    for(int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    do
    {
        cout << "\n\n----- HEAP MENU -----";
        cout << "\n1. Find Maximum Marks";
        cout << "\n2. Find Minimum Marks";
        cout << "\n3. Find Both Minimum and Maximum";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        int temp[100];

        for(int i = 0; i < n; i++)
            temp[i] = marks[i];

        switch(choice)
        {
            case 1:
                maxHeap(temp, n);
                cout << "Maximum Marks = " << temp[0];
                break;

            case 2:
                minHeap(temp, n);
                cout << "Minimum Marks = " << temp[0];
                break;

            case 3:
                maxHeap(temp, n);
                cout << "Maximum Marks = " << temp[0];

                minHeap(temp, n);
                cout << "\nMinimum Marks = " << temp[0];
                break;

            case 4:
                cout << "Exiting program...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while(choice != 4);

    return 0;
}
/* OUTPUT : 
Enter number of students: 5

Enter marks of students:
Student 1: 75
Student 2: 90
Student 3: 65
Student 4: 85
Student 5: 55

----- HEAP MENU -----
1. Find Maximum Marks
2. Find Minimum Marks
3. Find Both Minimum and Maximum
4. Exit

Enter your choice: 3

Maximum Marks = 90
Minimum Marks = 55*/