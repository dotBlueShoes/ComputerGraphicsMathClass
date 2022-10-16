#include "Framework.hpp"

// TODO
// Zaimplementuj klasę wektor wraz ze wszystkimi działaniami.
// Sprawdź czy prawidłowo działa przemienność dodawania za pomocą odpowiedniego zdefiniowania przykładowych wektorów i ich sumy w funkcji main().
// 
// Znajdź kąt pomiędzy wektorem[0, 3, 0] a[5, 5, 0]
// 
// Znajdź wektor prostopadły do wektorów[4, 5, 1] i[4, 1, 3]
// 
// Znormalizuj powstały wektor
//

template <class T>
struct Vector2 {
	T x, y;
};

ErrorType function() {
	return ErrorCode::Success;
}

int main() {
	Vector2<float> sample { 0, 0 };
	return (int)(ErrorCode::Success);
}