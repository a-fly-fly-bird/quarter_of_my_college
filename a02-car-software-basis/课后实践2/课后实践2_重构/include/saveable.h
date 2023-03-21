#ifndef SAVEABLE_H
#define SAVEABLE_H

#include<string>

class Saveable{
public:
    virtual bool Save(const std::string &) const = 0;
};

#endif