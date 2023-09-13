#include <iostream>
#include <vector>
#include <string>

class ItemSet {
private:
    std::vector<std::string> items;

public:
    // Método para inserir um item no conjunto, caso ele não exista.
    void inserir(const std::string& s) {
        bool itemJaExiste = false;
        for (const std::string& item : items) {
            if (item == s) {
                itemJaExiste = true;
                break;
            }
        }

        if (!itemJaExiste) {
            items.push_back(s);
            std::cout << "Item '" << s << "' inserido no conjunto." << std::endl;
        } else {
            std::cout << "Item '" << s << "' já existe no conjunto." << std::endl;
        }
    }

    // Método para excluir um item do conjunto, caso ele exista.
    void excluir(const std::string& s) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == s) {
                items.erase(it);
                std::cout << "Item '" << s << "' excluído do conjunto." << std::endl;
                return;
            }
        }
        std::cout << "Item '" << s << "' não encontrado no conjunto." << std::endl;
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
    ItemSet conjunto;

    conjunto.inserir("item1");
    conjunto.inserir("item2");
    conjunto.inserir("item1"); // Tentando inserir um item já existente
    conjunto.inserir("item3");

    conjunto.imprimir();

    conjunto.excluir("item2");
    conjunto.excluir("item4"); // Tentando excluir um item que não existe

    conjunto.imprimir();

    return 0;
}
