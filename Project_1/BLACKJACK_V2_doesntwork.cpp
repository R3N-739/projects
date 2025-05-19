#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <numeric>
#include <cstdlib>
#include <stdexcept>
#include <ctime>

using namespace std;

//CARD STRUCT basic structire for a card
struct Card {
    char Royal; //J, Q, K, A or 0 for numbers
    int value;  //2-10
    string suit;//Hearts, Diamonds, Clubs, Spades

    //Constructor for royal cards (J, Q, K, A)
    Card(char Royal, string suit) : Royal(Royal), suit(suit), value(0) {}

    //Constructor for number cards (2-10)
    Card(int value, string suit) : value(value), suit(suit), Royal('0') {}

    string toString() const {
        //if not royal return value
        if (Royal == '0') return to_string(value) + " of " + suit;

        //if royal return royal letter
        return string(1, Royal) + " of " + suit;
    }
};

//DECK OF CARDS
class Deck {
private:
    stack<Card> cards;  //Stack of cards for deck

    //Generate deck as list before pushing to stack
    void generateDeck() {
        //Temporary deck to shuffle cards into stack
        deque<Card> temp;
        //List of suits
        list<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

        //Loop through suits
        for (const auto& suit : suits) {
            
            //Loop through numbers 2-10
            for (int i = 2; i <= 10; i++) {
                //Add number cards to deck
                temp.push_back({i,suit});
            }

            //Add royal cards to deck
            temp.push_back({'J', suit});
            temp.push_back({'Q', suit});
            temp.push_back({'K', suit});
            temp.push_back({'A', suit});
        }

        //Shuffle deck
        shuffle(temp.begin(), temp.end(), default_random_engine(time(0)));

        //Add Cards to stack
        for (const Card& card: temp){ cards.push(card); }
    }

public:
    //Constructor for deck
    Deck() { generateDeck(); }  //Generate deck on creation

    //Draw a card from te deck
    Card draw() {
        //Generate new deck when empty
        if (cards.empty()) generateDeck();

        //Access top card, save to return
        Card top = cards.top();

        //Pop top card
        cards.pop();

        //Return top card
        return top;
    }

};

//HAND OF CARDS
class Hand {
protected:
    list<Card> cards;   //List of cards in hand
    int total = 0;

public:
    //Add card to hand and add value to total
    void addCard(const Card& card) {
        cards.push_back(card);
        //Modify total
        if (card.Royal == '0') total += card.value; //if not royal add value
        else if (card.Royal == 'A'){    //If Card is an ace
            if (total + 11 > 21) total += 1; //if total + 11 is greater than 21 add 1
            else total += 11; //if total + 11 is less than or equal to 21 add 11
        }
        else total += 10; //Add 10 for royal cards
    }

    //Return total value of hand
    int get_total() const {
        return total;
    }

    //Clear hand (for end of round)
        void clear() {
            cards.clear();
            total = 0; //Reset total to 0
        }
};

//PLAYER CLASS inheriting from Hand
class Player : public Hand {
private:
    string name;       //Player name

public:
    //Constructor for player with name
    Player(string n) : name(n) {}
    
    //Print hand
    void printHand() const {
        cout << name << "'s hand: ";

        //Loop through and print each card
        for (const auto& card : cards) {
            cout << "[" << card.toString() << "] ";
        }
        //Print total value of hand
        cout << " Total: " << total << endl;
    }

    // Accessor
    string getName() const { return name; }
};

//DEALER CLASS inheriting from Hand
class Dealer : public Hand {
    private:
    //Dealers name is always Dealer
        string name = "Dealer";
    
    public:
    //Print hand with hiding first card functionality
    //Does not hide first card by default
        void printHand(bool hideFirst = false) const {
            cout << name << "'s hand: ";

            int i = 0;  //int to count first card, for hiding

            //Loop through and print each card
            for (const auto& card : cards) {
                //If hiding first card = true, print HIDDEN
                //Else orint card normally
                if (hideFirst && i++ == 0) {
                    cout << "[Hidden] ";
                } else {
                    cout << "[" << card.toString() << "] ";
                }
            }
            //IF hiding first card do not print total
            //Else print total value of dealers hand
            if(!hideFirst) {
                cout << ""; //Print hidden card
            } else { 
                cout << " Total: " + to_string(get_total());
            }
            cout << endl;
        }
};

//TURN ORDER CLASS to control turn order for more players
class TurnOrder {};

//BANK CLASS to manage money
class Bank {
    private: 
    map<string, int> balances; //Map <player name, balance>

    public:

    //Open "account" for new player
    void addAccount(const string& name, int money) {
        balances[name] = money;
    }

    //Deposit money to player account
    void deposit(const string& name, int amount) {
        balances[name] += amount; //Add amount to player balance
    }

    //Withdraw money from player account
    void withdraw(const string& name, int amount) {
        //If player has enough money withdraw amount
        //Else print insufficient funds message
        if (balances[name] >= amount) {
            balances[name] -= amount; //Subtract amount from balance
        } else {
            throw runtime_error("Insufficient funds for " + name);
        }
    }

    //Get player balance
    int getBalance(const string& name) const {
        auto balance = balances.find(name); //Find player balance in map
        //If found return balance amount
        if (balance == balances.end()){
            throw invalid_argument("No balance found for " + name);
        } else {
            return balance->second;
        }
    }

    //Print player balances
    void printBalances() const {
        cout <<"\n Player Balances: \n";
        for (const auto& [name, balance] : balances) {
            cout << name << ": $" << balance <<endl;
        }
    }
};

//BETTING SYSTEM CLASS to manage bets and money for gambling
class Bets {
    private:
        map<string, int> bets; //Map <player name, bet amount>

    public:
        //takes player name and bet amount and adds to map
        void placeBet(const string& playerName, int bet) {
            bets[playerName] = bet;
        }

        //returns bet amount for a player
        int getBet(const string& name) const {
            //Find player bet in map
            auto bet = bets.find(name);

            //If found return bet amount, else return 0
            if (bet == bets.end()) {
                return 0; //Bet not found
            } else {
                return bet->second; //Return bet amount
            }
        }

        //clears all bets from the maop
        void clearBets() {
            bets.clear();
        }

        void printBets() const {
            cout <<"/n Current Bets:\n";

            //Loop through map and print keys and values
            for (auto i = bets.begin(); i != bets.end(); i++) {
                cout << i->first << ": $" << i->second << endl;
            }
        }
};
//BLACKJACK GAME CLASS
class BlackjackGame {
    private:
        Deck deck;
        Dealer dealer;
        queue<string> turnOrder;
        map<string, int> stats;
        set<string> bustedPlayers;
        Bank bank;
        Bets bets;
    
    public:
        void start(Player player) {
            stats["Wins"] = 0;
            stats["Losses"] = 0;
            stats["Ties"] = 0;
    
            bank.addAccount(player.getName(), 1000);
    
            while (true) {
                try {
                    playRound(player);
                } catch (const exception& e) {
                    cerr << "Error: " << e.what() << endl;
                    break;
                }
    
                char choice;
                cout << "\nPlay another round? (y/n): ";
                cin >> choice;
                if (tolower(choice) != 'y') break;
                player.clear();
                dealer.clear();
                bets.clearBets();
            }
    
            cout << "\nFinal Stats:\n";
            for (const auto& [key, val] : stats)
                cout << key << ": " << val << "\n";
    
            bank.printBalances();
        }
    
        void playRound(Player player) {
            cout << "\n--- New Round ---\n";
            cout << "Current Balance: $" << bank.getBalance(player.getName()) << endl;
    
            int bet;
            cout << "Place your bet: $";
            cin >> bet;
    
            bank.withdraw(player.getName(), bet);
            bets.placeBet(player.getName(), bet);
    
            // Initial deal
            for (int i = 0; i < 2; ++i) {
                player.addCard(deck.draw());
                dealer.addCard(deck.draw());
            }
    
            player.printHand();
            dealer.printHand(true);
    
            // Player's turn
            while (true) {
                if (player.get_total() >= 21) break;
                cout << "Hit or Stay? (h/s): ";
                char move;
                cin >> move;
                if (tolower(move) == 'h') {
                    Card drawn = deck.draw();
                    cout << player.getName() << " drew: " << drawn.toString() << "\n";
                    player.addCard(drawn);
                    player.printHand();
                } else break;
            }
    
            // Bust check
            if (player.get_total() > 21) {
                bustedPlayers.insert(player.getName());
                cout << "You busted!\n";
                stats["Losses"]++;
                return;
            }
    
            // Dealer's turn
            cout << "\nDealer's turn...\n";
            dealer.printHand();
            while (dealer.get_total() < 17) {
                Card drawn = deck.draw();
                cout << "Dealer drew: " << drawn.toString() << "\n";
                dealer.addCard(drawn);
            }
            dealer.printHand();
    
            // Result
            int pt = player.get_total();
            int dt = dealer.get_total();
            int playerBet = bets.getBet(player.getName());
    
            if (dt > 21 || pt > dt) {
                cout << "You win!\n";
                stats["Wins"]++;
                bank.deposit(player.getName(), playerBet * 2);
            } else if (pt == dt) {
                cout << "It's a tie.\n";
                stats["Ties"]++;
                bank.deposit(player.getName(), playerBet);
            } else {
                cout << "Dealer wins.\n";
                stats["Losses"]++;
            }
        }
    };

class Menu {
private:
    list<string> startScreen = {"+---------------------------+",
                                "|                           |",
                                "|    BLACK JACK THE GAME    |",
                                "|                           |",
                                "|    PRESS ENTER TO PLAY    |",
                                "|                           |",
                                "+---------------------------+"};
                                
    list<string> pickNameScreen = {"+---------------------------+",
                                   "|                           |",
                                   "|      Enter Your Name      |",
                                   "|                           |",
                                   "+---------------------------+"};

    list<string> homeScreen = {"+---------------------------+",
                               "|                           |",
                               "|       1. Start Game       |",
                               "|      2. Achievements      |",
                               "|          3. Quit          |",
                               "|                           |",
                               "+---------------------------+"};

    void printScreen(const list<string>& screen) {
        for (const auto& line : screen) {
            cout << line << endl;
        }
    }                 

public:
    void menuLoop() {
        char input;
        printScreen(startScreen);
        cin >> input;
        printScreen(pickNameScreen);
        string name;
        cin >> name;
        while (input != '3') {
            printScreen(homeScreen);
            cin >> input;
            if (input == '1') {

            }
            else if (input == '2') {

            }
            else if (input == '3') {
                break;
            }
            else {
                cout << "I dont understand this..." << endl;
                cout << "please enter '1' '2' or '3'" << endl;
            }
        }
    }
};
    
    //MAIN FUNCTION
    int main() {
        Menu mainMenu;
        mainMenu.menuLoop();
        return 0;
    }
    