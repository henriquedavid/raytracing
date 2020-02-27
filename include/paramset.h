#ifndef PS
#define PS

#include <iostream>
#include <string>
#include <map>
#include <typeinfo>   // operator typeid
#include <sstream> 

template < typename Key, typename Data >
class ParamSet
{
    private:
        std::map<Key, Data> componentes;

    public:
        ParamSet();
        void add(const Key _k, const Data _d );
        Data getParam(const Key _k);
        void setParam(const Key _k, const Data _d);
        void print();
        template <typename Tipo>
        Tipo find(const Key _k, const Tipo _d );
};

#include "paramset.inl"
#endif