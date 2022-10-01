int LeastPrimeDivisor[MAX];
vector<int> pr;

void LinearSieve(){
	for(int i = 2; i < MAX; i++){
		if(!LeastPrimeDivisor[i]) pr.push_back(i), LeastPrimeDivisor[i] = i;
		for(int p : pr){
				if(i * p >= MAX) break;
				LeastPrimeDivisor[i * p] = p;
				if(i % p == 0) break;
		}
	}
}
