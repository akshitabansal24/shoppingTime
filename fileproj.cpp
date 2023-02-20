#include <bits/stdc++.h>
#include <cstring>
#include <unordered_map>
#include <stdio.h>

using namespace std;

class customer
{
	int a, b, cust_phone;
	int i;

public:
	int cust_id;
	string cust_name;
	string cust_address;

public:
	customer(){};
	customer(vector<string> content)
	{
		this->cust_id = stoi(content[0]);
		this->cust_name = content[1];
		this->cust_address = content[2];
		this->cust_phone = stoi(content[3]);
	};

	void addCustomer()

	{
		cout << "Customer ID :\n";
		cout << "Customer Name :\n";
		cout << "Customer Address :\n";
		cout << "Customer Phone number :\n";
		cin >> cust_id;
		cin >> cust_name;
		cin >> cust_address;
		cin >> cust_phone;
	}

	void displayCustomer()
	{
		cout << "\n\n";

		cout << "Customer ID :" << cust_id << endl;
		cout << "Customer Name :" << cust_name << endl;
		cout << "Customer Address :" << cust_address << endl;
		cout << "Customer Phone number :" << cust_phone << endl;
	}

	void writeCustomer()
	{
		fstream f1;
		f1.open("customer.csv", ios::app);
		f1.seekp(0, ios::end);
		f1 << this->cust_id << ","
		   << this->cust_name << ","
		   << this->cust_address << ","
		   << this->cust_phone << endl;
		f1.close();
	}
};

class product
{
	int a, b, product_phone;
	int i;

public:
	int product_id;
	string product_name;
	string product_desc;
	int product_stock;
	float product_price;

public:
	product(){};
	product(vector<string> content)
	{
		this->product_id = stoi(content[0]);
		this->product_name = content[1];
		this->product_desc = content[2];
		this->product_stock = stoi(content[3]);
		this->product_price = stof(content[4]);
	};

	void addProduct()

	{
		cout << "Product ID:\n";
		cout << "Product Name :\n";
		cout << "Product Description :\n";
		cout << "Product Stock :\n";
		cout << "Product Price :\n";
		cin >> product_id;
		cin >> product_name;
		cin >> product_desc;
		cin >> product_stock;
		cin >> product_price;
	}

	void displayProduct()
	{
		cout << "\n\n";

		cout << "Product ID :" << product_id << endl;
		cout << "Product Name :" << product_name << endl;
		cout << "Product Description :" << product_desc << endl;
		cout << "Product Stock :" << product_stock << endl;
		cout << "Product Price :" << product_price << endl;
	}

	void writeProduct()
	{
		fstream f1;
		f1.open("product.csv", ios::app);
		f1.seekp(0, ios::end);
		f1 << this->product_id << ","
		   << this->product_name << ","
		   << this->product_desc << ","
		   << this->product_stock << ","
		   << this->product_price << endl;
		f1.close();
	}
};

unordered_map<int, customer> customers;
unordered_map<int, product> products;

void readCustomers()
{
	customer c;
	ifstream f1;
	f1.open("customer.csv", ios::in);
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
	while (getline(f1, line))
	{
		row.clear();
		stringstream str(line);
		while (getline(str, word, ','))
			row.push_back(word);
		content.push_back(row);
	}

	for (int i = 1; i < content.size(); i++)
	{
		customer c(content[i]);
		customers[c.cust_id] = c;
	}
	f1.close();
}

customer searchCustomers()
{
	readCustomers();
	int rn;
	char found = 'n';
	cout << "\n\n Enter Customer ID you want to searchCustomers :";
	cin >> rn;
	if (customers.find(rn) == customers.end())
		cout << "\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"
			 << endl;
	else
	{
		return customers[rn];
	}
}

void updateCustomer()
{
	customer c = searchCustomers();
	c.addCustomer();
	customers[c.cust_id] = c;
	remove("customer.csv");
	fstream f1;
	cout << "\n";
	f1.open("customer.csv", ios::app);
	f1 << "cust_id"
	   << ","
	   << "cust_name"
	   << ","
	   << "cust_address"
	   << ","
	   << "cust_phone" << endl;
	for (auto i = customers.begin(); i != customers.end(); i++)
		i->second.writeCustomer();
	f1.close();
}

void deleteCustomer()
{
	customer c = searchCustomers();
	remove("customer.csv");
	customers.erase(c.cust_id);
	fstream f1;
	f1.open("customer.csv", ios::app);
	f1 << "cust_id"
	   << ","
	   << "cust_name"
	   << ","
	   << "cust_address"
	   << ","
	   << "cust_phone" << endl;
	for (auto i = customers.begin(); i != customers.end(); i++)
		i->second.writeCustomer();
	f1.close();
}

void readProducts()
{
	product p;
	ifstream f1;
	f1.open("product.csv", ios::in);
	vector<vector<string>> content;
	vector<string> row;
	string line, word;
	while (getline(f1, line))
	{
		row.clear();
		stringstream str(line);
		while (getline(str, word, ','))
			row.push_back(word);
		content.push_back(row);
	}

	for (int i = 1; i < content.size(); i++)
	{
		product p(content[i]);
		products[p.product_id] = p;
	}
	f1.close();
}

product searchProducts()
{
	readProducts();
	int rn;
	char found = 'n';
	cout << "\n\n Enter Product ID you want to searchProducts :";
	cin >> rn;
	if (products.find(rn) == products.end())
		cout << "\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"
			 << endl;
	else
	{
		return products[rn];
	}
}

void updateProduct()
{
	product p = searchProducts();
	p.addProduct();
	products[p.product_id] = p;
	remove("product.csv");
	fstream f1;
	cout << "\n";
	f1.open("product.csv", ios::app);
	f1 << "product_id"
	   << ","
	   << "product_name"
	   << ","
	   << "product_address"
	   << ","
	   << "product_phone" << endl;
	for (auto i = products.begin(); i != products.end(); i++)
		i->second.writeProduct();
	f1.close();
}

void deleteProduct()
{
	product c = searchProducts();
	remove("product.csv");
	products.erase(c.product_id);
	fstream f1;
	f1.open("product.csv", ios::app);
	f1 << "product_id"
	   << ","
	   << "product_name"
	   << ","
	   << "product_desc"
	   << ","
	   << "product_stock"
	   << ","
	   << "product_price" << endl;
	for (auto i = products.begin(); i != products.end(); i++)
		i->second.writeProduct();
	f1.close();
}

void customerMenu()
{
	cout << "Press" << endl;
	cout << "1 to enter new customer" << endl;
	cout << "2 to read all customer data" << endl;
	cout << "3 to search a customer" << endl;
	cout << "4 to update existing customer data" << endl;
	cout << "5 to delete existing customer data" << endl;
	cout << "6 to return to main menu" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		customer cust;
		cust.addCustomer();
		cust.writeCustomer();
		break;
	}
	case 2:
	{
		readCustomers();
		for (auto i = customers.begin(); i != customers.end(); i++)
		{
			i->second.displayCustomer();
		}
		break;
	}
	case 3:
	{
		searchCustomers().displayCustomer();
		break;
	}
	case 4:
	{
		updateCustomer();
		break;
	}
	case 5:
	{
		deleteCustomer();
		break;
	}
	case 6:
	{
		return;
	}
	default:
	{
		cout << "Enter valid choice";
		break;
	}
	}
}

void productMenu()
{
	cout << "Press" << endl;
	cout << "1 to enter new product" << endl;
	cout << "2 to read all product data" << endl;
	cout << "3 to search a product" << endl;
	cout << "4 to update existing product data" << endl;
	cout << "5 to delete existing product data" << endl;
	cout << "6 to return to main menu" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		product p;
		p.addProduct();
		p.writeProduct();
		break;
	}
	case 2:
	{
		readProducts();
		for (auto i = products.begin(); i != products.end(); i++)
		{
			i->second.displayProduct();
		}
		break;
	}
	case 3:
	{
		searchProducts().displayProduct();
		break;
	}
	case 4:
	{
		updateProduct();
		break;
	}
	case 5:
	{
		deleteProduct();
		break;
	}
	case 6:
	{
		return;
	}
	default:
	{
		cout << "Enter valid choice";
		break;
	}
	}
}

void orderMenu()
{
	cout << "Press" << endl;
	cout << "1 to enter new order" << endl;
	cout << "2 to show all order data" << endl;
	cout << "3 to search an order" << endl;
	cout << "4 to return to main menu" << endl;
	int choice;
	cin >> choice;
}

int main()
{
	int choose;
	do{
		cout<<"Press"<<endl;
		cout<<"1 for Customer Menu:"<<endl;
		cout<<"2 for Product Menu:"<<endl;
		cout<<"9 to EXIT:"<<endl;
		cin>>choose;
		switch(choose){
			case 1:{
				customerMenu();
				break;
			}
			case 2:{
				productMenu();
				break;
			}
			case 3:{
				orderMenu();
				break;
			}
			case 9:{
				return 0;
			}
			default:{
				cout<<"ENTER VALID CHOICE:"<<endl;
				break;
			}
		}
	}
	while(choose!=9);
}