#ifndef FUNCTION_REGISTRY_H
#define FUNCTION_REGISTRY_H

#include <map>
#include <set>
#include <string>

/// <summary>
/// This class serves as map of functions with the defined characteristics. Clients will be able
/// to defineand add functions to the registryand then have Users call functions via string input
/// rather than switch statements.
/// </summary>
/// <typeparam name="ReturnType">Return type for functions to emplace.</typeparam>
/// <typeparam name="...ArgumentTypes">Argument types for functions to emplace.</typeparam>
template <typename ReturnType, typename ... ArgumentTypes>
class FunctionRegistry
{

private:

	/// <summary>
	/// Map of all functions.
	/// </summary>
	std::map<std::string, ReturnType(*)(ArgumentTypes...)> functions;

	/// <summary>
	/// Set of all keys emplaced in the function map.
	/// </summary>
	std::set<std::string> keys;

public:

	/// <summary>
	/// Initializes containers.
	/// </summary>
	FunctionRegistry();

	/// <summary>
	/// Adds a function to the registry with the given key.
	/// </summary>
	/// <param name="func">Function to register.</param>
	/// <param name="key">Key for the registered function.</param>
	void Add(ReturnType(*function)(ArgumentTypes...), const std::string key);

	/// <summary>
	/// Accesses the function pointer at the given key.
	/// </summary>
	/// <param name="key">Key to the function to return.</param>
	/// <returns>Function at the given key.</returns>
	ReturnType* const Get(const std::string key) const;

	/// <summary>
	/// Evaluates the function pointer at the given key with the given arguments.
	/// </summary>
	/// <param name="key">Key to the function to evaluate.</param>
	/// <param name="...args">Arguments to pass into the function.</param>
	/// <returns>Output of the function.</returns>
	ReturnType Evaluate(const std::string key, ArgumentTypes ... args) const;
};

#include "FunctionRegistry.cpp"

#endif
