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

	Array operator+(Array& array)
	{

	}

	Array operator==(Array& array)
	{

	}

	void operator+=(int element)
	{

	}

	void operator-(int element)
	{

	}

	void operator=(Array& array)
	{

	}

	int operator[](int i)
	{

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

int main()
{
	Array arr1;

	std::cin >> arr1;

	arr1.print();
	
	std::cout << arr1.search(5) << '\n';

	arr1.sort();

	std::cout << arr1 << '\n';

	std::cout << arr1.search(6) << '\n';

	system("pause");
	return 0;
}