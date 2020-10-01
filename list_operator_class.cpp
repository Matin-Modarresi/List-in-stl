#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class c{
	friend ostream &operator << (ostream & , const c&);
	
	public:
		int x;
		int y;
		 
		c();
		c( c&);
		~c(){};
		
		c&    operator = (const c &);
		int  operator == (const c &) const;
		int  operator < (const c &) const;
		
};

c::c(){
	
	x=0;
	y=0;
}

 c::c( c &copyin)
{
	x=copyin.x;
	y=copyin.y;
}

ostream &operator<<(ostream &o ,const c &c)
{
	o << c.x << ' ' << c.y;
	
	return o;
}

c& c::operator=(const c &k)
{
	this -> x = k.x;
	this -> y = k.y;
	
	return *this;
}


int c::operator==(const c &k ) const
{
	if(this->x == k.x)
	 return 0;
	 
	 else return 0;
}

int c::operator < (const c &k) const
{
	if(this->x == k.x && this->y == k.y)
	 return 1;
	 
	 if (this->x==k.x && this->y < k.y)
	 return 1;
	 
	 if(this->x < k.x)
	 return 1;
	 
	 return 0;
	 
}


int main()
{
   list<c> L;
   
   c t;
   
   t.x=1;   
   t.y=2;  
   L.push_back(t); //  1 2
   
   
   t.x=3;
   L.push_back(t);  // 1 2 -> 3 2
   
   t.y=4;
   L.push_back(t); // 1 2 -> 3 2 -> 3 4
   
   t.x=2;
   t.y=7;
   L.push_back(t); // 1 2 -> 3 2 -> 3 4 -> 2 7   
   
   list<c>::iterator i;
   
   cout << "List: " << endl;	
   
   for(i=L.begin() ; i!=L.end() ; i++)
     cout << (*i).x << " " << (*i).y << endl;
	 
	 cout << "\n\n";
	 
	 cout << "Sorted: \n";
	 L.sort();
	 for(i=L.begin() ; i !=L.end() ; i++)
	 cout << *i;
	 
	 cout << "\n";
	 
	 for(i=L.begin(); i!=L.end() ; i++)
	   if((*i).x == 2)
	   i = L.erase(i);
	     
	     else i++;
	     
	cout << "delete: " << endl;
	for(i=L.begin() ; i!=L.end() ; i++)
	 cout << *i;
	 
	cout << endl;
	
	cout << "Show Reverse: " << endl;
	list<c>::reverse_iterator ri;
	for(ri=L.begin() ; ri!=L.rend() ; ri++)
	  cout << *ri ;
	  
	  cout << endl;
	 
	  
}
