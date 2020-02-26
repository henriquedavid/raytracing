//#include "paramset.h"

template < typename Key, typename Data >
inline ParamSet<Key, Data>::ParamSet(){
    nome = "";
}

template < typename Key, typename Data >
inline ParamSet<Key, Data>::ParamSet(std::string _n){
    nome = _n;
}

template<typename Key, typename Data>
inline void ParamSet<Key, Data>::setNameParam(std::string name){
    nome = name;
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
    std::cout << "NOME OBJETO : " << nome << std::endl;
    for(auto item : componentes){
        std::cout << " KEY : " << item.first << " - VALUE : " << item.second << std::endl;
    }

    std::cout << std::endl;

}