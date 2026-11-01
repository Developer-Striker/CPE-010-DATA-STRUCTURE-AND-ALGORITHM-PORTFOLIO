#include <iostream>
#include <string.h>

class Grocery {
    private:
        std::string name;
        double price;
        int quantity;
    public:
        Grocery(std::string itemName = "Unknown", double itemPrice = 0.0, int itemQuantity = 0){
            name = std::move(itemName);
            price = itemPrice;
            quantity = itemQuantity;
            std::cout << "Constructor Called." << std::endl;
        }
        virtual ~Grocery(){
            std::cout << "Destructor called." << std::endl;
        }
        Grocery(const Grocery &copyGrocery){
            std::cout << "Copy Constructor Called." << std::endl;\
            name = copyGrocery.name;
            price = copyGrocery.price;
            quantity = copyGrocery.quantity;
        }

        double calculateSum() const {
            return price * quantity;
        }

        std::string getName() const {
            return name;
        }

        virtual void printDetails() const {
            std::cout << "Name: " << this->name << " | Price: PHP " << this->price
                      << " | Quantity: " << this ->quantity << " | Subtotal: PHP " 
                      << this->calculateSum() << std::endl;
        }
};

class Fruit : public Grocery {
    public:
        Fruit(std::string itemName, double itemPrice, int itemQuantity) 
        : Grocery(itemName, itemPrice, itemQuantity) {}
    
        ~Fruit() override {}

        void printDetails() const override {
            std::cout << "[Fruit]\t\t";
            Grocery::printDetails();
        }
};

class Vegetable : public Grocery {
    public:
    Vegetable(std::string itemName, double itemPrice, int itemQuantity)
    : Grocery(itemName, itemPrice, itemQuantity) {}

    ~Vegetable() override {}

    void printDetails() const override {
        std::cout << "[Vegetable]\t";
        Grocery::printDetails();
    }
};

double totalSum(Grocery* list[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        if(list[i] != nullptr) {
            total += list[i]->calculateSum();
        }
    }
    return total;
};

int main() {

    const size_t j = 4;

    Grocery* groceryList[j] = {nullptr};

    std::string nameList[j] = {"Apple", "Banana", "Brocolli", "Lettuce"};
    double priceList[j] = {10.0, 10.0, 60.0, 50.0};
    int quantityList[j] = {7, 8, 12, 10};

    for (int i = 0; i < j; i++) {
        if (i < 2) {
            groceryList[i] = new Fruit(nameList[i], priceList[i], quantityList[i]);
        } else {
            groceryList[i] = new Vegetable(nameList[i], priceList[i], quantityList[i]);
        }
    }

    std::cout << "\n\t\t|--- Jenna's Grocery List ---|\n" << std::endl;
    for (int i = 0; i < j; i++){
        groceryList[i]->printDetails();
    }

    double totalCost = totalSum(groceryList, j);
    std::cout << "\n Total Amount to Pay: PHP " << totalCost << "\n\n";


    std::cout << "--- Problem 4: Deleting Lettuce ---" << std::endl;
    for(int i = 0; i < j; i++) {
        if(groceryList[i] != nullptr && groceryList[i]->getName() == "Lettuce") {
            delete groceryList[i];
            groceryList[i] = nullptr;
            break;
        }
    }

    for (int i = 0; i < j; i++) {
        if (groceryList[i] != nullptr) {
            groceryList[i]-> printDetails();
        }else {
            std::cout << "[Empty Slot] Element at index " << i << "was deleted." <<std::endl;
        }
    }

    for (int i = 0; i < j; i++) {
        delete groceryList[i];
    }
    
    return 0;
}