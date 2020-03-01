#include "paramset.h"

inline ParamSet::ParamSet()
{
}

inline ParamSet::~ParamSet()
{
}

template <typename T>
inline void ParamSet::add(const string &new_key, unique_ptr<T[]> values, size_t size)
{
    shared_ptr<void> v_ = std::move(values);
    std::pair<std::string, shared_ptr<void>> valor(new_key, v_);
    params.insert(valor);
}

template <typename T>
inline const T & ParamSet::find_one(const string &target_key, const T &d) const
{
    unordered_map<string, shared_ptr<void>>::const_iterator params_ = params.find(target_key);

    if ( params_ == params.end() )
    {
        return d;
    }
    else
    {
        auto v = params_->second;

        shared_ptr<T> valor = static_pointer_cast<T>(v);
        return *valor;
    }
}