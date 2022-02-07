#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring>
#include <cmath>

class String
{
public:
    String();
    String(const char);
    String(const char*);
    String(unsigned long chars_count, const char);
    String(const String &);
    ~String() { delete [] str_; }

    String& operator=(const String&);
    String& operator+=(const String&);
    String& operator+=(const char);
    String& operator*=(const size_t);

    const String substr(unsigned long start, long long count = -1) const;

    const char& operator[](unsigned long index) const;
    char& operator[](unsigned long index);

    void clear();
    void push_back(const char);
    char pop_back();

    bool empty() const { return (len_ == 0 ? true : false); }

    char& front() { return str_[0]; }
    char& back() { return str_[len_ - 1]; }

    unsigned long find(const String&) const;
    unsigned long rfind(const String&) const;
    unsigned long length() const { return len_; }
    unsigned long capacity() const { return cap_; }

    friend std::ostream& operator<< (std::ostream &, const String &);
    friend std::istream& operator>> (std::istream &, String &);

private:
    char *str_;
    unsigned long len_;
    unsigned long cap_;

    void free_mem();
    void getmem(size_t power);
};

const String operator+(const String&, const String&);
const String operator+(const String&, const char);
const String operator*(const String&, const size_t);

#endif // MYSTRING_H
