// ** : answer may not be integer even if inputs are intergers, 
// use pdd if necessary

// use a pair to store a point/vector
#define pii pair<int, int>
#define pdd pair<double, double>
#define X first
#define Y second

// addition and subtraction
pii operator+(pii a, pii b){
  return make_pair(a.X + b.X, a.Y + b.Y);
}
pii operator-(pii a, pii b){
  return make_pair(a.X - b.X, a.Y - b.Y);
}

// scalar multiplication
pii operator*(pii a, int b){
  return make_pair(a.X * b, a.Y * b);
}

// ** scalar division
pii operator/(pii a, int b){
  return make_pair(a.X / b, a.Y / b);
}

// dot and cross product
int dot(pii a, pii b){
  return a.X * b.X + a.Y * b.Y;
}
int cross(pii a, pii b){
  return a.X * b.Y - a.Y * b.X;
}

// square of length
int len2(pii a){
  return dot(a, a);
}

// sign function
int sign(int a){
  if(a > 0) return 1;
  if(a < 0) return -1;
  return 0;
}

// orientation of vectors ab and ac
// 1 : anti-clockwise
// 0 : collinear
// -1: clockwise
int ori(pii a, pii b, pii c){
  return sign(cross(b - a, c - a));
}

// check if point c is on segment ab
bool in_seg(pii a, pii b, pii c){
  return cross(a - c, b - c) == 0 and (dot(a - c, b - c) <= 0;
}

// check if segments ab and cd intersect (including endpoints)
bool intersect(pii a, pii b, pii c, pii d){
  if(ori(a, b, c) * ori(a, b, d) == -1 and ori(c, d, a) * ori(c, d, b) == -1) return 1;
  if(in_seg(a, b, c) or in_seg(a, b, d) or in_seg(c, d, a) or in_seg(c, d, b)) return 1;
  return 0;
}

// ** find the intersection point of ab and cd
// (if ab and cd intersect but are not parallel)
pii intersection(pii a, pii b, pii c, pii d){
  int a123 = cross(b - a, c - a);
  int a124 = cross(b - a, d - a);
  return (d * a123 - c * a124) / (a123 - a124);
}

// ** find the projection vector of ac on ab
pii proj(pii a, pii b, pii c){
  return (b - a) * dot(c - a, b - a) / len2(b - a);
}
