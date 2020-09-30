#include <iostream>
#include <list>
#include <iterator>

using namespace std;

template <typename T>

void printList(list<T> r)
{
	if(r.empty())
	 cout << "list is empty";
	
	else 
	{
		ostream_iterator <T> k(cout , " ");
		copy(r.begin() , r.end() , k);
	}
	
	cout << endl;
}

int main()
{
	list < int > x;
	list < int > k;
	
	x.push_front(1);
	x.push_front(2);
	x.push_back(4);
	x.push_back(3);
	
	printList(x);//2 1 4 3
	
	x.sort();
	printList(x); // 1 2 3 4
	
	int a[] = {2,6,4,8}; // 2 6 4 8
	k.insert(k.begin() , a , a+4);
	
	printList(k);
	
	x.splice(x.end() , k);
	printList(x);  // 1 2 3 4 2 6 4 8
	printList(k); // list is empty
	
	x.sort();
	printList(x); //1 2 2 3 4 4 6 8
	
	k.insert(k.begin() , a , a+4);
	k.sort();
	printList(k); //2 4 6 8
	
	x.merge(k);
	printList(x);  // 1 2 2 2 3 4 4 6 6 8 8
	printList(k); // empty
	
	x.pop_back();
	x.pop_front();
	x.unique();
	printList(x); // 2 3 4 6 8
	
	x.swap(k);
	printList(x);  //empty
	printList(k);  //2 3 4 6 8
	
	
	
	
	
}
