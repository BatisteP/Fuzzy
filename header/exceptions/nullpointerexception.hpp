#ifndef NULLPOINTEREXCEPTION_HPP
#define NULLPOINTEREXCEPTION_HPP

#include <iostream>
#include <exception>

namespace exceptions {
    template <class T>
    class NullPointerException : public std::runtime_error {
    public:
        explicit NullPointerException(const std::string&) throw();
    };

    template <class T>
    NullPointerException<T>::NullPointerException(const std::string& msg) throw()
            : std::runtime_error(msg.c_str()) {}


}

#endif // ! NULLPOINTEREXCEPTION_HPP
