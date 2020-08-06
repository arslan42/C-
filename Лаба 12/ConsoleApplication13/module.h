#pragma once
#include <iostream>
using namespace std;

class El_mas {
public:
	int j, num;
	El_mas() {}
	El_mas(int k, int ip) { num = k; j = ip; }
	void print() { cout << " j= " << j << " num= " << num << endl; }
};

class Elem {
public:
	El_mas dat;
	int n;
	Elem * next, *prev;
	Elem() { n = 0; next = 0; prev = 0; }
	void print() { dat.print(); }
	

};

class List {
public:
	Elem * first, *last, *cur;
public:
	List() { first = 0; last = 0; cur = 0; }
	void add(int j);
	void add_head(int j);
	void del_head();
	void del_xwost();
	void print_List();
	void print_List_prev();
	void wstawka(Elem *, int);
	void del_zweno(Elem *);
	void del_List();
};

void List::print_List() {
	cur = first;
	while (cur) {
		cout<<cur->n<<" ";
		cur = cur->next;
	}
}

void List::add(int j) {
	cur = new Elem();
	cur->n = j;
	if (first) {
		last->next = cur; cur->prev = last;
		last = cur;
		cur->next = 0;
	}
	else {
		cur->prev = 0; cur->next = 0;
		first = cur; last = cur;
	}
}
void List::del_List() {
	while (first && last) del_head();
}
void List::add_head(int j) {
	cur = new Elem();
	cur->n = j;
	if (first == 0) {
		cur->prev = 0; cur->next = 0;
		first = cur; last = cur;
	}
	else {
		cur->next = first; first->prev = cur;
		first = cur;
	}
}

//vstavka posle zvena s adresom q
void List::wstawka(Elem * q, int j) {
	cur = new Elem();
	cur->n = j;
	if (first&&last&&q != last) {
		cur->prev = q; //posle zvena s adresom q
		cur->next = q->next;
		q->next->prev = cur;
		q->next = cur;
	}
}

void List::del_zweno(Elem * q) {
	cur = q;
	if (first && last && q != last && q != first) {
	//udalenie zvena s adresom q
		q->prev->next = q->next;
		q->next->prev = q->prev;
		delete cur;
	}
}

void List::del_head() {
	if (first->next) {
		cur = first; first->next->prev = 0;
		first = first->next;
		delete cur;
	}
	else if (first) {
		cur = first;
		delete cur;
		first = 0; last = 0;
	}
	else cout << " first=0 " << endl;
}

void List::del_xwost() {
	if (last->prev) {
		cur = last; last->prev->next=0;
		last = last->prev;
		delete cur;
	}
	else if (last) {
		cur = last; 
		delete cur;
		first = 0; last = 0;
	}
	else cout << " last=0 " << endl;
}

int sum_raz_mas(List *sp, List *sp1, List *sps) {
	int j, k;
	sp1->cur = sp1->first;
	sp->cur = sp->first;
	sps->cur = sps->first;
	j = 0;

	while (sp1->cur != 0 && sp->cur != 0) {
		if (sp->cur->dat.num == sp1->cur->dat.num) {
			k = sp1->cur->dat.j + sp->cur->dat.j;
			sps->cur->dat = El_mas(sp1->cur->dat.num, k);
			//cout<<sps->cur->dat.num<<" "<<sps->cur->dat.j<<end;
			sp1->cur = sp1->cur->next;
			sp->cur = sp->cur->next;
			sps->cur = sps->cur->next;
		} 
		else if (sp->cur->dat.num < sp1->cur->dat.num) {
			sps->cur->dat = El_mas(sp->cur->dat.num, sp->cur->dat.j);
			//cout<<sps->cur->dat.num<<" "<<sps->cur->dat.j<<endl;
			sp->cur = sp->cur->next;
			sps->cur = sps->cur->next;
		}
		else {
			sps->cur->dat = El_mas(sp1->cur->dat.num, sp1->cur->dat.j);
			sp1->cur = sp1->cur->next;
			sps->cur = sps->cur->next;
		}
		j++;
	}
	if (sp1->cur != 0) 
		while (sp1->cur != 0) {
			sps->cur->dat = El_mas(sp1->cur->dat.num, sp1->cur->dat.j);
			sp1->cur = sp1->cur->next;
			sps->cur = sps->cur->next;
			j++;
		}
	else while (sp->cur != 0) {
		sps->cur->dat = El_mas(sp->cur->dat.num, sp->cur->dat.j);
		sp->cur = sp->cur->next;
		sps->cur = sps->cur->next;
		j++;
	}
	return j;
}