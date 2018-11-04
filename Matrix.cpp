#include "Matrix.h"
#include <iostream>
#include <limits>
#include <math.h>
#define DBL_MAX std::numeric_limits<double>::max()      //Definirea unui macro care simbolizeaza valoarea maxima a unei variabile de tip double;


//Functiile get:
int Matrix::get_nrrow()
{
	return m_nrrow;
}
int Matrix::get_nrcol()
{
	return m_nrcol;
}
//Constructor:
Matrix::Matrix(int nrrow, int nrcol)
 {
	int i, j;
	m_nrcol = nrcol;
	m_nrrow = nrrow;
	m_elem = new double* [m_nrrow];
	for ( i = 0; i < m_nrrow; i++)
		m_elem[i] = new double[m_nrcol];
	if (m_nrrow == m_nrcol)
	{
		for ( i = 0; i < m_nrrow; i++)
		{
			for ( j = 0; j < m_nrcol; j++)
				if (i == j) m_elem[i][j] = 1;
				else m_elem[i][j] = 0;
		}
	}


}
//Constructor de copiere:

Matrix::Matrix(const Matrix& obj)
{
	m_nrrow = obj.m_nrrow;
	m_nrcol = obj.m_nrcol;
	m_elem = new double* [m_nrrow];
	for (int i = 0; i < m_nrrow; i++)
    {
		m_elem[i] = new double[m_nrcol];
		for (int j = 0; j < m_nrcol; j++)
			m_elem[i][j] = obj.m_elem[i][j];
	}
}
//Destructor:

Matrix::~Matrix()
{
    for(int i=0;i<m_nrrow;i++)
            delete m_elem[i];
    delete[]m_elem;

}
//Operatori de citire si afisare:

std::istream & operator>>(std::istream & stream, Matrix & obj)
{
    for(int i=0;i<obj.m_nrrow;i++)
        for (int j = 0; j < obj.m_nrcol; j++)
        {
            stream >> obj.m_elem[i][j];
        }
	return stream;
}
std::ostream & operator<<(std::ostream & stream, const Matrix & obj)
{
    for (int i = 0; i < obj.m_nrrow; i++)
    {   for (int j = 0; j < obj.m_nrcol; j++)
        {
            stream<<obj.m_elem[i][j]<< ' ';
        }
        stream << std::endl;
    }




	return stream;
}


//Operatori compusi de atribuire:



Matrix& Matrix::operator+=(Matrix obj)
{
    if(m_nrrow==obj.m_nrrow && m_nrcol==obj.m_nrcol)
   {

        for(int i=0;i<m_nrrow;i++)
            for(int j=0;j<m_nrcol;j++)
                m_elem[i][j]=m_elem[i][j]+obj.m_elem[i][j];

    return *this;
   }
   else throw 3;

}

Matrix& Matrix::operator+=(double number)
{
    for(int i=0;i<m_nrrow;i++)
        for(int j=0;j<m_nrcol;j++)
            m_elem[i][j]=m_elem[i][j]+number;

    return *this;
}

Matrix& Matrix::operator-=(Matrix obj)
{
    if(m_nrrow==obj.m_nrrow && m_nrcol==obj.m_nrcol)
    {
        for(int i=0;i<m_nrrow;i++)
            for(int j=0;j<m_nrcol;j++)
                m_elem[i][j]=m_elem[i][j]-obj.m_elem[i][j];

    return *this;
    }
    else throw 4;

}

Matrix& Matrix::operator-=(double number)
{
    for(int i=0;i<m_nrrow;i++)
        for(int j=0;j<m_nrcol;j++)
            m_elem[i][j]=m_elem[i][j]-number;

    return *this;
}




Matrix& Matrix::operator*=( Matrix obj)
{
    if(m_nrcol!=obj.m_nrrow) throw 1 ;

    else{
            int newRows = m_nrrow;
            int newCols = obj.m_nrcol;

            Matrix *NewMatrix = new Matrix(newRows, newCols);

            for (int i = 0; i < newRows; i++)
            {
                for (int j = 0; j < newCols; j++)
                {   int answer=0;
                    for (int k = 0; k < m_nrcol;k++)
                        answer+=this->m_elem[i][k] * (obj.m_elem[k][j]);
				(*NewMatrix).m_elem[i][j]=answer;
                }

            }
    *this=*NewMatrix;
	 return *this;
        }

}



Matrix& Matrix::operator*=(double number)
{
    for(int i=0;i<m_nrrow;i++)
        for(int j=0;j<m_nrcol;j++)
            m_elem[i][j]=m_elem[i][j]*number;
    return *this;
}



Matrix& Matrix::operator/=(double number)
{
    if(number ==0) throw 2;
        else
            {
                for(int i=0;i<m_nrrow;i++)
                    for(int j=0;j<m_nrcol;j++)
                        m_elem[i][j]=m_elem[i][j]/number;

            return *this;
            }
}

//Operatori unari:



Matrix operator+(Matrix obj )
{
    Matrix result(obj);

    return result;
}

Matrix operator-(Matrix obj)
{
    Matrix result(obj);
    result*=(-1);

    return result;
}



//Operatori aritmetici binari:

Matrix operator+(Matrix obj1, Matrix obj2)
{
    if(obj1.m_nrrow==obj2.m_nrrow && obj1.m_nrcol==obj2.m_nrcol)
	{
	    Matrix result(obj1);
        result+=obj2;

	return result;
	}
    else throw 5;
}


Matrix operator+( Matrix obj, double number)
{
	Matrix result(obj);
    result+=number;

	return result;
}


Matrix operator+( double number,Matrix obj)
{
	Matrix result(obj);
    result+=number;

	return result;
}


Matrix operator-(Matrix obj1, Matrix obj2)
{
    if(obj1.m_nrrow==obj2.m_nrrow && obj1.m_nrcol==obj2.m_nrcol)
	{
	    Matrix result(obj1);
        result-=obj2;

	return result;
	}
	else throw 6;

}


Matrix operator-(Matrix obj, double number)
{
	Matrix result(obj);
    result-=number;

	return result;
}


Matrix operator-( double number,Matrix obj)
{
	Matrix result(obj);
    result*=(-1);
    result+=number;

	return result;
}


Matrix operator*(Matrix obj1, Matrix obj2)
{
    if(obj1.m_nrcol==obj2.m_nrrow)
	{
	    Matrix result(obj1.m_nrrow,obj2.m_nrcol);
        for(int i=0;i<obj1.m_nrrow;i++)
            for(int j=0;j<obj2.m_nrcol;j++)
                result.m_elem[i][j]=0;
        for (int i = 0; i < obj1.m_nrrow; i++)
        {
            for (int j = 0; j < obj2.m_nrcol; j++)
            {
                for (int k = 0; k < obj2.m_nrrow;k++)
                    result.m_elem[i][j] = result.m_elem[i][j] + obj1.m_elem[i][k] * obj2.m_elem[k][j];
            }

        }

	return result;
	}
	else throw 7;
}


Matrix operator*(Matrix obj, double number)
{
	Matrix result(obj);
    result*=number;


	return result;

}


Matrix operator*(double number,Matrix obj)
{
	Matrix result(obj);
    result*=number;


	return result;

}


 Matrix operator/(Matrix obj, double number)
{
    if(number !=0)
    {
        Matrix result(obj);
        for (int i = 0; i < obj.m_nrrow; i++)
        {
            for (int j = 0; j < obj.m_nrcol; j++)
                result.m_elem[i][j] = obj.m_elem[i][j] / number;
        }

	return result;
    }
    else  throw 8;

}


Matrix operator/(double number,Matrix obj)
{
	Matrix result(obj);
	for (int i = 0; i < obj.m_nrrow; i++)
	{
        for (int j = 0; j < obj.m_nrcol; j++)
			result.m_elem[i][j] = number /obj.m_elem[i][j];
	}

	return result;
}


Matrix operator^( const Matrix obj,int number)
{
    if(number==1) return obj;
    if(number == 0)  return 1;
    if(obj.m_nrrow==obj.m_nrcol)
    {
        Matrix result(obj);
        for(int i=0;i<number-1;i++)
            result*=obj;
        int boolean =0;
        for(int index_row=0;index_row<result.m_nrrow;index_row++)
        for(int index_col=0;index_col<result.m_nrcol;index_col++)
            if(result.m_elem[index_row][index_col]>DBL_MAX) boolean=1;

        if(boolean ==1 ) throw -1;
        else
        {
            return result;
        }

     }
     else throw 0;

}

//Alti operatori:

Matrix Matrix::operator[](int pos)
{
    if(m_nrcol==1)
    {
        Matrix result;
        result.m_elem[0][0]=m_elem[pos][0];
        return result;

    }
    else if(m_nrrow==1)
    {
        Matrix result;
        result.m_elem[0][0]=m_elem[0][pos];
        return result;

    }
    else
    {
        int i;
        Matrix result(1,m_nrcol);
        for( i=0;i<m_nrcol;i++)
            result.m_elem[0][i]=m_elem[pos][i];
        return result;
    }

}


//Operatori relationali:



bool operator==(Matrix obj1,Matrix obj2)
{
    if(obj1.m_nrrow!=obj2.m_nrrow || obj1.m_nrcol!=obj2.m_nrcol )
        return false;
    for(int i=0;i<obj1.m_nrrow;i++)
        for (int j=0;j<obj1.m_nrcol;j++)
            if(obj1.m_elem[i][j]!=obj2.m_elem[i][j])
                return false;

    return true;
}
bool operator!=(Matrix obj1,Matrix obj2)
{
    int counter=0;
    if(obj1.m_nrrow==obj2.m_nrrow && obj1.m_nrcol==obj2.m_nrcol)
    {
        for(int i=0;i<obj1.m_nrrow;i++)
        {
            for(int j=0;j<obj1.m_nrcol;j++)
                if(obj1.m_elem[i][j]==obj2.m_elem[i][j]) counter++;
        }
                if(counter==obj1.m_nrrow*obj1.m_nrcol) return false;
    }
    return true;

}







