#ifndef PS
#define PS

#include <iostream>
#include <string>
#include <map>

template < typename Key, typename Data >
class ParamSet
{
    private:
        std::string nome;
        std::map<Key, Data> componentes;

    public:
        ParamSet();
        ParamSet(std::string _n);
        void setNameParam(std::string name);
        void add(const Key _k, const Data _d );
        Data getParam(const Key _k);
        void setParam(const Key _k, const Data _d);
        void print();
};

#include "paramset.inl"
#endif