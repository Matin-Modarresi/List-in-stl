#include <iostream>
#include<bits/stdc++.h>
#include <list>
using namespace std;

void display(list<int>x , list<int>y)
{ 
  for(auto item:x)
   cout << item << " ";
   
   cout << "\n";
   
   for(auto item:y)
   cout << item << " ";
   
   cout<<"\n";
}

int main()
{
	list<int>x{1,2,3,4,5};
	list<int>y{7,8,9};
	
	auto itr = x.begin();
        itr++; // *itr == 2
	
	x.splice(itr , y); // x = 1 7 8 9 2 3 4 5	
	display(x,y);     // y = NULL
	 
	 cout << "\n";
	 
	y.splice(y.begin() , x , itr); // x = 1 7 8 9 3 4 5	 
	display(x,y);                 // y = 2
	
	cout << *itr << "\n"; //2
	
	itr = x.begin(); // *itr = 1
	
	advance(itr,3); // *itr = 9
	
	x.splice(x.begin() , x , itr , x.end()); // x = 9 3 4 5 1 7 8
	display(x,y);                            // y = 2
	

	 	

}
