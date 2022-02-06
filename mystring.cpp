#include "mystring.h"

String::String() : str_(nullptr), len_(0), cap_(0) {}

String::String(const char sym) : len_(1), cap_(2)
{
    str_ = new char[cap_];
    str_[0] = sym;
}

String::String(const char *str) : len_(strlen(str)),
    cap_(static_cast<unsigned long>(pow(2, ceil(log2(strlen(str))))))
{
    str_ = new char[cap_];
    strncpy(str_, str, len_);
}

String::String(unsigned long chars_count, const char sym) :
    len_(chars_count),
    cap_(static_cast<unsigned long>(pow(2, ceil(log2(chars_count)))))
{
    str_ = new char[cap_];
    for (unsigned long i = 0; i < chars_count; ++i)
        str_[i] = sym;
}

String::String(const String &other) : len_(other.len_),
    cap_(other.cap_)
{
    str_ = new char[cap_];
    strncpy(str_, other.str_, len_);
}

String& String::operator=(const String &other)
{
    if (this == &other)
    {
        return *this;
    }

    delete [] str_;
    len_ = other.len_;
    cap_ = other.cap_;
    str_ = new char[cap_];
    strncpy(str_, other.str_, len_);
    return *this;
}

String& String::operator+=(const String &other)
{
    if (other.len_ + len_ > cap_)
    {
        getmem(ceil(log2(other.len_ + len_)));
    }

    len_ += other.len_;
    strncat(str_, other.str_, other.len_);
    return *this;
}

const String operator+(const String &other, const String &other2)
{
    String tmp(other);
    return tmp += other2;
}

String& String::operator+=(const char sym)
{
    if (1 + len_ > cap_)
    {
        getmem(ceil(log2(1 + len_)));
    }
    ++len_;
    str_[len_-1] = sym;
    return *this;
}

const String operator+(const String &other, const char sym)
{
    String tmp(other);
    return tmp += sym;
}

const String String::substr(unsigned long start, long long count) const
{
    if (count == -1)
        return String(*this);
    String res;
    if (start + count >= len_)
        count = len_ - start;
    for (unsigned long i = start; i < start + count; ++i)
        res += str_[i];
    return res;
}

const char& String::operator[](unsigned long index) const
{
    return str_[index];
}

char& String::operator[](unsigned long index)
{
    return str_[index];
}

void String::clear()
{
    delete [] str_;
    len_ = 0;
    cap_ = 0;
}

void String::push_back(const char sym)
{
    *this += sym;
}

char String::pop_back()
{
    char res = str_[len_ - 1];
    --len_;
    if ((1 << static_cast<size_t>(ceil(log2(len_)))) != cap_)
        free_mem();
    return res;
}

unsigned long String::find(const String &dest) const
{
    if (dest.len_ > len_)
        return len_;
    unsigned long curr_ind = 0;
    for (unsigned long i = 0; i < len_ - dest.len_ + 1; ++i)
    {
        if (str_[i] == dest.str_[curr_ind])
        {
            if (curr_ind + 1 == dest.len_)
                return i - curr_ind;
            ++curr_ind;
        }
        else
        {
            curr_ind = 0;
        }
    }
    return len_;
}

unsigned long String::rfind(const String &dest) const
{
    if (dest.len_ > len_ || dest.len_ == 0)
        return len_;
    unsigned long curr_ind = dest.len_ - 1;
    for (unsigned long i = len_; i > 0; --i)
    {
        if (str_[i - 1] == dest.str_[curr_ind])
        {
            if (curr_ind == 0)
                return i - 1;
            --curr_ind;
        }
        else
        {
            curr_ind = dest.len_ - 1;
        }
    }
    return len_;
}

std::ostream& operator<< (std::ostream &fout, const String &string)
{
    for (unsigned long i = 0; i < string.len_; ++i)
        fout << string.str_[i];
    return fout;
}

std::istream& operator>> (std::istream &fin, String &string)
{
    string.clear();
    char tmp = fin.get();
    while (tmp != '\n')
    {
        string += tmp;
        tmp = fin.get();
    }
    return fin;
}

void String::free_mem()
{
    String tmp(*this);
    delete [] str_;
    cap_ /= 2;
    str_ = new char[cap_];
    strncpy(str_, tmp.str_, len_);
}

void String::getmem(size_t power)
{
    String tmp(*this);
    delete [] str_;
    cap_ = (1 << power);
    str_ = new char[cap_];
    strncpy(str_, tmp.str_, len_);
}
