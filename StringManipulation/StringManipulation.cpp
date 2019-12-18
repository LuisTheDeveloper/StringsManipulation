#include <vector>
#include <iostream>
#include <string>

using namespace std;

string implode(const string& glue, const vector<string>& pieces);
vector<string> GetUserInput(const string& delimiter, const string& str);
void ReadString(string& str, vector<string>& arr, string& delim);

int main(int argc, char* argv[])
{
    vector<string>arr1;
    string delim, value;
    int option, i, strlen;

    std::cout << "Type the delimiter character, in the end hit return " << std::endl;
    std::cin >> delim;
    std::cout << "Type a sentence, words separated by the delimiter defined before, in the end hit return " << std::endl;
    std::cin >> value;
    std::cout << "What action do you want: 1-Explode, 2-Implode, 3-Noplode. In the end hit return " << std::endl;
    std::cin >> option;
    
    switch (option)
    {
    case 1:
            arr1 = GetUserInput(delim, value);
            for (int i = 0; i < arr1.size(); i++)
            {
                cout << i << " [" << arr1[i] << "] " << endl;
            }
            break;
    case 2:
            cout << implode(delim, arr1) << endl;
            break;
    case 3:
            ReadString(value, arr1, delim);
            strlen = arr1.size();
            i = 0;
            while (i < strlen)
            {
                cout << arr1[i] << endl;
                i++;
            }
            break;
    }
    
}

vector<string> GetUserInput(const string& delimiter, const string& str)
{
    vector<string>arr;

    int strlen = str.length();
    int dellen = delimiter.length();
    if (dellen == 0)
        return arr;

    int i = 0;
    int k = 0;
    while (i < strlen)
    {
        int j = 0;
        while (i + j < strlen && j < dellen && str[i + j] == delimiter[j])
            j++;
        if (j == dellen) 
        {
            arr.push_back(str.substr(k, i - k));
            i += dellen;
            k = i;
        }
        else
        {
            i++;
        }
    }
    arr.push_back(str.substr(k, i - k));
    return arr;
}

void ReadString(string& str, vector<string>& arr, string& delim)
{
    int leng = str.size();
    string a;

    for (int i = 0; i < leng; i++)
    {
        if (str.substr(i, 1) == delim)
        {
            if (a.size() > 0)
            {
                arr.push_back(a);
                a.clear();
            }
        }
        else
        {
            a += str.substr(i,1);
        }
    }
    if (a.size() > 0)
        arr.push_back(a);

}

string implode(const string& glue, const vector<string>& pieces)
{
    string a;
    int leng = pieces.size();
    for (int i = 0; i < leng; i++)
    {
        a += pieces[i];         // Grab each element of the array: each position is equivalent at each element inside the array.
        if (i < (leng - 1))     // As long there are more elements of the array to read (< array length size)
            a += glue;          // keep adding the delimiter between the array elements
    }
    return a;
}

