// fill in the blanks to do whatever things you want it to do

#define Get(T, x) (((T) == nullptr) ? (/*default*/) : (T->x))

struct Treap{
	Treap *l, *r;
	int pri, sz;
	// information of T
  // tags if needed
  Treap(int _val): l(nullptr), r(nullptr), /*info, tag*/, pri(rand()), sz(1) {}
};

// not necessary if without tag
void push(Treap *&T){
  if(T == nullptr) return;
  // apply T->tag on T
  // push T->tag to T->l, T->r
  // delete T->tag
}

void pull(Treap *&T){
	if(T == nullptr) return;
  push(T);
  if(T->l != nullptr) push(T->l);
  if(T->r != nullptr) push(T->r);
  // calculate T->info, T->sz using information of T->l, T->r
}

Treap* Merge(Treap *a, Treap *b){
  if(a == nullptr) return b;
  if(b == nullptr) return a;
  if(a->pri < b->pri){
		push(a);
    a->r = Merge(a->r, b);
    pull(a);
    return a;
	}
  else{  
    push(b);
    b->l = Merge(a, b->l);
    pull(b);
    return b;
  }
}
 
void Split_by_sz(Treap *T, Treap *&a, Treap *&b, int k){
  if(T == nullptr){
    a = b = nullptr;
    return;
  }
  push(T);
  if( Get(T->l, sz) + 1 <= k ){
    a = T;
    Split_by_sz(a->r, a->r, b, k - Get(T->l, sz) - 1);
    pull(a);
  }
  else{
    b = T;
    Split_by_sz(b->l, a, b->l, k);
    pull(b);
  }
}

// call Get(T, x) to get information x of node T, 
// or default value if node T does not exist

// call Merge(a, b) to merge two treaps a, b
// the resulting treap is its return value

// call Split_by_sz(T, a, b, k) to split a treap T into two treaps a, b
// size of a is k (or size of T if it is less than k)
// the two resulting treaps are stored in a, b
