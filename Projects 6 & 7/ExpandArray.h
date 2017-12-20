//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 7
//  May 11, 2016
//

#include <fstream>
#include <iostream>

using namespace std;

#ifndef IOOR_h
#define IOOR_h

class IOOR
{
    const char *_functionName;
    const int _index;
    const int _minIndex;
    const int _maxIndex;
    const char *_extraMessage;

public:

    IOOR(const char *functionName, const int index, const int minIndex, const int maxIndex, const char *extraMessage)
    : _functionName(functionName), _index(index), _minIndex(minIndex), _maxIndex(maxIndex), _extraMessage(extraMessage) {};

    friend ostream& operator<<(ostream &os, const IOOR &exception)
    {
        os << "Exception thrown in: " << exception._functionName << endl;

        if (exception._extraMessage)
        {
            os << exception._extraMessage << endl;
            return os;
        }

        if (exception._maxIndex < exception._minIndex)
            os << "No range exists." << endl;
        else
            os << "Index '" << exception._index << "' not in range (" << exception._minIndex << ", " << exception._maxIndex << ")." << endl;

        return os;
    }
};

#endif

#ifndef ExpandArray_h
#define ExpandArray_h

#define MIN_ARRAY_SIZE 10

template <class T>
class ExpandArray
{
    T *_array;
    float _percentage;
    int _startIndex;
    int _size;
    int _allocatedSize;

public:
    ExpandArray(int i = 0, float p = .5);
    // i is the index of the first element in your ExpandArray
    // p is the percentage that this ExpandArray will grow or shrink

    ExpandArray(const T*, unsigned s, int = 0, float p = .5);
    // i is the index of the first element in your ExpandArray
    // p is the percentage that this ExpandArray will grow or shrink
    // s is the number of items pointed to by T*

    ExpandArray(const ExpandArray&);

    ~ExpandArray();

    ExpandArray& operator=(const ExpandArray&);

    // Insert the array or a pointer to an array into an out stream
    template <class T2>
    friend ostream& operator<<(ostream&, const ExpandArray<T2> &);

    template <class T2>
    friend ostream& operator<<(ostream&, const ExpandArray<T2> *);

    // access the item at index 0 <= i < size (assuming standard indexing)
    T& operator[](int i);
    const T& operator[](int i) const;

    // Returns a sub array beginning at index first and going to index last-1
    ExpandArray operator()(int first, int last) const;

    // Append either a new item or another ExpandArray beginning at index size
    void append(const T&);
    void append(const ExpandArray&);

    // return the number of items in the array
    unsigned size() const;

    // Remove the item at index 0 <= i < size (assuming standard indexing)
    void remove(int i);

    // Remove the items from index first through index last-1
    void remove(int first, int last);

    // Remove the item at index size-1 (assuming standard indexing)
    void remove();

    // Insert at index 0 <= i < size (assuming standard indexing)
    void insert(int i, const T&);

    // Insert at index 0 (assuming standard indexing)
    void insert(const T&);

    void write(const char *filename) const;
    void read(const char *filename);
};

#endif

template <class T>
ExpandArray<T>::ExpandArray(int i, float p)
:_startIndex(i), _size(0), _allocatedSize(0)
{
    if (p < 0.25) p = 0.25;
    if (p > 1) p = 1;
    _percentage = p;
}

template <class T>
ExpandArray<T>::ExpandArray(const T *t, unsigned s, int i, float p)
:_startIndex(i), _size(0), _allocatedSize(0)
{
    if (p < 0.25) p = 0.25;
    if (p > 1) p = 1;
    _percentage = p;

    for (int j = 0; j < s; j++)
        append(*(t++));
}

template <class T>
ExpandArray<T>::ExpandArray(const ExpandArray<T> &array)
:_percentage(0), _startIndex(0), _size(0), _allocatedSize(0)
{
    *this = array;
}

template <class T>
ExpandArray<T>::~ExpandArray()
{
    if (_allocatedSize != 0)
        delete [] _array;
}

template <class T>
ExpandArray<T>& ExpandArray<T>::operator=(const ExpandArray &array)
{
    if (this == &array) return *this;

    _percentage = array._percentage;
    _startIndex = array._startIndex;

    if (_allocatedSize != 0)
        delete [] _array;

    _size = 0;
    _allocatedSize = 0;

    for (int i = 0; i < array._size; i++)
        (*this).append(array._array[i]);

    return *this;
}

template <class T>
ostream& operator<<(ostream &os, const ExpandArray<T> &array)
{
    for (int i = array._startIndex; i < array._size + array._startIndex; i++)
    {
        os << array[i] << ((i == array._size + array._startIndex - 1) ? "\n" : ", ");
    }

    os << "Size: " << array._size << endl;
    os << "Allocated Size: " << array._allocatedSize << endl;
    os << "Growth Percentage: " << array._percentage * 100 << "%" << endl;
    os << "Start Index: " << array._startIndex << endl;

    return os;
}

template <class T>
ostream& operator<<(ostream &os, const ExpandArray<T> *array)
{
    os << *array;
    return os;
}

template <class T>
T& ExpandArray<T>::operator[](int i)
{
    int index = i - _startIndex;

    if (index < 0 || index >= _size)
        throw IOOR("operator[](int)", i, _startIndex, _startIndex + _size - 1, NULL);

    return _array[index];
}

template <class T>
const T& ExpandArray<T>::operator[](int i) const
{
    int index = i - _startIndex;

    if (index < 0 || index >= _size)
        throw IOOR("operator[](int) const", i, _startIndex, _startIndex + _size - 1, NULL);

    return _array[index];
}

template <class T>
ExpandArray<T> ExpandArray<T>::operator()(int first, int last) const
{
    int indexFirst = first - _startIndex;
    int indexLast = last - _startIndex;

    if (indexFirst < 0 || indexFirst > _size)
        throw IOOR("operator(int, int)", first, _startIndex, _startIndex + _size, NULL);

    if (indexLast < 0 || indexLast > _size)
        throw IOOR("operator(int, int)", last, _startIndex, _startIndex + _size, NULL);

    if (indexLast < indexFirst)
        throw IOOR("operator(int, int)", 0, 0, 0, "'first' index is larger than 'last' index.");

    if (indexFirst == indexLast)
        throw IOOR("operator(int, int)", 0, 0, 0, "Range cannot be of size zero.");

    ExpandArray<T> temp(_startIndex, _percentage);

    for (int i = indexFirst; i < indexLast; i++)
        temp.append(_array[i]);

    return temp;
}

template <class T>
void ExpandArray<T>::append(const T &t)
{
    if (_allocatedSize == 0)
    {
        _array = new T[MIN_ARRAY_SIZE];
        _allocatedSize = MIN_ARRAY_SIZE;
    }

    if (_size >= _allocatedSize)
    {
        _allocatedSize += _allocatedSize * _percentage;
        T *temp = new T[_allocatedSize];
        for (int i = 0; i < _size; i++)
            temp[i] = _array[i];

        if (_array != NULL)
            delete [] _array;

        _array = new T[_allocatedSize];
        for (int i = 0; i < _size; i++)
            _array[i] = temp[i];

        if (temp != NULL)
            delete [] temp;
    }

    _array[_size++] = t;
}

template <class T>
void ExpandArray<T>::append(const ExpandArray &array)
{
    for (int i = array._startIndex; i < array._size + array._startIndex; i++)
        (*this).append(array[i]);
}

template <class T>
unsigned ExpandArray<T>::size() const
{
    return _size;
}

template <class T>
void ExpandArray<T>::remove(int i)
{
    int index = i - _startIndex;

    if (index < 0 || index >= _size)
        throw IOOR("remove(int)", i, _startIndex, _startIndex + _size - 1, NULL);

    ExpandArray<T> temp(_startIndex, _percentage);

    for (int i = 0; i < _size; i++)
    {
        if (i != index)
            temp.append(_array[i]);
    }

    *this = temp;
}

template <class T>
void ExpandArray<T>::remove(int first, int last)
{
    int indexFirst = first - _startIndex;
    int indexLast = last - _startIndex;

    if (indexFirst < 0 || indexFirst > _size)
        throw IOOR("remove(int, int)", first, _startIndex, _startIndex + _size, NULL);

    if (indexLast < 0 || indexLast > _size)
        throw IOOR("remove(int, int)", last, _startIndex, _startIndex + _size, NULL);

    if (indexLast < indexFirst)
        throw IOOR("remove(int, int)", 0, 0, 0, "'first' index is larger than 'last' index.");

    if (indexFirst == indexLast)
        throw IOOR("remove(int, int)", 0, 0, 0, "Range cannot be of size zero.");

    ExpandArray<T> temp(_startIndex, _percentage);

    for (int i = 0; i < _size; i++)
    {
        if (!(i >= indexFirst) || !(i < indexLast))
            temp.append(_array[i]);
    }

    *this = temp;
}

template <class T>
void ExpandArray<T>::remove()
{
    if (_size == 0)
        throw IOOR("remove()", 0, 0, 0, "Array is empty. Cannot remove anymore objects.");

    (*this).remove(_size + _startIndex - 1);
}

template <class T>
void ExpandArray<T>::insert(int i, const T &t)
{
    int index = i - _startIndex;

    if (index < 0 || index > _size)
        throw IOOR("insert(int, T)", i, _startIndex, _startIndex + _size, NULL);

    ExpandArray<T> temp(_startIndex, _percentage);

    for (int i = 0; i < _size; i++)
    {
        if (i == index)
            temp.append(t);

        temp.append(_array[i]);
    }

    if (index == _size)
        temp.append(t);

    *this = temp;
}

template <class T>
void ExpandArray<T>::insert(const T &t)
{
    insert(_startIndex, t);
}

template <class T>
void ExpandArray<T>::write(const char *filename) const
{
    ofstream file(filename, ios::out | ios::binary);

    if (!file)
    {
        cout << "Write file: " << filename << " does not open." << endl;
        return;
    }

    file.write(reinterpret_cast<const char *>(&_percentage), sizeof(float));
    file.write(reinterpret_cast<const char *>(&_startIndex), sizeof(int));
    file.write(reinterpret_cast<const char *>(&_size), sizeof(int));
    file.write(reinterpret_cast<const char *>(_array), sizeof(T) * _size);
    file.close();
}

template <class T>
void ExpandArray<T>::read(const char *filename)
{
    float percentage = 0;
    int startIndex = 0;
    int size = 0;

    ifstream file(filename, ios::in | ios::binary);

    if (!file)
    {
        cout << "Read file: " << filename << " does not open." << endl;
        return;
    }

    file.read(reinterpret_cast<char *>(&percentage), sizeof(float));
    file.read(reinterpret_cast<char *>(&startIndex), sizeof(int));
    file.read(reinterpret_cast<char *>(&size), sizeof(int));

    T *array = new T[size];
    file.read(reinterpret_cast<char *>(array), sizeof(T) * size);

    file.close();
    
    *this = ExpandArray<T>(array, size, startIndex, percentage);

    delete [] array;
}
