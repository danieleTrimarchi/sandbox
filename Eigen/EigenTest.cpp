#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/CXX11/Tensor>
#include <numeric>
#include <vector>

template<typename T>
using  MatrixType = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

template<typename Scalar, int rank, typename sizeType>
auto Tensor_to_Matrix(const Eigen::Tensor<Scalar, rank>& tensor, const sizeType rows, const sizeType cols)
{
	return Eigen::Map<const MatrixType<Scalar>>(tensor.data(), rows, cols);
}

template<typename Scalar, typename... Dims>
auto Matrix_to_Tensor(const MatrixType<Scalar>& matrix, Dims... dims)
{
	constexpr int rank = sizeof... (Dims);
	return Eigen::TensorMap<Eigen::Tensor<const Scalar, rank>>(matrix.data(), { dims... });
}

int main() {

	size_t size = 3;
	double value(4.7);
	Eigen::VectorXf v(Eigen::VectorXf::Ones(size) * value ) ;
	Eigen::MatrixXf m(Eigen::MatrixXf::Random(size, 2 * size) );

	std::cout << "v= \n" << v <<"\n";
	std::cout << "m= \n" << m << "\n";

	std::cout << "v - m.col(1)= \n" << v - m.col(1) << "\n";
	std::cout << " (v - m.col(1) ).cwiseAbs()= \n" << (v - m.col(1)).cwiseAbs() << "\n";

	Eigen::MatrixXf::Index index;
	double min = (v - m.col(1) ).cwiseAbs().minCoeff(&index);
	std::cout << "min = " << min << std::endl;

		 
	//Eigen::Tensor<int, 4> t(10, 10, 10, 10);
	//t(0, 1, 2, 3) = 42.0;

	//double storage[128];  // 2 x 4 x 2 x 8 = 128
	//Eigen::TensorMap<Eigen::Tensor<int, 4>> t_4d(storage, 2, 4, 2, 8);

	//// Initialize all elements
	//for (int i = 0; i < 2; ++i) {
	//	for (int j = 0; j < 4; ++j) {
	//		for (int k = 0; k < 2; ++k) {
	//			for (int l = 0; l < 8; ++l) {
	//				t_4d(i, j, k, l) = i*j*k*l;
	//			}
	//		}
	//	}
	//}

	Eigen::Tensor<float, 3> a(3, 4, 2);
	a.setZero();
	a(0, 0, 0) = 0.00;
	a(1, 0, 0) = 1.00;
	a(2, 0, 0) = 2.00;
	a(0, 1, 0) = 0.10;
	a(1, 1, 0) = 1.11;
	a(2, 1, 0) = 2.10;
	a(1, 2, 0) = 1.21;
	a(0, 2, 0) = 0.20;
	a(2, 2, 0) = 2.20;
	a(1, 3, 0) = 1.31;
	a(0, 3, 0) = 0.30;
	a(2, 3, 0) = 2.30;

	a(0, 0, 1) = 0.01;
	a(1, 0, 1) = 1.01;
	a(2, 0, 1) = 2.01;
	a(0, 1, 1) = 0.11;
	a(1, 1, 1) = 1.11;
	a(2, 1, 1) = 2.11;
	a(1, 2, 1) = 1.21;
	a(0, 2, 1) = 0.21;
	a(2, 2, 1) = 2.21;
	a(1, 3, 1) = 1.31;
	a(0, 3, 1) = 0.31;
	a(2, 3, 1) = 2.31;
	
	std::cout << "Full view = \n" << a << std::endl;

	// a(0,0,:)
	//Eigen::array<INT64, 3> offsets = { 0, 0, 0 };
	//Eigen::array<INT64, 3> extents = { 1, 1, 2 };
	//Eigen::Tensor<float, 3> c = a.slice(offsets, extents);
	//std::cout <<"Sliced view = \n" << c << std::endl;

	// a(:,1,:)
	Eigen::array<INT64, 3> offsets = { 0, 1, 0 };
	Eigen::array<INT64, 3> extents = { 3, 1, 2 };
	Eigen::Tensor<float,3> c(a.slice(offsets, extents));

	std::cout << "Sliced view = \n" << c << std::endl;
	std::cout << "Dimensions of c: " << c.dimension(0)<<" "<<c.dimension(1) << " "<< c.dimension(2) << std::endl;

	c(1,0, 1) = 123.;

	// Re-assign the slice to the original Tensor 
	a.slice(offsets, extents) = c; 
	std::cout << "Full view = \n" << a << std::endl;

	Eigen::MatrixXf mymatrix = Tensor_to_Matrix(c,3, 2);	//std::cout << "Sliced matrix view  = \n" << cm << std::endl;
	std::cout << "conversion to MatrixXf : \n" << mymatrix << std::endl;
	
	Eigen::array<int, 1> dims = {2};
	Eigen::Tensor<float, 2> meanT = a.mean<Eigen::array<int, 1>>(dims);
	std::cout << "MEAN on dimension 2: \n" << meanT << std::endl;

	// T3d - T2d = ? 
	Eigen::Tensor<float, 2> b(3, 4);
	b.setConstant(5);
	//std::cout << "T3d - T2d = \n" << a - b << std::endl;
	for (size_t i = 0; i < 2; i++) {
		Eigen::array<INT64, 3> offset2 = { 0, 0, i };
		Eigen::array<INT64, 3> extent2 = { 3, 4, 1 };
		a.slice(offset2, extent2) -= b;
	}
	std::cout << "T3d - T2d = \n" << a  << std::endl;

	return 0;
}