#ifndef NULLPOINTEREXCEPTION_HPP
#define NULLPOINTEREXCEPTION_HPP

#include <iostream>
#include <exception>

namespace exceptions {
    template <class T>
    class NullPointerException : public std::exception {
    public:
        NullPointerException() throw();
        explicit NullPointerException(const std::string&) throw();
        virtual ~NullPointerException();

        virtual const char* what() const throw ();

    private:
        std::string message;
    };

    template <class T>
    NullPointerException<T>::NullPointerException() throw() : std::exception() {}

    template <class T>
    NullPointerException<T>::NullPointerException(const std::string& msg) throw()
            : std::exception(), message(msg) {}

    template <class T>
    NullPointerException<T>::~NullPointerException() {}

    template <class T>
    const char* NullPointerException<T>::what() const throw() {
        return message.c_str();
    }
}

#endif // ! NULLPOINTEREXCEPTION_HPP
