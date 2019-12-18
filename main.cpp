#include <iostream>
using namespace std;

struct node {
	int v;
	node* nxt;
};

node* init() {
	node* p = new node;
	p->nxt = NULL;
	return p;
}

void add(int v, node *p) {
	node *temp = p;
	node *nxt = new node;
	nxt->v = v;
	nxt->nxt = NULL;

	while(temp->nxt != NULL) temp = temp->nxt;
	temp->nxt = nxt;
}

void print(node* p) {
	node *temp = p->nxt;

	cout<<"x"<<endl;
	while(temp != NULL) {
		cout<<temp->v<<endl;
		temp = temp->nxt;
	}cout<<endl;
}

node* merge(node *f, node *s) {
	node *res = new node;
	node *resp = res;

	while(true) {
		if(f->nxt == NULL) {
			resp->nxt = s->nxt;
			return res;
		} else if (s->nxt == NULL) {
			resp->nxt = f->nxt;
			return res;
		} else {
			if(f->nxt->v <= s->nxt->v) {
				resp->nxt = f->nxt;
				f->nxt = f->nxt->nxt;
			} else {
				resp->nxt = s->nxt;
				s->nxt = s->nxt->nxt;
			}
			resp->nxt->nxt = NULL;
			resp = resp->nxt;
		}
	}

	return NULL;
}

int main() {
	node *f = init();
	node *s = init();

	for(int i(0); i<10; i++) {
		add(2*i, f);
		add(2*i+1, s);
	}

	print(merge(f, s));

	return 0;
}