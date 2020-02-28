//#include "paramset.h"

template < typename Key, typename Data >
inline ParamSet<Key, Data>::ParamSet(){
}

template <typename Key, typename Data>
inline void ParamSet<Key, Data>::add(const Key _k, const Data _d ){
    componentes[_k] = _d;
}

template <typename Key, typename Data>
inline Data ParamSet<Key, Data>::getParam(const Key _k){
    return componentes[_k];
}

template <typename Key, typename Data>
inline void ParamSet<Key, Data>::setParam(const Key _k, const Data _d){
    componentes[_k] = _d;
}

template<typename Key, typename Data>
inline void ParamSet<Key, Data>::print(){
    for(auto item : componentes){
        std::cout << " KEY : " << item.first << " - VALUE : " << item.second << std::endl;
    }

    std::cout << std::endl;
}

template <typename Key, typename Data>
inline Data ParamSet<Key, Data>::find(const Key _k, const Data _d ){
    auto valor = componentes[_k];

    if(valor == ""){
        return _d;
    } else{
        return valor;
    }

    return _d;
}