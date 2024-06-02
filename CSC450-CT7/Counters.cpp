#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//Creates object for mutex
mutex mtx;

//Creates a function to increase the number
void countUp() {
	for (int i = 1; i <= 20; ++i) {
		lock_guard<mutex> lock(mtx); //Locking the thread
		cout << "First Thread (Count up): " << i << endl;
	}
}

//Creates a function to decrease the number
void countDown() {
	for (int i = 20; i >= 0; --i) {
		lock_guard<mutex> lock(mtx); //Locking the thread
		cout << "Second Thread (Count down): " << i << endl;
	}
}

int main() {

	string input;

	//Prompts the user to type "begin" to start program
	cout << "Type 'begin' to run the program: ";
	cin >> input;

	// Check if the input matches "begin" and if not exits the program
	if (input == "begin") {
		cout << "Program started!" << endl;
	} else {
		cout << "Not a valid input, exiting the program." << endl;
		exit(EXIT_FAILURE);
	}

	//Creates threads to perform increment increase and decrease respectfully
	thread t1(countUp);
	thread t2(countDown);

	//.join allows both threads to start at the same time
	t1.join();
	t2.join();

	//Ending message to state the program is done
	cout << "Program has ended." << endl;

	return 0;
}
