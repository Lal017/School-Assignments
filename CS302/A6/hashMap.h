#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

template <class t1, class t2>
class hashMap
{
public:
	hashMap(std::size_t = 5);
	t2& operator[](t1);
private:
	struct keyVal
	{
		keyVal()
		{
			key = t1();
			value = t2();
		}

		t1 key;
		t2 value;
	};

	void resize(std::size_t);

	std::size_t hash1(std::string);
	std::size_t hash2(std::string);

	std::vector<keyVal> table1;
	std::vector<keyVal> table2;

	std::size_t items1;
	std::size_t items2;
};

template <class t1, class t2>
hashMap<t1, t2>::hashMap(std::size_t size)
{
	items1 = 0;
	items2 = 0;

	table1.resize(size);
	table2.resize(size);
}

template <class t1, class t2>
t2& hashMap<t1, t2>::operator[](t1 key)
{
	int i1 = 0, i2 = 0;														// collision counters
	float load_factor1, load_factor2;										// used to calculate load factors
	double vector_size;

	vector_size = table1.size();
	load_factor1 = items1 / vector_size;									// load factor for table 1
	vector_size = table2.size();
	load_factor2 = items2 / vector_size;									// load factor for table 2

	if(load_factor1 >= 0.2 || load_factor2 >= 0.2)
	{
		this->resize(table1.size());
		this->resize(table2.size());
	}

	std::size_t index1 = hash1(key) % table1.size();
	std::size_t index2 = hash2(key) % table2.size();

	int iteration = 1;														// iteration counter

	while(1)
	{
		if(table1[index1].key == t1())										// if key is empty
		{
			table1[index1].key = key;
			items1++;
			return table1[index1].value;
		}
		else if(table1[index1].key == key)									// if key is found
			return table1[index1].value;

		if(table2[index2].key == t1())
		{
			table2[index2].key = key;
			items2++;
			return table2[index2].value;
		}
		else if(table2[index2].key == key)
			return table2[index2].value;

		i1++;																// increment collision counter
		i2++;

		if(iteration % 2 == 0)												// even iterations
		{
			index1 = (index1 + i1 * hash2(key)) % table1.size();			// get new index if collision occured
			index2 = (index2 + i2 * hash1(key)) % table2.size();
		}
		else																// odd iterations
		{
			index1 = (index1 + i1 * hash1(key)) % table1.size();
			index2 = (index2 + i2 * hash2(key)) % table2.size();
		}
		iteration++;
	}
}

template <class t1, class t2>
void hashMap<t1, t2>::resize(std::size_t amount)
{
	std::vector<keyVal> temp1(table1);												// copy tables into temp vectors
	std::vector<keyVal> temp2(table2);

	table1.clear();
	table2.clear();

	for(int i = 0; i < amount + temp1.size(); i++)									// increase size of tables
	{
		table1.push_back(keyVal());
		table2.push_back(keyVal());
	}

	for(int i = 0; i < temp1.size(); i++)											// rehashes back into table1 and table2
	{
		if(temp1[i].key != t1())
		{
			std::size_t index1 = hash1(temp1[i].key) % table1.size();
			std::size_t index2 = hash2(temp2[i].key) % table2.size();

			int iteration = 1;														// iteration counter
			int i1 = 0, i2 = 0;														// collision counters

			while(1)
			{
				if(table1[index1].key == t1())
				{
					table1[index1].key = temp1[i].key;
					table1[index1].value = temp1[i].value;
					break;
				}
				else if(table2[index2].key == t1())
				{
					table2[index2].key = temp2[i].key;
					table2[index2].value = temp2[i].value;
					break;
				}

				i1++;
				i2++;

				if(iteration % 2 == 0)
				{
					index1 = (index1 + i1 * hash2(temp1[i].key)) % table1.size();
					index2 = (index2 + i2 * hash1(temp2[i].key)) % table2.size();
				}
				else
				{
					index1 = (index1 + i1 * hash1(temp1[i].key)) % table1.size();
					index2 = (index2 + i2 * hash2(temp2[i].key)) % table2.size();
				}
				iteration++;
			}
		}
	}
}

template <class t1, class t2>
std::size_t hashMap<t1, t2>::hash1(std::string key)
{
	std::size_t ret = 0;
	for(int i = 0; i < key.length(); i++)
		ret += key[i] * pow(10,i);

	return ret;
}

template <class t1, class t2>
std::size_t hashMap<t1, t2>::hash2(std::string key)
{
	std::size_t ret = 0;
	for(int i = 0; i < key.length(); i++)
		ret += key[key.length()-1-i] * pow(10,i);

	return ret;
}
