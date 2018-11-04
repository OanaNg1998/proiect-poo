#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
class Matrix
{
public:

	Matrix(int nrrow = 1, int nrcol= 1);
	Matrix(const Matrix& obj);
	~Matrix();
	int get_nrcol();
	int get_nrrow() ;
	Matrix& operator+=(Matrix obj);
	Matrix& operator+=(double number);
	Matrix& operator-=(Matrix obj);
	Matrix& operator-=(double number);
	Matrix& operator*=( Matrix obj);
	Matrix& operator*=(double number);
	Matrix& operator/=(double number);
	Matrix operator[](int pos);


    friend std::istream& operator>>(std::istream& stream, Matrix& obj);
	friend std::ostream& operator<<(std::ostream& stream, const Matrix& obj);
	friend Matrix operator+(Matrix obj1, Matrix obj2);
	friend Matrix operator+( Matrix obj, int number);
	friend Matrix operator+(double number,Matrix obj);
	friend Matrix operator-(Matrix obj1, Matrix obj2);
	friend Matrix operator-(Matrix obj, double number);
	friend Matrix operator*(Matrix obj1, Matrix obj2);
	friend Matrix operator*(Matrix obj, double number);
	friend Matrix operator*(double number,Matrix obj);
	friend Matrix operator/(Matrix obj, double number);
	friend Matrix operator/(double number,Matrix obj);
	friend Matrix operator^(const Matrix obj,int number);
	friend Matrix operator+(Matrix obj);
	friend Matrix operator-(Matrix obj);
	friend bool operator==(Matrix obj1,Matrix obj2);
	friend bool operator!=(Matrix obj1,Matrix obj2);



private:
	double **m_elem;
	int m_nrcol;
	int m_nrrow;

};


#endif // MATRIX_H_INCLUDED
