#ifndef TRIANGLEEXCEPTION_HPP
#define TRIANGLEEXCEPTION_HPP

#include <iostream>
#include <exception>

namespace exceptions {
    template <class T>
    class TriangleException : public std::exception {
    public:
        TriangleException() throw();
        explicit TriangleException(const std::string&) throw();
        virtual ~TriangleException();

        virtual const char* what() const throw();

    private:
        std::string message;
    };

    template <class T>
    TriangleException<T>::TriangleException() throw() : std::exception() {}

    template <class T>
    TriangleException<T>::TriangleException(const std::string& msg) throw() : std::exception(), message(msg) {}

    template <class T>
    TriangleException<T>::~TriangleException() {}

    template <class T>
    const char*  TriangleException<T>::what() const throw() {
        return message.c_str();
    }
}

#endif // ! TRIANGLEEXCEPTION_HPP
