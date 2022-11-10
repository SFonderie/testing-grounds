#ifndef FUNCTION_REGISTRY_CPP
#define FUNCTION_REGISTRY_CPP

#include "FunctionRegistry.h"

template <typename ReturnType, typename ... ArgumentTypes>
FunctionRegistry<ReturnType, ArgumentTypes...>::FunctionRegistry() {  }

template <typename ReturnType, typename ... ArgumentTypes>
void FunctionRegistry<ReturnType, ArgumentTypes...>::Add(ReturnType(*function)(ArgumentTypes...), const std::string key)
{
	this->functions.emplace(key, function);
	this->keys.emplace(key);
}

template <typename ReturnType, typename ... ArgumentTypes>
ReturnType* const FunctionRegistry<ReturnType, ArgumentTypes...>::Get(const std::string key) const
{
	return this->functions.at(key);
}

template <typename ReturnType, typename ... ArgumentTypes>
ReturnType FunctionRegistry<ReturnType, ArgumentTypes...>::Evaluate(const std::string key, ArgumentTypes ... args) const
{
	return (*(this->functions.at(key)))(args...);
}

#endif
