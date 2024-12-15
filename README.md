- By Tristen Martin and Matt Nokes

The Tennessee Tech Parking Lot Manager is a program that allows the user to do the following:
	- **Create virtual parking lots** 
	- **View cars in a parking lot**
	- **Add cars to a parking lot**
	- **Remove a car from a parking lot**
	- **Sort cars in a parking lot using a Quicksort algorithm**

- **Classes**
	- **Car class:**
		- Contains car attributes: license plate, make, and model.
		- Contains a getter function for each attribute
		- Also contains an overload function which prints the car attributes
	- **ParkingLot class:**
		- The ParkingLot class stores a collection of cars using a custom smart pointer
	- **SmartPointer class:**
		- The Smartpointer is a custom pointer that manages Car objects
		- Contains a pointer to the object
		- Uses a constructor, copy constructor, copy assignment operator,  destructor, and overload operators used to print the objects
	- **LinkedList class:**
		- Mainly used  to manage the new ParkingLot and Car objects
