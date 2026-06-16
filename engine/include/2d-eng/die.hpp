#pragma once

#include <format>
#include <iostream>

template<class... Args>
[[noreturn]]
inline void die(std::format_string<Args...> str, Args&&... args) {
	std::println(std::cerr, str, std::forward<Args>(args)...);
	abort();
}
