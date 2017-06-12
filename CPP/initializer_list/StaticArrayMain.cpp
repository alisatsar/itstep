template<class T, int N>
class Vector
{
  T m_data[N];
public:
  Vector(std::initializer_list<T> const& list)
  {
    std::initializer_list<T>::iterator it = list.begin();
    T* ptr = m_data;
    int i = 0;
    for(; it != list.end() & i < N; ++it)
    {
      m_data[i] = *it;
    }
};
