#include <iostream>
#include <vector>
#include <array>

template <typename T>
T mean_vector(std::vector <T> vector)
{
    T sum {};
    for (auto &elem: vector)
    { sum = sum + elem; }

    return sum/vector.size();
}

template <typename T>
double mean_array(std::array <T,5> array)
{
    double sum = 0;

    for (auto &elem: array) { sum += elem; }

    return sum/array.size();
}

template<typename T>
std::array<double,2> mean_class(std::array <T,3> array)
{
    std::array<double,2> sum_xy = {0,0};

    for (auto &elem: array)
    {
        sum_xy[0] += elem.x;
        sum_xy[1] += elem.y;
    }
    sum_xy[0] /= array.size();
    sum_xy[1] /= array.size();

    return sum_xy;
}

template<typename T>
class plane_point
{
public:

    T x, y;

    plane_point& operator+(const plane_point& other)
    {
        this ->x += other.x;
        this ->y += other.y;
    }
    plane_point& operator/(const int& size)
    {
        this ->x /= size;
        this ->y /= size;
    }


    ~plane_point() = default;

};

int main()
{
    std::vector <float> float_vector = {1.12, 2.2359323, 3.57};
    std::vector <int> int_vector = {1, 2, 3};

    std::cout << "Arithmetic mean of a vector of float-type numbers: " << mean_vector(float_vector) << std::endl;
    std::cout << "Arithmetic mean of a vector of int-type numbers: " << mean_vector(int_vector) << std::endl;


    std::array <int, 5> int_array = {1, 2, 3, 4, 5};
    std::array <float, 5> float_array = {1.5, 2.1, 3.2, 4.6, 5.87};

    std::cout << "\n" << "Arithmetic mean of an array of int-type numbers: " << mean_array(int_array) << std::endl;
    std::cout << "Arithmetic mean of an array of float-type numbers: " << mean_array(float_array) << std::endl;


    plane_point<int> point_1, point_2, point_3;
    point_1.x = 1;
    point_1.y = 2;

    point_2.x = 50;
    point_2.y = -412;

    point_3.x = -20;
    point_3.y = -7;
    std::vector <plane_point<int>> class_array = {point_1, point_2, point_3};
    std::cout << "Arithmetic mean of a vector of point-type numbers: " << std::endl;
    std::cout <<  mean_vector(class_array).x << " " << mean_vector(class_array).y << std::endl;

    /*
    std::array <plane_point<int>, 3> class_array = {point_1, point_2, point_3};
    std::cout << "\n" << "Arithmetic mean of points x: " << mean_class(class_array)[0] << std::endl;
    std::cout << "Arithmetic mean of points y: " << mean_class(class_array)[1] << std::endl;
    */


    return 0;
}
