#include <iostream>
#include <string>
using namespace std;

string reverseword(string str)
{
    string rs;

    for(int i = str.length() - 1; i >= 0; i--)
    {
        rs += str[i];
    }
    return rs;
}

int main()
{
    char arr[100];

    // Input using the getline function.
    string result;
    cin.getline(arr, 100);
    char separator = ' ';
    int i = 0;

    // Temporary string used to split the string.
    string s;
    while (arr[i] != '\0')
    {
        if (arr[i] != separator)
        {
            // Append the char to the temp string.
            s += arr[i];
        }
        else
        {
            // Reverse the word and append to result.
            result += reverseword(s);
            result += " "; // Add a space between words.
            s.clear();
        }
        i++;
    }

    // Reverse the last word and append to result.
    result += reverseword(s);

    // Print the final result.
    cout << result << endl;
}
