#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string input;
size_t pos = 0;

bool E();
bool T();
bool F();

void skipSpaces()
{
    while (pos < input.size() && isspace((unsigned char)input[pos]))
        pos++;
}


bool F()
{
    skipSpaces();

    if (pos < input.size() && isdigit((unsigned char)input[pos]))
    {
        while (pos < input.size() && isdigit((unsigned char)input[pos]))
            pos++;
        return true;
    }


    if (pos < input.size() && input[pos] == '(')
    {
        pos++;
        if (E())
        {
            skipSpaces();
            if (pos < input.size() && input[pos] == ')')
            {
                pos++;
                return true;
            }
        }
        return false;
    }

    return false;
}

bool T()
{
    skipSpaces();

    if (!F())
        return false;

    while (true)
    {
        skipSpaces();

        if (pos < input.size() && (input[pos] == '*' || input[pos] == '/'))
        {
            pos++;
            if (!F())
                return false;
        }
        else
            break;
    }
    return true;
}


bool E()
{
    skipSpaces();

    if (!T())
        return false;

    while (true)
    {
        skipSpaces();

        if (pos < input.size() && (input[pos] == '+' || input[pos] == '-'))
        {
            pos++;
            if (!T())
                return false;
        }
        else
            break;
    }
    return true;
}

int main()
{
    while (true)
    {
        cout << "Enter a mathematical expression (q to quit): ";
        if (!getline(cin, input))
            break;

        if (input == "q")
            break;

        pos = 0;

        if (E())
        {
            skipSpaces();

            if (pos == input.size())
                cout << "Valid Expression\n";
            else
                cout << "Invalid Expression\n";
        }
        else
        {
            cout << "Invalid Expression\n";
        }
    }

    return 0;
}
