#ifndef STANDARDDEVIATIONEXCEPTION_HPP
#define STANDARDDEVIATIONEXCEPTION_HPP

#include <iostream>
#include <exception>

namespace exceptions {
    template <class T>
    class StandardDeviationException : public std::runtime_error {
    public:
        explicit StandardDeviationException(const std::string&) throw();
    };

    template <class T>
    StandardDeviationException<T>::StandardDeviationException(const std::string& msg) throw()
            : std::runtime_error(msg.c_str()) {}
}

#endif // ! STANDARDDEVIATIONEXCEPTION_HPP
