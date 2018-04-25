#include "my_math.h"

using namespace math;

///vector class implementation
vector::vector() : x(0.0), y(0.0) {}

vector::vector(float _x, float _y) : x(_x), y(_y) {}

vector::vector(const vector& v) : x(v.x), y(v.y) {}

bool vector::operator==(vector const& right_vector) const
{
	return (this->x == right_vector.x) && (this->y == right_vector.y);
}

bool vector::operator!=(vector const& right_vector) const
{
	return !(*this == right_vector);
}

vertex::vertex()
{
	vec.x = 0.0f;
	vec.y = 0.0f;
	text_vec.x = 0.0f;
	text_vec.y = 0.0f;
}

vertex::vertex(vertex const& right_vertex)
{
	vec.x = right_vertex.vec.x;
	vec.y = right_vertex.vec.y;
	text_vec.x = right_vertex.text_vec.x;
	text_vec.y = right_vertex.text_vec.y;
}

vertex& vertex::operator=(vertex const& right_vertex)
{
	this->text_vec = right_vertex.text_vec;
	this->vec = right_vertex.vec;

	return *this;
}

bool vertex::operator==(vertex const& right_vertex) const
{
	return (this->text_vec == right_vertex.text_vec) && (this->vec == right_vertex.vec);
}

bool vertex::operator!=(vertex const& right_vertex) const
{
	return !(*this == right_vertex);
}

///triangle class implementation
triangle::triangle()
{
	vert[0] = vertex();
	vert[1] = vertex();
	vert[2] = vertex();
}

triangle& triangle::operator*(float n)
{
	matrix scale(n);
	vector result;
	for (int i = 0; i < 3; i++)
	{
		result = scale * this->vert[i].vec;

		this->vert[i].vec.x = result.x;
		this->vert[i].vec.y = result.y;
	}

	return *this;
}

triangle& triangle::operator=(triangle const& right_triangle)
{
	this->vert[0].vec = right_triangle.vert[0].vec;
	this->vert[0].text_vec = right_triangle.vert[0].text_vec;
	return *this;
}

bool triangle::operator==(triangle const& right_triangle) const
{
	for (int i = 0; i < 3; ++i)
	{
		if (this->vert[i] != right_triangle.vert[i])
		{
			return false;
		}
	}
	return true;
}

bool triangle::operator!=(triangle const& right_triangle) const
{
	return !(*this == right_triangle);
}
//move
triangle& triangle::operator+(vector const& v)
{
	matrix m(v);
	for (int i = 0; i < 3; ++i)
	{
		this->vert[i].vec = m * this->vert[i].vec;
		this->vert[i].text_vec = m * this->vert[i].text_vec;
	}
	return *this;
}

///matrix class implementation
matrix::matrix()
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			mat[i][j] = 0.0;
		}
	}
}

matrix::matrix(float scale)
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (j == i && j != 2)
			{
				mat[i][j] = scale;
			}
			else
			{
				mat[i][j] = 0.0;
			}
		}
	}
}

matrix::matrix(vector const& v)
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (j == i)
			{
				mat[i][j] = 1;
			}
			else if (j == 2 && j != i)
			{
				if (i == 0)
				{
					mat[i][j] = v.x;
				}
				if (i == 1)
				{
					mat[i][j] = v.y;
				}
			}
			else
			{
				mat[i][j] = 0.0;
			}
		}
	}
}

matrix& matrix::operator=(matrix const& right_matrix)
{
	matrix left = *this;

	if (this != &right_matrix)
	{
		for (int r = 0; r < ROW; ++r)
		{
			for (int c = 0; c < COL; ++c)
			{
				left.mat[r][c] = right_matrix.mat[r][c];
			}
		}
	}

	return left;
}

matrix& matrix::operator*(matrix const& right_matrix)
{
	return *this;
}

vector& matrix::operator*(vector const& vec)
{
	float a = 0.f;
	float b = 0.f;

	a += this->mat[0][0] * vec.x + this->mat[0][1] * vec.y + this->mat[0][2] * 1;
	b += this->mat[1][0] * vec.x + this->mat[1][1] * vec.y + this->mat[1][2] * 1;

	//float a = this->mat[0][0] * vec.x;
	//float b = this->mat[1][1] * vec.y;
	vector result(a, b);
	return result;
}

std::ostream& operator<<(std::ostream& os, matrix const& mat)
{
	for (int r = 0; r < ROW; ++r)
	{
		for (int c = 0; c < COL; c++)
		{
			os << "[" << r << "]" << "[" << c << "]" << mat.mat[r][c] << "\n";
		}
		os << std::endl;
	}

	return os;
}

void matrix::print()
{
	for (int r = 0; r < ROW; ++r)
	{
		for (int c = 0; c < COL; c++)
		{
			std::cout << this->mat[r][c];
		}
		std::cout << "\n";
	}
}
