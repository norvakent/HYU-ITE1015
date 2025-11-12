#include <iostream>
#include <limits>
#include <string>

using namespace std;

#define MAX_PRODUCTS 10

// TODO: Forward Declaration implementation
class Coupon;
class ShoppingCart;

// TODO: implement Product class
class Product {
private:
  string name;
  double price;
  string category;

public:
  Product() : name(""), price(0.0), category("") {}
  Product(string _name, double _price, string _category)
      : name(_name), price(_price), category(_category) {}
  string getName() const { return name; }
  double getPrice() const { return price; }
  friend double applyCoupon(const ShoppingCart &cart, const Coupon &coupon);
};

// TODO: implement Coupon class
class Coupon {
private:
  string targetCategory;
  double discountRate;

public:
  Coupon(string _targetCategory, double _discountRate)
      : targetCategory(_targetCategory), discountRate(_discountRate) {}
  string getTargetCategory() const { return targetCategory; }
  double getDiscountRate() const { return discountRate; }
  friend double applyCoupon(const ShoppingCart &cart, const Coupon &coupon);
};

// TODO: implement ShoppingCart class
class ShoppingCart {
private:
  Product products[MAX_PRODUCTS];
  int productCount;
  double totalPrice;

public:
  ShoppingCart() : productCount(0), totalPrice(0.0) {}
  double getTotalPrice() const { return totalPrice; }
  void addProduct(const Product &product) {
    if (productCount < MAX_PRODUCTS) {
      products[productCount++] = product;
    }
    totalPrice += product.getPrice();
  }
  friend double applyCoupon(const ShoppingCart &cart, const Coupon &coupon);
};

//--- applyCoupon function: External function for processing coupon application
// logic ---
double applyCoupon(const ShoppingCart &cart, const Coupon &coupon) {
  // TODO: Implement logic to return the discount amount after applying the
  // coupon
  //       to the products in the shopping cart.

  double discounts = 0.0;
  for (int i = 0; i < cart.productCount; i++) {
    if (cart.products[i].category == coupon.getTargetCategory()) {
      discounts += cart.products[i].getPrice() * coupon.getDiscountRate();
    }
  }
  return discounts;
}

int main() {
  // === 1. Input product list ===
  cout << "=== Step 1: Product Registration ===" << endl;
  cout << "Enter the number of products to sell: ";
  int numAvailableProducts;
  cin >> numAvailableProducts;

  Product *availableProducts = new Product[numAvailableProducts];

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < numAvailableProducts; ++i) {
    string name, category;
    double price;
    cout << "\n--- Enter details for product #" << i + 1 << " ---" << endl;
    cout << "Name: ";
    getline(cin, name);

    cout << "Price: ";
    cin >> price;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Category: ";
    getline(cin, category);

    availableProducts[i] = Product(name, price, category);
  }

  // === 2. Shopping cart section ===
  cout << "\n=== Step 2: Product Purchase ===" << endl;
  ShoppingCart myCart;

  while (true) {
    cout << "\n--- Available Products ---" << endl;
    for (int i = 0; i < numAvailableProducts; i++) {
      cout << i + 1 << ". " << availableProducts[i].getName() << " ($"
           << availableProducts[i].getPrice() << ")" << endl;
    }
    cout << "0. Checkout" << endl;
    cout << "Enter: ";

    int choice;
    cin >> choice;

    if (choice == 0) {
      break;
    }

    if (choice > 0 && choice <= numAvailableProducts) {
      myCart.addProduct(availableProducts[choice - 1]);
    }
  }

  // === 3. Final payment and coupon input ===
  cout << "\nTotal: $" << myCart.getTotalPrice() << endl;

  string couponCategory;
  double couponRate;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "\nEnter coupon category to apply: ";
  getline(cin, couponCategory);
  cout << "Enter discount rate (e.g., 0.2 for 20%): ";
  cin >> couponRate;

  Coupon userCoupon(couponCategory, couponRate);

  double discountAmount = applyCoupon(myCart, userCoupon);

  if (discountAmount > 0) {
    cout << "Applied " << userCoupon.getDiscountRate() * 100 << "% coupon for "
         << userCoupon.getTargetCategory() << " category (Discount: $"
         << discountAmount << ")" << endl;
  }

  // Calculate final price (total - discount)
  double finalPrice = myCart.getTotalPrice() - discountAmount;

  cout << "Final Price: $" << finalPrice << endl;

  // === 4. Free allocated memory ===
  delete[] availableProducts;

  return 0;
}