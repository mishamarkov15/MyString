# MyString
Реализация класса **string**.

## Конструкторы
1. String () - создаёт _пустую_ строку.
2. String (const char sym) - создаёт строку _из символа sym_.
3. String (const char *) - создаёт строку _из массива char_.
4. String (unsigned long n, const char sym) - создаёт строку из _n символов sym_.
5. String (const String &other) - _конструктор копирования_. Создаёт строку _из строки other_.

## Перегруженные бинарные операторы
1. String& operator= (const String &) - оператор присваивания.
2. String& operator+= (const String &) - оператор скоращённого сложения со строкой.
3. const String operator+ (const String &a, const String &b) - оператор сложения.
4. String& operator+= (const char sym) - оператор сокращённого сложения с символом.
5. const String operator+ (const String &, const char) - оператор сложения с символом.
6. std::ostream& operator<< (std::ostream &, const String &) - вывод в поток.
7. std::istream& operator>> (std::istream &, String &) - ввод из потока.

## 
