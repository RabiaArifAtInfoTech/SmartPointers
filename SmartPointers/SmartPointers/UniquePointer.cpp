#include <iostream>
using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b) {
		length = l;
		breadth = b;
		cout << "\Constructor of Unique pointer is called\n";
	}

	~Rectangle() {
		cout << "\nDestructor of Unique pointer is called\n";
	}
	int area() {
		return length * breadth;
	}
	void move(Rectangle&& ){
		cout << "\n Move Constructor called of Unique pointer\n";
	}
};

int main() {

	unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << P1->area() << endl; // This'll print 50

	
	//unique_ptr<Rectangle> P2(P1); // error: cannot be reffered -- it is a deleted function
	
	unique_ptr<Rectangle> P2;

	//P2 = P1;  // error: cannot be reffered -- it is a deleted function

	P2 = std::move(P1);

	// This'll print 50
	cout << P2->area() << endl;

	// cout<<P1->area()<<endl;
	return 0;
}
