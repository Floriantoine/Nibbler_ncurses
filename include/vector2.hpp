/*
** EPITECH PROJECT, 2020
** JAM_streetart_2019
** File description:
** Vector2
*/

#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

template <typename T>
class Vector2 {
  public:
    Vector2();
    Vector2(T X, T Y);

    T x; ///< X coordinate of the vector
    T y; ///< Y coordinate of the vector
};

template <typename T>
Vector2<T>::Vector2() : x{0}, y{0}
{
}

template <typename T>
Vector2<T>::Vector2(T x, T y) : x{x}, y{y}
{
}

template <typename T>
Vector2<T> operator-(const Vector2<T>& right)
{
    return {-right.x, -right.y};
}

template <typename T>
Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

template <typename T>
Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

template <typename T>
Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
{
    return {left.x + right.x, left.y + right.y};
}

template <typename T>
Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
{
    return {left.x - right.x, left.y - right.y};
}

template <typename T>
bool operator==(const Vector2<T>& left, const Vector2<T>& right)
{
    return left.x == right.x && left.y == right.y;
}

template <typename T>
bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
{
    return !(left == right);
}

template <typename T>
bool operator<(const Vector2<T>& left, const Vector2<T>& right)
{
    return left.x < right.x && left.y < right.y;
}

template <typename T>
bool operator<=(const Vector2<T>& left, const Vector2<T>& right)
{
    return left.x <= right.x && left.y <= right.y;
}

// Define the most common types
using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned int>;
using Vector2f = Vector2<float>;

#endif /* !VECTOR2_HPP_ */

