#pragma once
template <typename T>
class IsBetween
{
public:

	IsBetween(T lower, T upper);
	~IsBetween();
	inline bool operator()(T compare) const;

private:
	T mLower;
	T mUpper;
};

template <typename T>
IsBetween<T>::IsBetween(T lower, T upper) : mLower(lower), mUpper(upper)
{
}

template <typename T>
IsBetween<T>::~IsBetween()
{
}

template <typename T>
inline bool IsBetween<T>::operator()(T compare) const
{
	if (compare >= mLower && compare <= mUpper) return true;
	else return false;
}
