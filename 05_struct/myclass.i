%include "string.i"

%module myclass
%{
#include <string>
#include "my_class.h"
%}

%extend MyClass {
    std::string __repr__()
    {
        return $self->getName();
    }
}

%include "myclass.h"
