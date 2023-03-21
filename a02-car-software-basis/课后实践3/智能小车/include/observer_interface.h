#ifndef OBSERVER_INTERFACE_H
#define OBSERVER_INTERFACE_H

#include <iostream>
#include <string>
#include <list>

class IObserver
{
public:
    virtual ~IObserver() {}
    virtual void Update(const std::string &message_from_subject) = 0;
};

class ISubject
{
public:
    virtual ~ISubject() {}
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

#endif