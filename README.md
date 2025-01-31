Problem Description

Design and implement a thread-safe singleton class in C++. The singleton pattern ensures that only one instance of a class is created and provides a global access point to that instance. The implementation must be efficient and thread-safe, ensuring that multiple threads cannot create separate instances of the singleton.


Implement a class Singleton with the following constraints:
	1.	Instance Retrieval
	•	Implement a method static Singleton* getInstance() that returns a pointer to the single instance of the class.
	•	If the instance does not exist, it should be created in a thread-safe manner.
	2.	Thread-Safety
	•	The class should ensure only one instance is created, even if multiple threads access getInstance() simultaneously.
	3.	Memory Management
	•	The singleton instance should be properly deleted when the program terminates to avoid memory leaks.
	4.	Performance Optimization (Follow-Up)
	•	Optimize the implementation to avoid unnecessary locking once the instance is created.