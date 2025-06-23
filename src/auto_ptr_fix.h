#ifndef unique_ptr_fix_h_
#define unique_ptr_fix_h_

#include <memory>

// Transfer ownership from rhs to lhs (move semantics)
template <class T_>
inline void unique_ptr_move(std::unique_ptr<T_>& lhs, std::unique_ptr<T_> rhs) {
    lhs = std::move(rhs);
}

// Create a unique_ptr from raw pointer and assign to lhs
template <class T_>
inline void unique_ptr_move(std::unique_ptr<T_>& lhs, T_* rhs) {
    std::unique_ptr<T_> p(rhs);
    lhs = std::move(p);
}

#endif // ! unique_ptr_fix_h_