#include <iostream>

class Array
{
private:
	int m_size;
	int* m_array;

public:
	Array(int size = 5) : m_size(size), m_array(new int[m_size]) {}

	Array(Array& array) : m_size(array.m_size), m_array(new int[m_size]) {}
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

	}

	void print()
	{

	}

	void push()
	{
		for (int i = 0; i < m_size; i++)
		{
			std::cout << "Enter " << i + 1 << "element:";
			std::cin >> m_array[i];
			std::cout << '\n';
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

}

std::istream& operator>>(std::istream& is, Array& array)
{
	
}

int main()
{

	system("pause");
	return 0;
}