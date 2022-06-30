#include <iostream>

void ch1()
{
    std::string str = "Eugene_message";

    std::string nickname[10], data[255];
    int i = 0;

    while (str[i] != '_')
    {
        nickname[i] = str[i];
        i++;
    }


    int j = 0;
    i++;

    while (str[i])
        data[j++] = str[i++];

    i = 0;
    while (nickname[i] != "\0")
    {
        std::cout << nickname[i++];
    }
    i = 0;
    std::cout << "\t";
    while (data[i] != "\0")
    {
        std::cout << data[i++];
    }
    //std::cout << nickname[0] << "\t" << data[0];
}

void ch2()
{
    char str[255] = "Eugene_message";
    char* p = str;
    char nickname[10]{}, data[255]{};
    //std::cout << *(++p);
    int i = 0;

    while (*p != '_')
    {
        nickname[i++] = *p++;
    }
    p++;
    i = 0;
    while (*p)
    {
        data[i++] = *p++;
    }

    i = 0;
    while (i < 10)
        std::cout << nickname[i++];

    std::cout << "\t";

    i = 0;
    while (i < 8)
        std::cout << data[i++];

    std::cout << std::endl << sizeof(nickname) / sizeof(nickname[0]);
}