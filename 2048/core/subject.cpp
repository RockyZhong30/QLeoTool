#include "subject.h"
#include "observer.h"

Subject::Subject()
{
}

void Subject::notifyObservers()
{
//    for (Observer* o : observers)
//        o->notify();
    Observer* o;
    for(int i = 0; i < observers.size(); i++)
    {
        o = observers[i];
        o->notify();
    }


}

void Subject::registerObserver(Observer* observer)
{
    observers.push_back(observer);
}
