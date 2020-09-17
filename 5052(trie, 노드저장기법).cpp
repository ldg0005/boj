#include <iostream>
using namespace std;
struct _node {
   _node* next[13];
   bool tail;
};
int T;
int N;
_node node[100001];
int size;
_node* getNode() {
   node[size].tail = false;
   for (int i = 0; i < 13; i++) {
      node[size].next[i] = nullptr;
   }
   return &node[size++];
}
_node* root;
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> T;
   while (T--) {
      size = 0;
      root = getNode();

      cin >> N;
      bool success = true;
      for (int i = 0; i < N; i++) {
         char temp[13]={0,};
         cin >> temp;
         _node* ptr = root;
         for (int j = 0; success && temp[j] != 0; j++) {
            int idx = temp[j] - '0';
            if (ptr->next[idx] == nullptr) {
               ptr->next[idx] = getNode();
            }

            ptr = ptr->next[idx];
            if (ptr->tail) {
               success = false;
            }
         }
         ptr->tail = true;
         for (int i = 0; success && i < 13; i++) {
            if (ptr->next[i] != nullptr) {
               success = false;
            }
         }
      }

      if (success) cout << "YES\n";
      else cout << "NO\n";
   }

}
