#include <iostream>
#include <cstring>
using namespace std;
template<typename T = string, const int MAX_COPIES = 5>
class LibraryItem
{
	string title;
	T* copies;
	static int totalItems;
	int currentTotalItems;
public:
	LibraryItem (string booktitle)
	{
		title = booktitle;
		currentTotalItems = 0;
		for (int i = 0; i < MAX_COPIES; i++)
		{
			copies[i] = T();
		}
		totalItems++;
	}
	~LibraryItem()
	{
		totalItems--;
	}
	void addCopy(T id)
	{
		if (currentTotalItems >= MAX_COPIES)
		{
			cout << "The book limit has been reached...";
		}
		T* temp = new T[currentCopiesCount + 1];
		for (int i = 0; i < currentCopiesCount; i++) 
		{
			temp[i] = copies[i];
		}
		temp[currentCopiesCount] = id;
		copies[currentCopiesCount] = id;
		currentCopiesCount++;
		return true;
	}
	void removeCopy(T id)
	{
		int indexRemowe = -1;
		for (int i = 0; i < currentCopiesCount; i++)
		{
			if (copies[i] == id)
			{
				indexRemowe = i;
				break;
			}
		}
		if (indexRemowe == -1)
		{
			return false;
		}
		if (currentTotalItems <= 1)
		{
			delete[]copies;
			copies = nullptr;
			currentCopiesCount = 0;
			return true;
		}
		T* temp = new T[currentTotalItems - 1];
		int k = 0;
		for (int i = 0; i < currentCopiesCount; i++)
		{
			if (i == indexRemowe)
			{
				continue;
			}
			temp[k] = copies[i];
			k++;
		}
		delete[] copies;
		copies = temp;
		currentTotalItems--;
		return true;
	}
	int getCopiesCount()
	{
		return currentTotalItems;
	}
	string getTitle() const
	{
		return title;
	}
	static int getTotalItems()
	{
		return totalItems;
	}
	template<typename T, int MAX_COPIES>
	int LibraryItem<T, MAX_COPIES>::totalItems = 0;
};
int main()
{
	LibraryItem<int, 3> book1("C++ Guide");
	book1.addCopy(101);
	book1.addCopy(102);

	cout << "Copies: " << book1.getCopiesCount() << endl;
	book1.removeCopy(101);
	cout << "Copies after remove: " << book1.getCopiesCount() << endl;
	cout << "Total books created: " << LibraryItem<int>::getTotalItems() << endl;
}