//#include "paramset.h"

inline ParamSet::ParamSet(){
}

inline ParamSet::~ParamSet(){
    
}



template <typename T>
inline T ParamSet::add(const string & new_key, unique_ptr<T []> values, size_t size){
    std::pair<std::string, shared_ptr<void>> valor (new_key, &values);
    params.insert(valor);
    return values[0];
}

template <typename T>
inline const T & ParamSet::find_one(const string & target_key, const T & d) const{
    unordered_map< string , shared_ptr<void>>::const_iterator params_ = params.find(target_key);
    if(params_ = params.end()){
        return d;
    } else{
        return params_->second;
    }
}