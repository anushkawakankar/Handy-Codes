#include <iostream> 
using namespace std; 
class Base {
	 public: Base() 
	 { 
		 cout<<"Base constructor is called"<<"\n"; 
		} 
	virtual ~Base() { 
		cout<<"Base class object is destroyed"<<"\n"; 
		} 
	}; 
class Derived:public Base { 
		public: Derived() { 
			cout<<"Derived class constructor is called"<<"\n";
			} 
		~Derived() { 
			cout<<"Derived class object is destroyed"<<"\n"; 
			} 
			}; 
			
			int main() { Base* b= new Derived; delete b; return 0; } 


int main() { 
	int x = 3; int y = 7; 
	if (y > 1 && y < x) 
	printf("y is greater than 1 AND y\n"); 
	else printf("y is greater than 1 but smaller than x\n"); 
	int z = x & y; 
	printf ("z = %d", z); return 0; } 
y is greater than 1 but smaller than x
z = 3

HelloHello

for(int i = 0; i<10; i++)