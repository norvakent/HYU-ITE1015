#include <iostream>

struct Product {
  std::string name;
  int price, stock, status;
};

int findProductIndex(Product inventory[], int size, std::string targetName) {
  for (int i = 0; i < size; i++) {
    if (inventory[i].name == targetName) return i;
  }
  return -1;
}

int processSale(Product &product, int quantity) {
  if (quantity > product.stock) product.status = 2;
  else {
    product.stock -= quantity;
    product.status = 1;
  }
  return product.status;
}

bool restockProduct(Product &product, int quantity) {
  product.stock += quantity;
  product.status = 1;
  return true;
}


void printProductStatus(Product product) {
  if (product.status == 3) {
    std::cout << "Product '" << product.name << "' not found.\n";
    return;
  }
  else if (product.status == 2) {
    std::cout << "Insufficient stock for " << product.name << " (Current stock: )" << product.stock << ")\n";
    return;
  }
  else {
    int totalValue = product.price * product.stock;
    std::cout << "Current Stock: " << product.stock << "\n";
    std::cout << "Total Inventory Value: " << totalValue << " KRW\n";
  }
}

int main() {
  const int NUM_PRODUCTS = 5;
  Product inventory[NUM_PRODUCTS] = {
    {"Notebook", 1500000, 20, 1},
    {"Mouse", 50000, 100, 1},
    {"Keyboard", 120000, 50, 1},
    {"Monitor", 350000, 30, 1},
    {"Webcam", 80000, 40, 1}
  };

  std::string command, targetName;
  int quantity;
  std::cin >> command >> targetName >> quantity;
  int idx = findProductIndex(inventory, NUM_PRODUCTS, targetName);

  if (idx == -1) {
    Product temp = {targetName, 0, 0, 3};
    printProductStatus(temp);
    return 1;
  }

  if (command == "sale") {
    processSale(inventory[idx], quantity);
    printProductStatus(inventory[idx]);
  } else if (command == "restock") {
    restockProduct(inventory[idx], quantity);
    printProductStatus(inventory[idx]);
  } else if (command == "check") {
    inventory[idx].status = 1;
    printProductStatus(inventory[idx]);
  }
  return 0;
}