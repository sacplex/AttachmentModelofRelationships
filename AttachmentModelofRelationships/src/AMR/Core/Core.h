#pragma once

#include <memory>
#include <iostream>
#include <unordered_map>

namespace AMR {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	using String = std::string;

	template<typename K, typename V>
	using Map = std::unordered_map<K,V>;
}