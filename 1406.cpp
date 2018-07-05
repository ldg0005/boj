#include <iostream>
using namespace std;

struct List {
	struct Node {
		char ch;
		Node *next, *prev;
		Node() { ch = 0, next = prev = 0; }
	};
	Node *head, *cur;
	List() {
		head = new Node();
		cur = new Node();
		head->next = cur;
		cur->prev = head;
	}
	void push(char ch) {
		Node *newnode = new Node();
		newnode->ch = ch;
		newnode->next = newnode->prev = 0;
		if (head->next == cur) {
			head->next = newnode;
			newnode->prev = head;
			newnode->next = cur;
			cur->prev = newnode;
		}
		else {
			cur->prev->next = newnode;
			newnode->prev = cur->prev;
			newnode->next = cur;
			cur->prev = newnode;
		}
	}
	void del() {
		if (cur->prev == head) return;
		Node *del = cur->prev;
		del->prev->next = cur;
		cur->prev = del->prev;
		delete del;
	}
	void left() {
		if (cur->prev == head) return;
		Node *tmp = cur->prev;
		tmp->prev->next = cur;
		cur->prev = tmp->prev;
		tmp->next = cur->next;
		if(cur->next!=0)
			cur->next->prev = tmp;
		cur->next = tmp;
		tmp->prev = cur;
	}
	void right() {
		if (cur->next == 0) return;
		Node *tmp = cur->next;
		cur->prev->next = tmp;
		tmp->prev = cur->prev;
		if(tmp->next !=0)
			tmp->next->prev = cur;
		cur->next = tmp->next;
		tmp->next = cur;
		cur->prev = tmp;
	}
	void print() {
		Node *tmp = head;
		while (tmp->next != 0) {
			tmp = tmp->next;
			if(tmp!=cur) cout << tmp->ch;
		}
	}
};

char str[100001];
int N;
List *root;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	cin >> N;
	root = new List();
	for (int i = 0; str[i]; i++)
		root->push(str[i]);
	char a, b;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == 'P') {
			cin >> b;
			root->push(b);
		}
		else if (a == 'L')
			root->left();
		else if (a == 'D')
			root->right();
		else if (a == 'B')
			root->del();
	}
	root->print();
	cout << '\n';

	return 0;
}