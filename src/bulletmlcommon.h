#ifndef bulletmlcommon_h_
#define bulletmlcommon_h_

#ifdef WIN32_DLL_EXPORT
# define DECLSPEC __declspec(dllexport)
#else
# define DECLSPEC
#endif

#ifndef __EXCEPTIONS
#include <exception>
inline void throw_exception(std::exception const &) {
    // Do nothing or implement custom error handling/logging here
}
#else
// If exceptions are enabled, use the regular throw
template <typename E>
[[noreturn]] inline void throw_exception(E const& e) {
    throw e;
}
#endif

#endif // ! bulletmlcommon_h_
