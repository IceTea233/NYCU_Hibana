#include<complex> //use complex as a 2D space
#define TYPE double // or use int if necessary
#define pos complex<TYPE>
#define vec complex<TYPE>
#define x real()
#define y imag()

using namespace std;

/* built-in operators
  const should be the same type as the type of complex<TP>
  '+', '-', '*', '/', '=', '==', '!='
*/

/*defined functions and operators*/
struct cmp { // to support sorting
  bool operator ()(pos a, pos b)& {
    if (a.x == b.x)
      return a.y < b.y;
    return a.x < b.x;
  }
};

TP operator &(const vec a, const vec b) { // inner product
  return a.x * b.x + a.y * b.y;
}
TP operator |(const vec a, const vec b) { // outer product
  return a.x * b.y - a.y * b.x;
}
vec unit(vec &v) {
  return v/abs(v);
}

/* built-in functions
  double abs(const vec v)
    -> the length of the vector
  double arg(const vec v)
    -> phase angle of the vector
  double norm(const vec v)
    -> square of the abs value
  vec polar(const TP r, const TP theta)
    -> (r, theta) to (x, y)
  double sin(const vec v)
  double cos(const vec v)
  double tan(const vec v)
*/