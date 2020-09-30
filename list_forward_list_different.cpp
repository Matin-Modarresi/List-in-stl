#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

int main()
{
	list<int> x{1,2,3};
	list<int>::iterator itr1;

	forward_list<int> y{4,5,6,7};
    forward_list<int>::iterator itr2;
		
	cout << x.front() << "  ";// 1
	cout << y.front() << "\n";// 4
	
	cout << x.back() << "\n"; // 3
//	cout << y.back() << "\n";  error

    cout << x.size() << "  "; // 3
//  cout << y.size() << "  ";  error
 
   cout << "\n";
   
    x.insert(x.begin() ,13); // 13 1 2 3
    for(itr1=x.begin() ; itr1!=x.end() ; itr1++)
      cout << *itr1 << "  ";
      
      cout << "\n";
	
	y.insert_after(y.before_begin() , 13); // 13 4 5 6 7
	for(itr2=y.begin() ; itr2 != y.end() ; itr2++)
	cout << *itr2 << "  ";
 
    cout << "\n";
  
    x.erase(x.begin());
    for(itr1 = x.begin() ; itr1 != x.end() ; itr1++)
    cout << *itr1 << "  "; // 1 2 3
    
    cout << "\n";
    
    y.erase_after(y.before_begin());
    for(auto item:y)
    cout << item << " ";// 4 5 6 7
    
    
    
}
