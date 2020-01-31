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
	cout << "Behind door number " << reveal_door << " is a goat" << endl;
	
	//switching doors?
	cout << "Would you want to switch door ? [ (y)es or (n)o ]" << endl;
	char user_bool;
	cin >> user_bool;
	if (user_bool == 'y') {
		cout << "Choose between the 2 remaining door" << endl;
		cin >> user_choice;
	}

	// Revealing the result of the deal.
	if (user_choice != winning_door) {
		cout << "Omae Wa Mou Shindeiru !!!" << endl;
	}
	else {
		int prize = range2(engine);
		if (prize == 1) {
			cout << "Your have won a Titan RTX graphic card!!!" << 
				"A powerful and expensive graphic card with 24Gb of video memory DDR6 and boost clock of 24Mhz" << endl;
		}
		else if (prize == 2) {
			cout << "You have won a Ryzen 7 3700x CPU "<< 
				"Multicore processor with 8 cores and 16 threads with base clock speed at 3.6GHz"<< 
				"and boost clock at 4.4GHz more than enough power" << 
				"to render any video and way over kill for any games that you might play."<< endl;
		}
		else if (prize == 3) {
			cout << "You have won a Ticket to Comic Con 2020: San Diego" << 
				"A wonderful convention if you are a fan of comics. Meet other people with the same interest as well as their special guests"
				<<"partake in amazing activities" << endl;
		}
		else if (prize == 4) {
			cout << "Enjoy Monster Hunter World and Iceborn DLC"<< 
				"A great MMORPG	game where you can hunt monster and carve them for parts and make weapons."<< 
				"The DLC contain exclusive monsters as well as weapons and armor."
				"Once you have some interest in the game, you will be hooked into the never ending grind and have no life." 
				"So say goodbye to your social life and enjoy the content"<< endl;
		}
		else {
			cout << "You have won a RX 5600xt GPU" <<
				"A beefy graphic card that with 6GB of video memory DDR6 and a base clock of 1413MHz."<< 
			 	"A budget friendly and amazing perfomance compare to their counter parts NVidia overprice products." << endl;
		}
	}
}
