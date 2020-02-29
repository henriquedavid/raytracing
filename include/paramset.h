#ifndef PS
#define PS

#include <iostream>
#include <memory>
#include <string>
#include <utility> 
#include <unordered_map>

using namespace std;

class ParamSet
{
    private:
        unordered_map< string , shared_ptr<void>> params;

    public:
        ParamSet();
        ~ParamSet();
        // Add a list of values of Type T to the dictionary.
        template < typename T >
        void add(const string &new_key, unique_ptr<T []> values, size_t size );
        // Find and return a single item from the ParamSet.
        template < typename T >
        const T & find_one(const string &target_key, const T & d) const;
};

#include "paramset.inl"
#endif