#include <iostream>
#include <string>

using namespace std;

// Функція для імплікації
bool implication(bool p, bool q) {
    return !p || q;
}


// Функція для еквівалентності
bool equivalence(bool p, bool q) {
    return implication(p, q) && implication(q, p);
}

// Нова функція для порозрядних операцій OR, AND, XOR
void bitwise_operations(const string& a, const string& b, string& or_result, string& and_result, string& xor_result) {
    int n = a.length();  // Довжина рядків
    or_result = "";
    and_result = "";
    xor_result = "";

    for (int i = 0; i < n; ++i) {
        // Операція OR
        if (a[i] == '1' || b[i] == '1') {
            or_result += '1';
        }
        else {
            or_result += '0';
        }

        // Операція AND
        if (a[i] == '1' && b[i] == '1') {
            and_result += '1';
        }
        else {
            and_result += '0';
        }

        // Операція XOR
        if (a[i] != b[i]) {
            xor_result += '1';
        }
        else {
            xor_result += '0';
        }
    }
}

int main() {
    setlocale(LC_ALL, "UKR");

    bool p, q;

    // Введення значень істинності p і q
    cout << "Введiть значення p (0 або 1): ";
    cin >> p;
    cout << "Введiть значення q (0 або 1): ";
    cin >> q;

    // Кон'юнкція (AND)
    bool conjunction = p && q;
    cout << "Кон'юнкцiя (p ^ q): " << conjunction << endl;

    // Диз'юнкція (OR)
    bool disjunction = p || q;
    cout << "Диз'юнкцiя (p ⌄ q): " << disjunction << endl;

    // Альтернативне "або" (XOR)
    bool exclusiveOr = p != q;
    cout << "Альтернативне \"або\" (p ⊕ q): " << exclusiveOr << endl;

    // Імплікація p - q
    bool impl_pq = implication(p, q);
    cout << "Iмплiкацiя (p -> q): " << impl_pq << endl;

    // Еквівалентність (p ~ q)
    bool equiv = equivalence(p, q);
    cout << "Еквiвалентнiсть (p ~ q): " << equiv << endl;

    // Задаємо два бітові рядки довжиною 8
    string a, b;
    cout << "\nВведiть перший бiтовий рядок (8 символiв): ";
    cin >> a;
    cout << "Введiть другий бiтовий рядок (8 символiв): ";
    cin >> b;

    // Перевірка чи рядки мають однакову довжину і рівну 8
    if (a.length() != 8 || b.length() != 8) {
        cout << "Помилка: Рядки повиннi бути точно 8 символiв" << endl;
        return 1;
    }

    string or_result, and_result, xor_result;
    bitwise_operations(a, b, or_result, and_result, xor_result);

    // Виведення результатів
    cout << "Результат OR:  " << or_result << endl;
    cout << "Результат AND: " << and_result << endl;
    cout << "Результат XOR: " << xor_result << endl;

    return 0;
}
