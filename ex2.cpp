#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class ItemSet {
private:
    std::vector<std::string> items;

public:
    // Construtor que recebe um conjunto como parâmetro
    ItemSet(const ItemSet& other) {
        items = other.items;
    }

    // Sobrecarga do operador de atribuição (=)
    ItemSet& operator=(const ItemSet& other) {
        if (this != &other) {
            items = other.items;
        }
        return *this;
    }

    // Sobrecarga do operador de união (+)
    ItemSet operator+(const ItemSet& other) const {
        ItemSet result(*this); // Cria uma cópia do conjunto atual

        for (const std::string& item : other.items) {
            result.inserir(item);
        }

        return result;
    }

    // Sobrecarga do operador de intersecção (*)
    ItemSet operator*(const ItemSet& other) const {
        ItemSet result;

        for (const std::string& item : items) {
            if (other.contem(item)) {
                result.inserir(item);
            }
        }

        return result;
    }

    // Sobrecarga do operador de diferença (-)
    ItemSet operator-(const ItemSet& other) const {
        ItemSet result;

        for (const std::string& item : items) {
            if (!other.contem(item)) {
                result.inserir(item);
            }
        }

        return result;
    }

    // Sobrecarga do operador de delta (<>)
    ItemSet operator<>(const ItemSet& other) const {
        ItemSet result;

        for (const std::string& item : items) {
            if (!other.contem(item)) {
                result.inserir(item);
            }
        }

        for (const std::string& item : other.items) {
            if (!contem(item)) {
                result.inserir(item);
            }
        }

        return result;
    }

    // Sobrecarga do operador de igualdade (==)
    bool operator==(const ItemSet& other) const {
        return items == other.items;
    }

    // Método para inserir um item no conjunto, caso ele não exista.
    void inserir(const std::string& s) {
        if (!contem(s)) {
            items.push_back(s);
        }
    }

    // Método para verificar se um item está no conjunto.
    bool contem(const std::string& s) const {
        return std::find(items.begin(), items.end(), s) != items.end();
    }

    // Método para imprimir os itens do conjunto.
    void imprimir() const {
        std::cout << "Itens no conjunto:" << std::endl;
        for (const std::string& item : items) {
            std::cout << item << std::endl;
        }
    }
};

int main() {
    ItemSet A, B, C;

    A.inserir("item1");
    A.inserir("item2");
    A.inserir("item3");

    B.inserir("item2");
    B.inserir("item3");
    B.inserir("item4");

    C.inserir("item3");
    C.inserir("item5");

    ItemSet D = B + C; // União de B e C
    D.imprimir();

    ItemSet E = B * C; // Intersecção de B e C
    E.imprimir();

    ItemSet F = B - C; // Diferença entre B e C
    F.imprimir();

    ItemSet G = B <> C; // Delta entre B e C
    G.imprimir();

    if (A == B) {
        std::cout << "A é igual a B." << std::endl;
    } else {
        std::cout << "A não é igual a B." << std::endl;
    }

    return 0;
}
