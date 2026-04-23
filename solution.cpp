
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class mystring
{
private:
    char *ch = nullptr;
    int len = 0;

public:

    mystring()
    {
        // TODO
        ch = nullptr;
        len = 0;
    }
    mystring(int _len, int c)
    {
        // TODO
        len = _len;
        ch = new char[len + 1];
        for (int i = 0; i < len; i++) {
            ch[i] = (char)c;
        }
        ch[len] = '\0';
    }
    mystring(string &c)
    {
        // TODO
        len = c.length();
        ch = new char[len + 1];
        for (int i = 0; i < len; i++) {
            ch[i] = c[i];
        }
        ch[len] = '\0';
    }
    ~mystring()
    {
        // TODO
        if (ch != nullptr) {
            delete[] ch;
            ch = nullptr;
        }
        len = 0;
    }

    // TODO
    char operator[](int x) {
        if (x >= 0 && x < len) {
            return ch[x];
        }
        return '\0';
    }

    bool operator<(const mystring &other) const {
        int min_len = (len < other.len) ? len : other.len;
        for (int i = 0; i < min_len; i++) {
            if (ch[i] < other.ch[i]) {
                return true;
            } else if (ch[i] > other.ch[i]) {
                return false;
            }
        }
        return len < other.len;
    }

    void ADD(const mystring &other) {
        int new_len = len + other.len;
        char *new_ch = new char[new_len + 1];
        
        for (int i = 0; i < len; i++) {
            new_ch[i] = ch[i];
        }
        for (int i = 0; i < other.len; i++) {
            new_ch[len + i] = other.ch[i];
        }
        new_ch[new_len] = '\0';
        
        if (ch != nullptr) {
            delete[] ch;
        }
        ch = new_ch;
        len = new_len;
    }

    void out() {
        if (ch != nullptr) {
            for (int i = 0; i < len; i++) {
                putchar(ch[i]);
            }
        }
    }

    int get_len() {
        return len;
    }
};

string str_in1, str_in2;
int n, id;
int main()
{
    cin >> id;
    if (id == 1)
    {
        mystring str1(100,'a');
        str1.out(); puts("");
        // cout << str1 << endl;
    }
    else if (id == 2)
    {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str2[x] << endl;
        }
    }
    else if (id == 3)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << endl;
    }
    else if (id == 4)
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
    }
    else
    {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++ i)
        {
            cin >> x;
            cout << str3[x] << endl;
        }
        cout << str2.get_len() << " " << str3.get_len() << endl;
        cout << (int)(str2 < str3) << endl;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
        cout << str2.get_len() << endl;
    }
    return 0;
}
