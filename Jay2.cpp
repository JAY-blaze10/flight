// Problem Statement
/*String Operations: Write a menu driven C++ program with a class for
String. Write functions
1. To determine the frequency of occurrence of a particular character
in the string.
2. Extract a new string from original string by accepting starting
position and length
3. To accept any character and return the string with by removing all
occurrences of a character accepted
4. To make an in-place replacement of a substring w of a string by the
string x. Note that w may not be of same size that of x */
#include<iostream>
#include<string>
using namespace std;

class StringOp
{
    string s;

public:

    void get()
    

    {
       while(true)
       {
          cout << "Enter a string (only alphabets): ";
          cin >> s;

          int valid = 1;

          for(int i = 0; i < s.length(); i++)
           {
             if(!isalpha(s[i]))
               {
                 valid = 0;
                 break;
                }
            }

        if(valid)
            break;
        else
            cout << "Invalid input! Try again.\n";
        }
    } 

    // 1. Frequency of character
    void frequency()
    {
        char ch;
        int count=0;

        cout<<"Enter character: ";
        cin>>ch;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]==ch)
            count++;
        }

        cout<<"Frequency = "<<count<<endl;
    }

    // 2. Extract substring
    void extract()
    {
        int pos,len;

        cout<<"Enter starting position: ";
        cin>>pos;

        cout<<"Enter length: ";
        cin>>len;

        if(pos>=0 && pos+len<=s.length())
        {
            for(int i=pos;i<pos+len;i++)
                cout<<s[i];
        }
        else
            cout<<"Invalid position or length";

        cout<<endl;
    }

    // 3. Remove character
    void removechar()
    {
        char ch;

        cout<<"Enter character to remove: ";
        cin>>ch;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=ch)
                cout<<s[i];
        }

        cout<<endl;
    }

    // 4. Replace substring using TEMP string
    void replace()
    {
        string w,x;
        string temp = s;

        cout<<"Enter substring to replace: ";
        cin>>w;

        cout<<"Enter new substring: ";
        cin>>x;

        int pos = temp.find(w);

        if(pos!=-1)
        {
            temp.replace(pos,w.length(),x);
            cout<<"New string (temp): "<<temp<<endl;
        }
        else
            cout<<"Substring not found"<<endl;
    }

    // 5. Palindrome check (checks original string)
    void palindrome()
    {
        string rev="";

        for(int i=s.length()-1;i>=0;i--)
            rev+=s[i];

        if(rev==s)
            cout<<"Palindrome"<<endl;
        else
            cout<<"Not Palindrome"<<endl;
    }
};

int main()
{
    StringOp obj;
    int choice;

    obj.get();

    do
    {
        cout<<"\n1. Frequency";
        cout<<"\n2. Extract substring";
        cout<<"\n3. Remove character";
        cout<<"\n4. Replace substring (temp)";
        cout<<"\n5. Palindrome check";
        cout<<"\n6. Exit";

        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: obj.frequency(); break;
            case 2: obj.extract(); break;
            case 3: obj.removechar(); break;
            case 4: obj.replace(); break;
            case 5: obj.palindrome(); break;
        }

    }while(choice!=6);

    return 0;
}
/*sudo dmesg -C && sudo rm -rf /var/log/kern* && sudo rm -rf/var/log/syslog* && sudo rm -rf
/var/log/journal/ && sudo rm -rf /run/log/journal/ 
history -c  */