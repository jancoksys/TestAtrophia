#include <iostream>
#include <tchar.h>
#include <vector>
#include <string>

bool IsEquationSolvable(int A, int B, int C)
{
    int D = B^2 - 4*A*C;
    if (D < 0)
    {
        return false;
    }
    return true;
}

TCHAR* GetNewStr(TCHAR* Str, bool& IsEqual)
{
    std::vector<TCHAR> chars;
    IsEqual = true;
    TCHAR* NewStr;
    int length = 0;
    for (int i = 0; Str[i] != '\0'; i++)
    {
        chars.push_back(Str[i]);
        if (Str[i+1] == '\0')
        {
            length = i + 1;
        }
    }
    if (length == 0)
    {
        return Str;
    }
    NewStr = new TCHAR[length + 1];
    NewStr[0] = chars[length - 1];
    for (int i = 0; i < length; i++)
    {
        NewStr[i+1] = chars[i];   
        if (i == length - 1)
        {
            NewStr[i+1] = '\0';
        }     
    }
    for (int i = 0; i < length; i++)
    {
        if (Str[i] != NewStr[i])
        {
            IsEqual = false;
            break;
        }
    }
    return NewStr;
}

int main()
{
    int a = 1, b = -2, c = 1;
    bool isSolvable = IsEquationSolvable(a,b,c);
    TCHAR str[] = _TEXT("abc");
    bool isEqual;
    TCHAR* NewStr = GetNewStr(str, isEqual);

    return 0;
}