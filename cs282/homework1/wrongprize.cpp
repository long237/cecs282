#include <iostream>
#include <iomanip> 
#include <random>
using namespace std;

int main(int argc, char* argv[]) {

	//creating random_device.
	random_device rd{};
	// create a random engine.
	default_random_engine engine{ rd() };

	//creating different distribution (inclusive parameters).
	uniform_int_distribution<int> range{ 1, 3};
	uniform_int_distribution<int> range2{ 1, 5};
	
	int winning_door = range(engine);
	
	cout << "Choose a door here (1-3):" << endl;
	int user_choice;
	cin >> user_choice;

	int reveal_door = user_choice;
	while (reveal_door == user_choice && reveal_door == winning_door){ 
		reveal_door = range(engine);
	}		
	
	//revealing the door
	cout << "Behind door number" << reveal_door << "is a goat" << endl;
	
	//switching doors?
	cout << "Would you want to switch door ? [ (y)es or (n)o ]" << endl;
	char user_bool;
	cin >> user_bool;
	if (user_bool == 'y') {
		cin >> user_choice;
	}

	// Revealing the result of the deal.
	if (user_choice != winning_door) {
		cout << "Omae Wa Mou Shindeiru" << endl;
	}
	else {
		int prize = range2(engine);
		if (prize == 1) {
			cout << "put a 1st prize here" << endl;
		}
		else if (prize == 2) {
			cout << "put a 2nd prize here" << endl;
		}
		else if (prize == 3) {
			cout << "put a 3rd prize here" << endl;
		}
		else if (prize == 4) {
			cout << "put a 4th prize here" << endl;
		}
		else (prize == 5) {
			cout << "put a 5th prize here" << endl;
		}
}
