#include <iostream>

class Array
{
private:
	int m_size;
	int* m_array;

public:
	Array(int size = 5) : m_size(size), m_array(new int[m_size]) {}

	Array(Array& array) : m_size(array.m_size), m_array(new int[m_size]) //переписати
	{
		for (int i = 0; i < array.m_size; i++)
		{
			array.m_array[i] = this->m_array[i];
		}
	}

	void sort()
	{
		int i, j, step;
		int tmp;
		for (step = m_size / 2; step > 0; step /= 2)
		{
			for (i = step; i < m_size; i++)
			{
				tmp = m_array[i];
				for (j = i; j >= step; j -= step)
				{
					if (tmp < m_array[j - step])
						m_array[j] = m_array[j - step];
					else
						break;
				}
				m_array[j] = tmp;
			}
		}
		
	}

	int search(int element)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_array[i] == element)
			{
				return i;
			}
			else if (i == m_size - 1)
			{
				return -1;
			}
			else
			{
				continue;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < m_size; i++)
		{
			std::cout << m_array[i] << ' ';
		}

		std::cout << '\n';
	}

	void push()
	{
		for (int i = 0; i < m_size; i++)
		{
			std::cout << "Enter " << i + 1 << " element: ";
			std::cin >> m_array[i];
		}
	}

	friend Array operator+(Array& array, Array& array1);

	Array operator==(Array& array)
	{

	}

	void operator+=(int element)
	{

	}

	void operator-(int element)
	{

	}

	int operator[](int i)
	{
		return 1;
	}


	friend std::ostream& operator<<(std::ostream& os, Array& array);
	friend std::istream& operator>>(std::istream& is, Array& array);

	~Array()
	{
		delete[] m_array;
	}
};

std::ostream& operator<<(std::ostream& os, Array& array)
{
	for (int i = 0; i < array.m_size; i++)
	{
		os << array.m_array[i] << " ";
	}

	return os;
}

std::istream& operator>>(std::istream& is, Array& array)
{
	for (int i = 0; i < array.m_size; i++)
	{
		std::cout << "Enter " << i + 1 << " element: ";
		is >> array.m_array[i];
	}

	return is;
}

Array operator+(Array& array, Array& array1)
{
	int* t_array = new int[array.m_size];

	for (int i = 0; i < array.m_size; i++)
	{
		t_array[i] = array.m_array[i];
	}

	array.m_array = new int[array.m_size + array1.m_size];

	for (int i = 0; i < array.m_size; i++)
	{
		array.m_array[i] = t_array[i];
	}

	for (int i = array.m_size, j = 0; i < (array.m_size + array1.m_size); i++, j++)
	{
		array.m_array[i] = array1.m_array[j];
	}

	return array;
}

int main()
{
	Array arr1;

	std::cin >> arr1;

	arr1.print();
	
	std::cout << arr1.search(5) << '\n';

	arr1.sort();

	std::cout << arr1 << '\n';

	std::cout << arr1.search(6) << '\n';

	Array arr2(7);
	std::cin >> arr2;

	std::cout << arr2 << '\n';

	Array arr3;

	arr3 = arr1 + arr2;

	std::cout << arr3;

	system("pause");
	return 0;
}