#ifndef STANDARDDEVIATIONEXCEPTION_HPP
#define STANDARDDEVIATIONEXCEPTION_HPP

#include <iostream>
#include <exception>

namespace exceptions {
    template <class T>
    class StandardDeviationException : public std::exception {
    public:
        StandardDeviationException() throw();
        explicit StandardDeviationException(const std::string&) throw();
        virtual ~StandardDeviationException();

        virtual const char* what() const throw();

    private:
        std::string message;
    };

    template <class T>
    StandardDeviationException<T>::StandardDeviationException() throw() : std::exception() {}

    template <class T>
    StandardDeviationException<T>::StandardDeviationException(const std::string& msg) throw()
            : std::exception(), message(msg) {}

    template <class T>
    StandardDeviationException<T>::~StandardDeviationException() {}

    template <class T>
    const char* StandardDeviationException<T>::what() const throw() {
        return message.c_str();
    }
}

#endif // ! STANDARDDEVIATIONEXCEPTION_HPP
