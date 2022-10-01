// given (a, b), returns (d, x, y) s.t. ax + by = d = gcd(a, b)

vector<int> ExtGcd(int a, int b){
	if(!b) return {a, 1, 0};
	int d, x, y;
	tie(d, x, y) = ExtGcd(b, a % b);
	return {d, y, x - (a / b) * y};
}
