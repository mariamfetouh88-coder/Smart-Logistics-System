# 📦 Smart Logistics & Order Routing System

A robust, pure C++ enterprise-grade simulation designed to model modern supply chain and logistics operations. This project showcases the practical application of Core Data Structures implemented entirely from scratch, without relying on the C++ Standard Template Library (STL).

---

## 🛠️ Data Structures Implemented From Scratch

To master pointer manipulation and memory management, every data structure used in this system was built manually:

* **Queue (FIFO - First In, First Out):** Powering the incoming cargo terminal to manage and process shipments in the exact order they arrive.
* **Stack (LIFO - Last In, First Out):** Simulating real-world truck loading mechanics where the last package loaded onto the cargo stack is the first one unloaded at delivery.
* **Singly Linked List:** Dynamically managing and displaying the sequential transit routes and delivery stations.
* **Binary Search Tree (BST):** Serving as a high-speed tracking index, enabling instant order lookups by unique ID with $O(\log n)$ time complexity.

---

## 🚀 Key Features

* **Batch Order Creation (Enhanced UX):** Allows users to dynamically register and enqueue multiple orders at once in a single flow.
* **Pure Object-Oriented Architecture (OOP):** Built with clean, decoupled structures for `Order`, `Node`, and custom data container classes.
* **Dynamic Status Tracking:** Orders seamlessly transit through lifecycle states: `Pending` ➡️ `In Transit` ➡️ `Delivered`.
* **Manual Memory Management:** Strict usage of pointers and manual node deletions (`delete`) to ensure zero memory leaks.

---

## 💻 How It Works (The Core Logic)

1. **Incoming Terminal:** Orders are accepted and pushed into the `IncomingOrdersQueue`. Simultaneously, a pointer to the order is indexed inside the `OrderTrackingBST`.
2. **Cargo Loading:** Dispatched orders are popped from the Queue and pushed onto the `TruckLoadingStack`, shifting their status to *In Transit*.
3. **Last-Mile Delivery:** The truck unloads cargo from the top of the Stack, marking the shipment as *Delivered*.
4. **Instant Lookup:** Managers can query the BST with an Order ID at any time to instantly inspect its current location and delivery status.
