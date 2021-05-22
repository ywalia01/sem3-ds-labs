#include <iostream>
#include <string.h>
using namespace std;

class example
{
public:
    char s1[25], s2[25];
    example(char str1[], char str2[])
    {
        strcpy(this->s1, str1);
        strcpy(this->s2, str2);
    }
    void operator+()
    {
        cout << "\n\nConcatenation: " << strcat(s1, s2) << "\n\n";
    }
};

int main()
{
    char str1[] = "Inter";
    char str2[] = "Planetary";

    example e1(str1, str2);

    +e1;
    return 0;
}