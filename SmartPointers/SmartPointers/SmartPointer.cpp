//#include<iostream>
//using namespace std;
//
//template<class T>
//class SmartPointer{
//
//	T* ptr;
//public:
//	SmartPointer(T* p)
//	{
//		cout << "\nConstructor of Smart pointer is called\n";
//		ptr = p;
//	}
//	~SmartPointer()
//	{
//		cout << "\nDestructor of Smart pointer is called\n";
//		delete(ptr);
//	}
//	//operator oveerloading
//	T & operator *()
//	{
//		return *ptr;
//	}
//	T* operator->() { return ptr; }
//};
//
//int main() {
//
//	/*int a = 10;
//	SmartPointer<int> sP(&a);*/
//
//	SmartPointer<int> ptr(new int());
//	*ptr = 20;
//	cout << *ptr;
//
//	return 0;
//}