#ifndef TRIANGLEEXCEPTION_HPP
#define TRIANGLEEXCEPTION_HPP

#include <iostream>
#include <exception>

namespace exceptions {
    template <class T>
    class TriangleException : public std::runtime_error {
    public:
        explicit TriangleException(const std::string&) throw();
    };

    template <class T>
    TriangleException<T>::TriangleException(const std::string& msg) throw()
            : std::runtime_error(msg.c_str()) {}
}

#endif // ! TRIANGLEEXCEPTION_HPP
