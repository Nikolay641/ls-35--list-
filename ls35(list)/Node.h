#pragma once
#include <iostream>
using std::cout;
using std::endl;

namespace MyList {
	template<typename T>
	class Node
	{
	public:
		T item;
		Node* next;

		Node(T value) { item = value; next = nullptr; }
		void show()const {
			cout << "Item: " << item << endl;
			cout << "\tNext: " << next << endl;
		}
	};

	template<typename T>
	class DNode
	{
	public:
		T item;
		DNode* next;
		DNode* prev;

		DNode(T value) { 
			item = value; 
			next = nullptr; 
			prev = nullptr; 
		}
		
		void show()const {
			cout << "Item: " << item << endl;
			cout << "\tNext: " << next << endl;
			cout << "\tPrev: " << prev << endl;
		}
	};
}