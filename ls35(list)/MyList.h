#pragma once
#include "Node.h"

namespace MyList {
	template<typename U>
	class List {
		Node<U>* head;
		Node<U>* tail;
	public:
		List() {
			head = tail = nullptr;
		}
		~List() {

		}
		void push_back(U value) {
			//1 Створюємо вузол
			Node<U>* el = new Node<U>(value);

			//Якщо це перший вузол
			if (head == nullptr) {
				head = el; //Назначаємо голову та хвіст
				tail = el;
			}
			else {//Якщо HE перший вузол
				tail->next = el;
				tail = el; //Оновлюємо хвіст
			}
		}
		void showInfo()const {
			if (head == nullptr) cout << "List is empty\n";
			else {
				Node<U>* p = head;
				while (p != nullptr) {
					p->show();
					p = p->next;
				}
			}
		}
	};

	template<typename U>
	class DList {
		DNode<U>* head;
		DNode<U>* tail;
	public:
		DList() {
			head = tail = nullptr;
		}
		~DList() {
			DNode<U>* p = head;
			while (p != nullptr) {
				DNode<U>* tmp = p;
				p = p->next;
				cout << "Delete: " << tmp->item << endl;
				delete tmp;
			}
		}
		
		void push_back(U value) {
			DNode<U>* el = new DNode<U>(value);
			if (head == nullptr) {
				head = tail = el;
			}
			else {
				tail->next = el;
				el->prev = tail;
				tail = el;
			}
		}

		void showInfo()const {
			if (head == nullptr) cout << "List is empty\n";
			else {
				DNode<U>* p = head;
				while (p != nullptr) {
					cout << p->item << " ";
					p = p->next;
				}
			}
			cout << endl;
		}
		void showReverseInfo()const {
			if (head == nullptr) cout << "List is empty\n";
			else {
				DNode<U>* p = tail;
				while (p != nullptr) {
					cout << p->item << " ";
					p = p->prev;
				}
			}
			cout << endl;
		}
		DNode<U>* search(U value) {
			DNode<U>* p = head;
			while (p != nullptr) {
				if (p->item == value) {
					return p;
				}
				else
				{
					p = p->next;
				}
			}return nullptr;
		}

		void push_front(U value) {
			DNode<U>* el = new DNode<U>(value);
			if (head == nullptr) {
				head = tail = el;
			}
			else {
				el->next = head;
				head->prev = el;
				head = el;
			}
		}
		void insertBefore(U before, U value) {
			DNode<U>* Before = search(before);
			if (Before != nullptr) {
				DNode<U>* el = new DNode<U>(value);
				el->next = Before;
				el->prev = Before->prev;
				if (Before->prev != nullptr) {
					Before->prev->next = el;
				}
				else {
					head = el;
				}
				Before->prev = el;
			}
		}
		void insertAfter(U after, U value) {
			DNode<U>* After = search(after);
			if (After != nullptr) {
				DNode<U>* el = new DNode<U>(value);
				el->prev = After;
				el->next = After->next;
				if (After->next != nullptr) {
					After->next->prev = el;
				}
				else {
					tail = el;
				}
				After->next = el;
			}
		}

		void erase(U value) { 
			DNode<U>* el = search(value);
			if (el != nullptr) {
				if (el->prev != nullptr) {
					el->prev->next = el->next;
				}
				else {
					head = el->next;
				}
				if (el->next != nullptr) {
					el->next->prev = el->prev;
				}
				else
				{
					tail = el->prev;
				}
				delete el;
			}
		}

	};
}