#include <bits/stdc++.h>

using namespace std;

class hash_table {
	#define SIZE 65536

	struct node {
		int value;
		struct node *next;
		node() {}
		node(int v): value(v), next(NULL) {}
	};

	struct node table[SIZE];
public:
	hash_table() { memset(table, 0, sizeof(table)); }

	int hash(int x) { return abs(x % SIZE); }

	int count(int x) {
		int block = hash(x);
		struct node *ptr = table[block].next;
		while (ptr != NULL) {
			if (ptr->value == x)
				return 1;
			ptr = ptr->next;
		}
		return 0;
	}

	void insert(int x) {
		if (count(x))
			return;
		int block = hash(x);
		struct node *attach = new node(x); 
		attach->next = table[block].next;
		table[block].next = attach;
	}

	void erase(int x) {
		// if (!count(x))
		// 	return;
		int block = hash(x);
		struct node *ptr = &table[block];
		while (ptr->next) {
			if (ptr->next->value == x) {
				struct node *release = ptr->next;
				ptr->next = ptr->next->next;
				free(release);
			}
		}
	}
};

int main() {
	hash_table table;
	table.insert(2);
	table.insert(99);
	table.erase(99);
	table.erase(0);
	table.insert(0);
	table.insert(0);
	cout << table.count(0) << endl;
}