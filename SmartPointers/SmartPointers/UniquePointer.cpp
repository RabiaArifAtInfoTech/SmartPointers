#include <iostream>
//using namespace std;
#include <memory>

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b) {
		length = l;
		breadth = b;
		std::cout << "\nConstructor of Rectangle is called"<< std::endl;
	}

	~Rectangle() {
		std::cout << "\nDestructor of Rectangle is called\n";
	}
	int area() {
		return length * breadth;
	}
	//copy constructor
	Rectangle(const Rectangle& pt)
	{
		std::cout << "\nin Rectangle copy  constructor";
	}
	//move constructor
	Rectangle(Rectangle&& pt)
	{
		std::cout << "\nin Rectangle Move constructor";
	}
	
	Rectangle& operator*() {
		std::cout << "\nin \"*\" operator ";

	}
	Rectangle& operator=(Rectangle pt) {
		std::cout << "\nin \"=\" operator ";

		return pt;
	}
	/*friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect)
	{
		return os << "{ x=" << rect.length << ", y=" << rect.breadth << " }";
	}*/
	
};


//void printPointer(std::unique_ptr<Rectangle> rect1)
//{
//	std::cout << "\nP1 area: " << rect1->area() << std::endl; // This'll print 50
//	std::cout << "\nP1.get(): " << rect1.get() << std::endl;
//}

int main() {

	std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	std::cout << "\nP1 area: " << P1->area() << std::endl; // This'll print 50
	std::cout << "\nP1.get(): " << P1.get() << std::endl;
	
	{

		std::cout << "\nP1 area: inside loop " << P1->area() << std::endl; // This'll print 50
		std::cout << "\nP1.get(): " << P1.get() << std::endl;

		std::unique_ptr<Rectangle> P2;
		std::cout << "\nP2.get(): " << P2.get() << std::endl;
		P2 = std::move(P1);
		std::cout << "\nP2 area: " << P2->area() << std::endl;
		std::cout << "\nP1.get(): " << P1.get() << std::endl;

	//cout << "\nP2 area: " << P2->area() << endl;
	}
	std::cout << "\nP2 area: " << P2->area() << std::endl;
	std::cout << "\nP1.get(): " << P1.get() << std::endl;

	
	//unique_ptr<Rectangle> P2(P1); // error: cannot be reffered -- it is a deleted function
	
	//std::unique_ptr<Rectangle> P2;
	//std::cout << "\nP2.get(): " << P2.get() << std::endl;
	////cout << "\nP2 area: " << P2->area() << endl;

	////P2 = P1;  // error: cannot be reffered -- it is a deleted function

	//P2 = std::move(P1);

	//// This'll print 50
	//std::cout << "\nP2 area: " << P2->area() << std::endl;
	//std::cout << "\nP1.get(): " << P1.get() << std::endl;
	//std::cout << "\nP2.get(): " << P2.get() << std::endl;
	//std::cout << "\nP1.get(): " << P1.get() << std::endl;
	////cout <<  "\nP1 area: " << P1->area() << endl; //error ....solution: shared pointer



	//Rectangle rect123(11, 11);
	////cout << rect123->area() << endl;

	//Rectangle rect13(117, 11);
	//cout << P2->area() << endl;
	/*for (int i = 0; i < 1 ; i++)
	{
		cout << "\nP1.get() inside loop: " << P1.get() << endl;
	}*/
	//std::unique_ptr<Rectangle> unique_Rect1 = std::make_unique<Rectangle>(rect123); //goes to copy constructor
	//std::cout << "\nunique_Rect1.get(): " << unique_Rect1.get() << std::endl;

	//std::unique_ptr<Rectangle> unique_Rect2; //goes to copy constructor

	////unique_ptr<Rectangle> unique_Rect2 = std::make_unique<Rectangle>(rect13); //goes to copy constructor
	//unique_Rect2 = std::move(unique_Rect1);

	//std::cout << "\nunique_Rect2.get(): " << unique_Rect2.get() << std::endl;
	//std::cout << "\nunique_Rect1.get(): " << unique_Rect1.get() << std::endl;

	 //cout<<P1->area()<<endl;



	////................Shared Pointer....................//

	//std::cout << "\n\n\n\n.....Shared Pointer.........\n\n";

	//std::shared_ptr<Rectangle> sharedRectPointer = std::make_shared<Rectangle>(Rectangle(11, 11));

	//std::cout << "\n\nsharedRectPointer.get(): " << sharedRectPointer.get() << std::endl;
	//std::cout << "\nsharedRectPointer.use_count(): " << sharedRectPointer.use_count() << std::endl;


	//{
	//	std::cout << "\n\nInside Scope:,..............." << std::endl;

	//	std::shared_ptr<Rectangle> sharedRectPointer2;

	//	std::cout << "\n\nsharedRectPointer2.get(): " << sharedRectPointer2.get() << std::endl;
	//	std::cout << "\nsharedRectPointer2.use_count(): " << sharedRectPointer2.use_count() << std::endl;

	//	sharedRectPointer2 = sharedRectPointer; //sharedRectPointer can be accessed here

	//	std::cout << "\n\nsharedRectPointer.get(): " << sharedRectPointer.get() << std::endl;
	//	std::cout << "\nsharedRectPointer.use_count(): " << sharedRectPointer.use_count() << std::endl;

	//	std::cout << "\n\nsharedRectPointer2.get(): " << sharedRectPointer2.get() << std::endl;
	//	std::cout << "\nsharedRectPointer2.use_count(): " << sharedRectPointer2.use_count() << std::endl;

	//}

	//sharedRectPointer2 cannot be accesed here
	// 
	//std::cout << "\n\nsharedRectPointer2.get(): " << sharedRectPointer2.get() << std::endl;
	//std::cout << "\nsharedRectPointer2.use_count(): " << sharedRectPointer2.use_count() << std::endl;


	//std::shared_ptr<Rectangle> sharedRectPointer2;

	//std::cout << "\n\nsharedRectPointer2.get(): " << sharedRectPointer2.get() << std::endl;
	//std::cout << "\nsharedRectPointer2.use_count(): " << sharedRectPointer2.use_count() << std::endl;

	//sharedRectPointer2 = sharedRectPointer;

	//std::cout << "\n\nsharedRectPointer.get(): " << sharedRectPointer.get() << std::endl;
	//std::cout << "\nsharedRectPointer.use_count(): " << sharedRectPointer.use_count() << std::endl;

	//std::cout << "\n\nsharedRectPointer2.get(): " << sharedRectPointer2.get() << std::endl;
	//std::cout << "\nsharedRectPointer2.use_count(): " << sharedRectPointer2.use_count() << std::endl;

	//std::shared_ptr<Rectangle> sharedRectPointer3;
	//std::cout << "\n\nsharedRectPointer3.get(): " << sharedRectPointer3.get() << std::endl;

	//std::cout << "\n\nsharedRectPointer3.get(): " << sharedRectPointer3.get() << std::endl;
	//std::cout << "\nsharedRectPointer3.use_count(): " << sharedRectPointer3.use_count() << std::endl;

	//sharedRectPointer3 = sharedRectPointer;

	//std::cout << "\n\nsharedRectPointer.get(): " << sharedRectPointer.get() << std::endl;
	//std::cout << "\nsharedRectPointer.use_count(): " << sharedRectPointer.use_count() << std::endl;

	//std::cout << "\n\nsharedRectPointer3.get(): " << sharedRectPointer3.get() << std::endl;
	//std::cout << "\nsharedRectPointer3.use_count(): " << sharedRectPointer3.use_count() << std::endl;
	std::cout << "\n\n\n\n\n\n";

	return 0;
}
