#pragma once
template <typename T>
class IsLower
{
public:

	IsLower(T limit);
	~IsLower();
	inline bool operator()(T compare) const;

private:
	T mLimit;
};

template <typename T>
IsLower<T>::IsLower(T limit) : mLimit(limit)
{
}

template <typename T>
IsLower<T>::~IsLower()
{
}

template <typename T>
inline bool IsLower<T>::operator()(T compare) const
{
	return compare < mLimit;
}
