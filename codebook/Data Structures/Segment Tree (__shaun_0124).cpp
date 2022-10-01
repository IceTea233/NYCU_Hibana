// fill in the blanks to do whatever things you want it to do

#define V st[cidx]
#define LC st[cidx*2]
#define RC st[cidx*2+1]

struct Node{
	int sl, sr;
	// info, tag
};

Node st[4*MAX];
 
void build(int cidx, int cl, int cr){
	V.sl = cl;
	V.sr = cr;
	if(cl < cr){
		int mid = (cl + cr) / 2;
		build(cidx*2, cl, mid);
		build(cidx*2+1, mid+1, cr);
		// V.info
    // V.tag
  }
  else{
		// V.info
		// V.tag
  }
}
 
void push(int cidx){
  // update V.info with V.tag
  // push V.tag to LC.tag and RC.tag
  // delete V.tag
}
 
void pull(int cidx){
  push(cidx);
  if(V.sl < V.sr){
  	push(cidx*2);
    push(cidx*2+1);
    // update V.info with LC.info and RC.info
  }
}

void modify(int cidx, int ml, int mr, /* modify */){
  if(mr < V.sl or V.sr < ml) return;
  if(ml <= V.sl and V.sr <= mr){
  	// update V.tag
    return;
  }
  push(cidx);
  modify(cidx*2, ml, mr, /* modify */);
  modify(cidx*2+1, ml, mr, /* modify */);
  pull(cidx);
}

/*  */ query(int cidx, int ql, int qr){
  if(qr < V.sl or V.sr < ql) return /* I */;
  pull(cidx);
  if(ql <= V.sl and V.sr <= qr) return /* V.info */;
  return /* merge( query(cidx*2, ql, qr) , query(cidx*2 + 1, ql, qr) ) */;
}

// call build(1, 1, n) to build a tree for segment [1, n]
// call modify(1, l, r, v) to modify [l, r] with parameter v
// call query(1, l, r) to get the answer for segment [l, r]
