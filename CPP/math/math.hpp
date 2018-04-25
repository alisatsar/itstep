#pragma once
#include <iostream>

namespace math
{
	///define for matrix dimensions
	const int ROW = 3;
	const int COL = 3;

	///struct for any vector
	struct vector
	{
		float x;
		float y;
		vector();
		vector(float _x, float _y);
		vector(const vector& v);
		bool operator==(vector const& right_vector) const;
		bool operator!=(vector const& right_vector) const;
	};

	struct vertex
	{
		vector vec;
		vector text_vec;
		vertex();
		vertex(vertex const& right_vertex);
		vertex& operator=(vertex const& right_vertex);
		bool operator==(vertex const& right_vertex) const;
		bool operator!=(vertex const& right_vertex) const;
	};

	struct triangle
	{
		vertex vert[3];
		triangle();
		triangle& operator*(float n);
		triangle& operator=(triangle const& right_triangle);
		bool operator==(triangle const& right_triangle) const;
		bool operator!=(triangle const& right_triangle) const;
		triangle& operator+(vector const& v);
	};

	class matrix
	{
	public:
		float mat[ROW][COL];
		matrix();
		matrix(float scale);
		matrix(vector const& v);
		matrix& operator=(matrix const& right_matrix);
		matrix& operator*(matrix const& right_matrix);
		vector& operator*(vector const& vec);
		friend std::ostream& operator<<(std::ostream& os, matrix const& mat);
		void print();
	};
	std::ostream& operator<<(std::ostream& os, matrix const& mat);

}


