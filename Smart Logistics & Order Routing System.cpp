#include <iostream>
#include<string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    string destination;
    string status;

    Order(int id, string name, string dest) {
        orderID = id;
        customerName = name;
        destination = dest;
        status = "Pending";
    }
    void displayOrder() {
        cout << "Order ID : " << orderID << " , Customer name : " << customerName << " , Destination : " << destination << " , Status : " << status << " . \n";
    }
};
class Node {
public:
    Order* orderData;
    Node* next;
    Node(Order* neworder) {
        orderData = neworder;
        next = NULL;
    }
};

class IncomingOrdersQueue {
    Node* front;
    Node* rear;

public:
    IncomingOrdersQueue() {
        front = rear = NULL;
    }
    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }
    void Enqueue(Order* item) {
        Node* newnode = new Node(item);
        if (isEmpty()) {
            front = rear = newnode;
            return;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }
    Order* Dequeue() {
        Order* order = front->orderData;
        Node* temp = front;
        if (isEmpty())cout << "the queue is empty\n";
        else if (front == rear) {
            delete front;
            front = rear = NULL;
        }
        else {
            front = front->next;
            delete temp;
        }
        return order;
    }
    void Display() {
        if (isEmpty()) {
            cout << "The incoming orders queue is currently empty.\n";
            return;
        }
        else {
            Node* temp = front;
            while (temp != NULL) {
                temp->orderData->displayOrder();
                temp = temp->next;
            }
            cout << endl;
        }
    }

};

class TruckLoadingStack {
    Node* top;

public:
    TruckLoadingStack() {
        top == NULL;
    }
    bool isempty() {
        return (top == NULL);
    }
    void push(Order* order) {
        if (order == NULL)return;
        Node* temp = new Node(order);
        temp->next = top;
        top = temp;
        order->status = "In Transit";
    }
    Order* pop() {
        if (isempty())return NULL;
        Node* temp = top;
        Order* order = top->orderData;
        top = top->next;
        delete temp;
        order->status = "Delivered";
        return order;
    }
    void displayTruck() {
        if (isempty()) {
            cout << "The truck is empty. No cargo loaded yet.\n";
            return;
        }
        Node* curr = top;
        while (curr != NULL) {
            curr->orderData->displayOrder();
            curr = curr->next;
        }
        cout << endl;
    }
};

class RouteNode {
public:
    string cityName;
    RouteNode* next;

    RouteNode(string name) {
        cityName = name;
        next = NULL;
    }
};

class DeliveryRouteLinkedList {
    RouteNode* head;
public:
    DeliveryRouteLinkedList() {
        head == NULL;
    }
    void addStation(string cityName) {
        RouteNode* temp = new RouteNode(cityName);
        if (head == NULL) {
            head = temp;
            return;
        }
        RouteNode* curr = head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = temp;
    }
    void printRoute() {
        if (head == NULL) {
            cout << "No delivery route has been defined yet.\n";
            return;
        }
        RouteNode* curr = head;
        cout << "Delivery Route: ";
        while (curr != NULL) {
            cout << curr->cityName;
            if (curr->next != NULL) cout << " ---> ";
            curr = curr->next;
        }
        cout << "\n";
    }
};

class BSTNode {
public:
    Order* orderData;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Order* order) {
        orderData = order;
        left = right = NULL;
    }
};

class OrderTrackingBST {
    BSTNode* root;
    BSTNode* insertHelper(BSTNode* node, Order* order) {
        if (node == NULL)return new BSTNode(order);
        if (order->orderID < node->orderData->orderID) {
            node->left = insertHelper(node->left, order);
        }
        else if (order->orderID > node->orderData->orderID) {
            node->right = insertHelper(node->right, order);
        }
        return node;
    }
    BSTNode* searchHelper(BSTNode* node, int id) {
        if (node == NULL || node->orderData->orderID == id) return node;
        if (id < node->orderData->orderID) return searchHelper(node->left, id);
        return searchHelper(node->right, id);
    }
public:
    OrderTrackingBST() { root = NULL; }

    void insert(Order* order) { root = insertHelper(root, order); }

    void search(int id) {
        BSTNode* res = searchHelper(root, id);
        if (res == NULL) {
            cout << "Sorry, no order was found with ID: " << id << "\n";
        }
        else {
            cout << "Order tracked successfully:\n";
            res->orderData->displayOrder();
        }
    }

};






int main() {
    IncomingOrdersQueue queue;
    TruckLoadingStack truck;
    DeliveryRouteLinkedList route;
    OrderTrackingBST bst;

    route.addStation("Cairo");
    route.addStation("Benha");
    route.addStation("Tanta");
    route.addStation("Alexandria");

    int choice;
    while (true) {
        cout << "\n=============================================\n";
        cout << " Smart Logistics & Order Routing System \n";
        cout << "=============================================\n";
        cout << "1. Enqueue New Order (Incoming Cargo)\n";
        cout << "2. Display Incoming Queue\n";
        cout << "3. Push Order to Truck (Load Cargo onto Stack)\n";
        cout << "4. Display Truck Stack (Top to Bottom)\n";
        cout << "5. Pop Order from Truck (Deliver Cargo to Client)\n";
        cout << "6. Print Active Delivery Route (Linked List)\n";
        cout << "7. Track Order Instantly by ID (Search BST)\n";
        cout << "8. Exit System\n";
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        if (choice == 1) {
            int numberOfOrders;
            cout << "How many orders do you want to enqueue? ";
            cin >> numberOfOrders;
            for (int i = 0; i < numberOfOrders; i++) {
                cout << "\n--- Entering Details for Order " << (i + 1) << " ---\n";
                int id; string name, dest;
                cout << "Enter unique Order ID: "; cin >> id;
                cout << "Enter Customer Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter Destination City: "; getline(cin, dest);

                Order* newOrder = new Order(id, name, dest);
                queue.Enqueue(newOrder);
                bst.insert(newOrder);
                cout << " Order " << id << " successfully registered and queued\n";
            }
        }
        else if (choice == 2) {
            cout << "\n--- Orders Waiting in Queue ---\n";
            queue.Display();
        }
        else if (choice == 3) {
            if (queue.isEmpty()) {
                cout << "No orders in queue available for loading.\n";
            }
            else {
                Order* order = queue.Dequeue();
                truck.push(order);
                cout << "Order [" << order->orderID << "] moved from Queue and loaded onto the truck\n";
            }
        }
        else if (choice == 4) {
            cout << "\n--- Cargo Stacked Inside the Truck ---\n";
            truck.displayTruck();

        }
        else if (choice == 5) {
            if (truck.isempty()) {
                cout << "The truck is empty. No orders to deliver.\n";
            }
            else {
                Order* deliveredOrder = truck.pop();
                cout << "Order successfully delivered to destination:\n";
                deliveredOrder->displayOrder();
            }
        }
        else if (choice == 6) {
            route.printRoute();

        }
        else if (choice == 7) {
            int searchID;
            cout << "Enter Order ID to track: "; cin >> searchID;
            bst.search(searchID);

        }
        else if (choice == 8) {
            cout << "Thank you for using Smart Logistics System. Goodbye! \n";
            break;
        }
        else {
            cout << "Invalid choice, please try again.\n";
        }

    }
    return 0;
}

