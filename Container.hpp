#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

#include <cassert>
#include <memory>

template <typename T>
class Container
{
	static const int RESIZE_UP_FACTOR = 2;

	std::shared_ptr<T[]> elements;
	int size;
	int capacity;

public:
	Container(int capacity = 4);
	Container(const Container &other) = delete;

	void insert(const T &other);
	void remove(const T &other);
	void remove(int idx);
	T getElement(int idx);
	const T getElement(int idx) const;
	int getSize() const;
	bool isEmpty() const;
	int search(const T &other) const;
	bool contains(const T &other) const;
	bool operator==(const Container<T> &other) const;
	void clear();

	static const int INVALID_INDEX = -1;

private:
	void resizeUp();
};

template <typename T>
Container<T>::Container(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elements = std::shared_ptr<T[]>(new T[capacity]);
}

template <typename T>
T Container<T>::getElement(int idx)
{
	return this->elements[idx];
}

template <typename T>
const T Container<T>::getElement(int idx) const
{
	return this->elements[idx];
}

template <typename T>
void Container<T>::insert(const T &other)
{
	if (!contains(other))
	{
		if (capacity == size)
		{
			resizeUp();
		}
		elements[size] = other;
		size++;
	}
}

template <typename T>
void Container<T>::resizeUp()
{
	capacity *= RESIZE_UP_FACTOR;
	std::shared_ptr<T[]> tmp_elements = std::shared_ptr<T[]>(new T[capacity]);
	for (int i = 0; i < size; i++)
	{
		tmp_elements[i] = elements[i];
	}
	elements = tmp_elements;
}

template <typename T>
void Container<T>::remove(const T &other)
{
	int idx = search(other);
	remove(idx);
}

template <typename T>
void Container<T>::remove(int idx)
{
	assert(0 <= idx && idx < size);

	if (idx != INVALID_INDEX)
	{
		for (int i = idx; i < size - 1; i++)
		{
			elements[i] = elements[i + 1];
		}
		elements[size - 1] = T();
		size--;
	}
}

template <typename T>
int Container<T>::getSize() const
{
	return this->size;
}

template <typename T>
bool Container<T>::isEmpty() const
{
	return this->size == 0;
}

template <typename T>
int Container<T>::search(const T &other) const
{
	for (int i = 0; i < size; i++)
	{
		if (elements[i] == other)
		{
			return i;
		}
	}
	return INVALID_INDEX;
}

template <typename T>
bool Container<T>::contains(const T &other) const
{
	return search(other) != INVALID_INDEX;
}

template <typename T>
bool Container<T>::operator==(const Container<T> &other) const
{
	if (size == other.size)
	{
		for (int i = 0; i < size; i++)
		{
			bool found = false;
			int j = 0;
			while (j < other.size && found == false)
			{
				if (elements[i] == other.elements[j])
				{
					found = true;
				}
				j++;
			}
			if (found == false)
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

template <typename T>
void Container<T>::clear()
{
	// TODO implement this method
}

#endif
