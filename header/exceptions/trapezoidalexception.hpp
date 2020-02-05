#ifndef TRAPEZOIDALEXCEPTION_HPP
#define TRAPEZOIDALEXCEPTION_HPP

#include <iostream>
#include <exception>

namespace exceptions {
    template <class T>
    class TrapezoidalException : public std::runtime_error {
    public:
        explicit TrapezoidalException(const std::string&) throw();
    };

    template <class T>
    TrapezoidalException<T>::TrapezoidalException(const std::string& msg) throw()
            : std::runtime_error(msg.c_str()) {}
}

#endif // ! TRAPEZOIDALEXCEPTION_HPP
