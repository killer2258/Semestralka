#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures
{

    Vector::Vector(size_t size) :
        memory_(calloc(size, 1)),
        size_(size)
    { }

    Vector::Vector(const Vector& other) :
        Vector(other.size_)
    {
        memcpy(memory_, other.memory_, size_);
    }

    Vector::~Vector()
    {
        free(memory_);
        memory_ = nullptr;
        size_ = 0;
    }

    Structure* Vector::clone() const
    {
        return new Vector(*this);
    }

    size_t Vector::size() const
    {
        return size_;
    }

    Structure& Vector::operator=(const Structure& other)
    {
        if (this != &other)
        {
            *this = dynamic_cast<const Vector&>(other);
        }
        return *this;
    }

    Vector& Vector::operator=(const Vector& other)
    {
        if (this != &other)
        {
            size_ = other.size_;
            memory_ = realloc(memory_, size_);
            memcpy(memory_, other.memory_, size_);
        }
        return *this;
    }

    bool Vector::operator==(const Vector& other) const
    {
        return this == &other ? true : size_ == other.size_ && memcmp(memory_, other.memory_, size_) == 0;
    }

    byte& Vector::operator[](const int index)
    {
        DSRoutines::rangeCheckExcept(index, size_, "Out of range");
        return *(reinterpret_cast<byte*>(memory_) + index);
    }

    byte Vector::operator[](const int index) const
    {
        DSRoutines::rangeCheckExcept(index, size_, "Out of range");
        return *(reinterpret_cast<byte*>(memory_) + index);
    }

    byte& Vector::readBytes(const int index, const int count, byte& dest)
    {
        DSRoutines::rangeCheckExcept(index + count - 1, size_, "Out of range");
        memcpy(&dest, getBytePointer(index), count);
        return dest;
    }

    void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
    {
        DSRoutines::rangeCheckExcept(srcStartIndex + length - 1, src.size_, "Out of range");
        DSRoutines::rangeCheckExcept(destStartIndex + length - 1, dest.size_, "Out of range");

        if (&src == &dest && srcStartIndex + length > destStartIndex&& destStartIndex >= srcStartIndex)
        {
            memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
        }
        else
        {
            memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
        }
    }

    byte* Vector::getBytePointer(const int index) const
    {
        DSRoutines::rangeCheckExcept(index, size_, "Out of range");
        return reinterpret_cast<byte*>(memory_) + index;
    }

}