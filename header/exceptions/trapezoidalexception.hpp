#ifndef TRAPEZOIDALEXCEPTION_HPP
#define TRAPEZOIDALEXCEPTION_HPP

#include <iostream>
#include <exception>

namespace exceptions {
    template <class T>
    class TrapezoidalException : public std::exception {
    public:
        TrapezoidalException() throw();
        explicit TrapezoidalException(const std::string&) throw();
        virtual ~TrapezoidalException();

        virtual const char* what() const throw();

    private:
        std::string message;
    };

    template <class T>
    TrapezoidalException<T>::TrapezoidalException() throw()
        : std::exception() {}

    template <class T>
    TrapezoidalException<T>::TrapezoidalException(const std::string msg) throw()
        : std::exception(), message(msg) {}

    template <class T>
    TrapezoidalException<T>::~TrapezoidalException() {}

    template <class T>
    const char* TrapezoidalException<T>::what() const throw() {
        return message.c_str();
    }
}

#endif // ! TRAPEZOIDALEXCEPTION_HPP
