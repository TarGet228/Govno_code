
#include <iostream>
#include <Windows.h>
using namespace std;

class List
{
    char ch;
    List* next;
public:
    void set(char c, List* n_c)
    {
        ch = c;
        next = n_c;
    }
    char info_ch()
    {
        return ch;
    }
    List* info_next()
    {
        return next;
    }
};

class Stack : public List
{
    List* pres;
public:
    Stack()
    {
        pres = NULL;
    }
    bool st_empty()
    {
        return pres == NULL;
    }
    void push(char ch)
    {
        List* next_ch = new List;
        next_ch->set(ch, pres);
        pres = next_ch;
    }
    char peek()
    {
        if (!st_empty())
            return pres->info_ch();
    }
    void pop()
    {
        if (!st_empty())
        {
            List* past = pres->info_next();
            delete pres;
            pres = past;
        }
    }
    void task(Stack S)
    {
        int s1 = 0, s2 = 0, s3 = 0;
        bool t = true;
        char ch;
        while (t && !S.st_empty())
        {
            ch = S.peek();
            switch (ch)
            {
            case '(':--s1; break;
            case ')':++s1; break;
            case '<':--s1; break;
            case '>':++s1; break;
            case '{':--s2; break;
            case '}':++s2; break;
            case '[':--s3; break;
            case ']':++s3; break;
            default:break;
            }
            if (s1 >= 0 && s2 >= 0 && s3 >= 0)
                t = true;
            else
                t = false;
            S.pop();
        }
        if (t && s1 == 0 && s2 == 0 && s3 == 0)
            cout << "Wright" << endl;
        else
            cout << "Wrong" << endl;
    }
};
int main()
{
    char ch;
    Stack c;
    cout << "Enter string" << endl;
    cin >> ch;
    while (ch != '.')
    {
        c.push(ch);
        cin >> ch;
    }
    c.task(c);
}