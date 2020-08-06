#pragma once
#include <iostream>
using namespace std;
class El_mas {
public:
	int j, num;
	El_mas() {}
	El_mas(int x, int ip) { num = x; j = ip; }
	void print() { cout << " j=" << j << ", num=" << num << endl; }
	
};



class Elemd {
public:
	El_mas data;
	int n;
	Elemd *next;
	Elemd(int j, El_mas tv) { data = tv; n = j; next = 0; }
	void print() { data.print(); }
};

class Listd {
public:
	Elemd *first, *last, *cur;
public:
	Listd() { first = 0; last = 0; cur = 0; }
	~Listd() { del_List(); cout << " DESTROY "; }
	void del_List();
	void add(int temp, El_mas t);
	void add_head(int temp, El_mas t);
	void print_List();
	void del_head();
	void del_xwost();
	void del_cur(Elemd *q);
	void del_tec_cur(Elemd *q);
	void wstawka(Elemd *q, El_mas nov, int j);
};

//dobavit v hvost
void Listd::add(int j, El_mas t) {
	cur = new Elemd(j, t);
	if (first) {
		last->next = cur;
		last = cur;
	}
	else {
		first = cur;
		last = cur;
	}
}

//dobavit v head
void Listd::add_head(int j, El_mas t) {
	cur = new Elemd(j, t);
	if (!first) {
		first = cur; 
		last = cur;
	}
	else {
		cur->next = first;
		first = cur;
	}
}

void Listd::print_List() {
	cur = first;
	while (cur != 0) {
		cur->print();
		cur = cur->next;
	}
}

void Listd::del_head() {
	if (first->next) {
		cur = first;
		first = first->next;
		delete cur;
	}
	else 
		if (first) {
			cur = first;
			delete cur;
			first = 0;
			last = 0;
		}
		else cout << " first=0" << endl;
	
}

void Listd::del_xwost() {
	if (last && first->next) {
		cur = first;
		while (cur->next->next != 0) cur = cur->next;
		last = cur;
		cur->next = 0;
		cur = cur->next;
		delete cur;
		}
	else {
		cur = last;
		delete cur;
		first = 0;
		last = 0;
		cout << " last=0" << endl;
	}
}

void Listd::del_List() {
	while (first && last) del_head();
}

//udalenie sled zvena za zvenom s adresom qur
void Listd::del_cur(Elemd * q) {
	if (first && last && q != last && q != first) {
		cur = q->next;
		q->next = q->next->next;
		delete cur;
	}
}

void Listd::del_tec_cur(Elemd *q) {
	if (first && last && q != last && q != first) {
		cur = first;
		while (cur->next != q) cur = cur->next;
		cur->next = q->next;
		delete q;
	}
}

//vstavka posle zvena q
void Listd::wstawka(Elemd *q, El_mas nov, int j) {
	cur = new Elemd (j,nov);
	if (first && last && q != last) {
		cur->next = q->next;
		q->next = cur;
	}
}