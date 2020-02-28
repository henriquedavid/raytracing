//#include "paramset.h"

inline ParamSet::ParamSet(){
}

inline ParamSet::~ParamSet(){
    
}

template <typename T>
inline T ParamSet::add(const string & new_key, unique_ptr<T []> values, size_t size){
    return 11;
}

template <typename T>
inline const T & ParamSet::find_one(const string & target_key, const T & d) const{

}