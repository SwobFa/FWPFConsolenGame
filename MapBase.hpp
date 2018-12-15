#ifndef MAP_HPP
#define MAP_HPP

#include <string>

using namespace std;

class MapBase
{
public:
    virtual ~MapBase() {}
    string Name;
    char * Design_ptr = nullptr;
};

#endif // MAP_HPP
