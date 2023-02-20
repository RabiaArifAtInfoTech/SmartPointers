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
		cout << "\nConstructor of Rectangle is called"<< endl;
	}

	~Rectangle() {
		cout << "\nDestructor of Rectangle is called\n";
	}
	int area() {
		return length * breadth;
	}
	//copy constructor
	Rectangle(const Rectangle& pt)
	{
		cout << "\nin Rectangle copy  constructor";
	}
	//move constructor
	Rectangle(Rectangle&& pt)
	{
		cout << "\nin Rectangle Move constructor";
	}
	
	Rectangle& operator*() {
		cout << "\nin \"*\" operator ";

	}
	Rectangle& operator=(Rectangle pt) {
		cout << "\nin \"=\" operator ";

		return pt;
	}
	/*friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect)
	{
		return os << "{ x=" << rect.length << ", y=" << rect.breadth << " }";
	}*/
	
};

int main() {

	unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	cout << "\nP1 area: " << P1->area() << endl; // This'll print 50
	cout << "\nP1.get(): " << P1.get() << endl;
	
	//unique_ptr<Rectangle> P2(P1); // error: cannot be reffered -- it is a deleted function
	
	unique_ptr<Rectangle> P2;
	cout << "\nP2.get(): " << P2.get() << endl;
	//cout << "\nP2 area: " << P2->area() << endl;

	//P2 = P1;  // error: cannot be reffered -- it is a deleted function

	P2 = std::move(P1);

	// This'll print 50
	cout << "\nP2 area: " << P2->area() << endl;
	cout << "\nP1.get(): " << P1.get() << endl;
	cout << "\nP2.get(): " << P2.get() << endl;
	cout << "\nP1.get(): " << P1.get() << endl;
	//cout <<  "\nP1 area: " << P1->area() << endl; //error ....solution: shared pointer



	Rectangle rect123(11, 11);
	//cout << rect123->area() << endl;

	Rectangle rect13(117, 11);
	//cout << P2->area() << endl;
	/*for (int i = 0; i < 1 ; i++)
	{
		cout << "\nP1.get() inside loop: " << P1.get() << endl;
	}*/
	unique_ptr<Rectangle> unique_Rect1 = std::make_unique<Rectangle>(rect123); //goes to copy constructor
	cout << "\nunique_Rect1.get(): " << unique_Rect1.get() << endl;

	unique_ptr<Rectangle> unique_Rect2; //goes to copy constructor

	//unique_ptr<Rectangle> unique_Rect2 = std::make_unique<Rectangle>(rect13); //goes to copy constructor
	unique_Rect2 = std::move(unique_Rect1);

	cout << "\nunique_Rect2.get(): " << unique_Rect2.get() << endl;
	cout << "\nunique_Rect1.get(): " << unique_Rect1.get() << endl;

	 //cout<<P1->area()<<endl;



	//................Shared Pointer....................//

	cout << "\n\n\n\n.....Shared Pointer.........\n\n";
	Rectangle rectShared1(11, 11);
	Rectangle rectShared2(10, 10);
	
	std::shared_ptr<Rectangle> sharedRectPointer = std::make_shared<Rectangle>(rectShared1);

	cout << "\n\nsharedRectPointer.get(): " << sharedRectPointer.get() << endl;
	cout << "\nsharedRectPointer.use_count(): " << sharedRectPointer.use_count() << endl ;
	
	std::shared_ptr<Rectangle> sharedRectPointer2;

	cout << "\n\nsharedRectPointer2.get(): " << sharedRectPointer2.get() << endl;
	cout << "\nsharedRectPointer2.use_count(): " << sharedRectPointer2.use_count() << endl;

	sharedRectPointer2 = sharedRectPointer;

	cout << "\n\nsharedRectPointer.get(): " << sharedRectPointer.get() << endl;
	cout << "\nsharedRectPointer.use_count(): " << sharedRectPointer.use_count() << endl;

	cout << "\n\nsharedRectPointer2.get(): " << sharedRectPointer2.get() << endl;
	cout << "\nsharedRectPointer2.use_count(): " << sharedRectPointer2.use_count() << endl;

	std::shared_ptr<Rectangle> sharedRectPointer3;
	cout << "\n\nsharedRectPointer3.get(): " << sharedRectPointer3.get() << endl;

	cout << "\n\nsharedRectPointer3.get(): " << sharedRectPointer3.get() << endl;
	cout << "\nsharedRectPointer3.use_count(): " << sharedRectPointer3.use_count() << endl;

	sharedRectPointer3 = sharedRectPointer;

	cout << "\n\nsharedRectPointer.get(): " << sharedRectPointer.get() << endl;
	cout << "\nsharedRectPointer.use_count(): " << sharedRectPointer.use_count() << endl;

	cout << "\n\nsharedRectPointer3.get(): " << sharedRectPointer3.get() << endl;
	cout << "\nsharedRectPointer3.use_count(): " << sharedRectPointer3.use_count() << endl;

	cout << "\n\n\n\n\n\n";

	return 0;
}

//void func() {
//	cout << "In Func";
//	P1->
//}