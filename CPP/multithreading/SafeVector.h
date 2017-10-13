#pragma once
#include <vector>
#include <mutex>
#include <initializer_list>
 
template <class T>
class SafeVector
{
private:
    std::vector<T> m_safeVector;
    std::mutex m_mutex;
 
public:
    SafeVector() = default;
    SafeVector(std::initializer_list<T> list);
    void PushBack(T& const element);
    T PopBack();
    T operator[](unsigned int index);
};
 
template <class T>
SafeVector<T>::SafeVector(std::initializer_list<T> list):
    m_safeVector(list)
{
}
 
template <class T>
void SafeVector<T>::PushBack(T& const element)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_safeVector.push_back(element);   
}
 
template <class T>
T SafeVector<T>::PopBack()
{
    std::unique_lock<std::mutex> lock(m_mutex);
       
    if (m_safeVector.empty())
    {
        throw std::exception("Out of range");      
    }
    T result = m_safeVector[m_safeVector.size() - 1];
    m_safeVector.pop_back();
   
    return result;
}
 
template <class T>
T SafeVector<T>::operator[](unsigned int index)
{
    std::unique_lock<std::mutex> lock(m_mutex);
 
    if (m_safeVector.size() <= index)
    {
        throw std::exception("Out of range");
    }
 
    return m_safeVector[index];
}
