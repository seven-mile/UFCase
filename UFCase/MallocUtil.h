#pragma once

//#include <objidl.h>

#include <memory>

inline auto GetGlobalMalloc() {
	static IMalloc *pMalloc = nullptr;
	if (!pMalloc)
		THROW_IF_FAILED(CoGetMalloc(1, &pMalloc));
	return pMalloc;
}

template<class T>
constexpr auto malloc_deleter = [](T *ptr){
	GetGlobalMalloc()->Free(ptr);
};

template<class T>
using malloc_ptr = std::unique_ptr<T, decltype(malloc_deleter<T>)>;

template<class T>
inline constexpr malloc_ptr<T> make_malloc(T* &raw) {
	//auto &&val = std::make_unique<T, decltype(malloc_deleter<T>)>(*raw);
	auto val = malloc_ptr<T>(static_cast<T*>(raw), malloc_deleter<T>);
	raw = nullptr;
	return std::move(val);
}

using malloc_wstring = malloc_ptr<wchar_t>;
