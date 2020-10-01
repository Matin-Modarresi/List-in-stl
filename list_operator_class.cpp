// class
#include <iostream>
#include <list>
using namespace std;
///////////////////////////////////////////////////////////////////////
class c
{
   friend ostream &operator<<(ostream &, const c &);

   public:
      int x;
      int y;

      c();
      c(const c &);
      ~c(){};
      
      c &operator=(const c &rhs);
      int operator==(const c &rhs) const;
      int operator<(const c &rhs) const;
};
/////////////////////////////////////////////////////////
c::c()   // Constructor
{
   x = 0;
   y = 0;
}
/////////////////////////////////////////////////////////
c::c(const c &copyin)   // Copy constructor to handle pass by value.
{                             
   x = copyin.x;
   y = copyin.y;
}
/////////////////////////////////////////////////////////
ostream &operator<<(ostream &o, const c &c)
{
   o << c.x << ' ' << c.y <<  endl;
   return o;
}
/////////////////////////////////////////////////////////
c& c::operator=(const c &k)
{
   this->x = k.x;
   this->y = k.y;
   return *this;
}
/////////////////////////////////////////////////////////
int c::operator==(const c &k) const
{
   if( this->x != k.x) 
       return 0;
   if( this->y != k.y) 
       return 0;
       
   return 1;
}
/////////////////////////////////////////////////////////
// This function is required for built-in STL list functions like sort
int c::operator<(const c &k) const
{
   if( this->x == k.x && this->y == k.y) 
         return 1;
         
   if( this->x == k.x && this->y < k.y) 
         return 1;
         
   if( this->x < k.x ) 
         return 1;
         
   return 0;
}
/////////////////////////////////////////////////////////

main()
{
   list<c> L;
   c t ;

   t.x=1;
   t.y=2;
   L.push_back(t);  // 1  2 

   t.x=3;
   L.push_back(t);   //  1  2  ->  3  2  
   
   t.y=4;
   L.push_back(t);   //  1  2  ->  3  2  ->  3  4

   t.x=2;
   t.y=7;
   L.push_back(t);   //  1  2  ->  3  2  ->  3  4 -> 2  7
   
   list<c>::iterator i;
///
   cout << "List: "<<endl ;
   for(i=L.begin(); i != L.end(); ++i) 
   		cout <<(*i).x <<" "<< (*i).y << endl; 
   		
   cout << endl << endl;      
////
   cout << "Sorted: " << endl;
   L.sort();
   for(i=L.begin(); i != L.end(); ++i) 
            cout << *i; 
   cout << endl;
////
   for(i=L.begin(); i != L.end(); )       
       if( (*i).x == 2 ) 
	         i = L.erase(i);       
       else i++; 
   cout << "delete: " << endl;
   for(i=L.begin(); i != L.end(); ++i) 
         cout << *i; 
   cout << endl;
 ////  	         
   cout << "Show Reverse: " << endl;
   list<c>::reverse_iterator ri;
   for(ri=L.rbegin(); ri != L.rend(); ++ri) 
              cout << *ri;                 
   cout << endl;   
			                          
   

}

          
