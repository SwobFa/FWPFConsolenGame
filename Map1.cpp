#include "MapBase.hpp"
#include <iostream>
class Map1 : public MapBase
{
public:
    Map1()
    {
        Name = "Map 1";
        Design_ptr = {
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX                                                          X"
            /*"X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "X                                                          X"
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"*/
        };
    }


};
