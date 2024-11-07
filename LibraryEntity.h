#ifndef LIBRARYENTITY_H
#define LIBRARYENTITY_H

#include <string>

class LibraryEntity {
public:
    virtual ~LibraryEntity() = default;
    virtual std::string to_string() const = 0;
    virtual void display() const = 0;
};

#endif // LIBRARYENTITY_H