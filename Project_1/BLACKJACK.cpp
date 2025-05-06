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
#include <ctime>

using namespace std;

//CARD STRUCT
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
        deque<Card> temp;
        list<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
        for (const auto& suit : suits) {    //Loop through suits
            for (int i = 2; i <= 10; i++) { //Loop through numbers 2-10
                temp.push_back({i,suit});   //Add number cards to deck
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

    Card draw() {
        if (cards.empty()) generateDeck();//Generate new deck when empty
        Card top = cards.top(); //Access top card, save to return
        cards.pop();    //Pop top card
        return top;     //Return top card
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
        for (const auto& card : cards) {
            cout << "[" << card.toString() << "], ";
        }
        cout << " Total: " << total << endl;
    }
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
            int i = 0;
            for (const auto& card : cards) {
                if (hideFirst && i++ == 0) {
                    cout << "[Hidden], ";
                } else {
                    cout << "[" << card.toString() << "], ";
                }
            }
            cout << (hideFirst ? "" : " Total: " + to_string(get_total())) << endl;
        }
    };

//BLACKJACK GAME CLASS
class BlackjackGame {
    private:
        Deck deck;
        Player player{"You"};
        Dealer dealer;
        queue<string> turnOrder;
        map<string, int> stats;
        set<string> bustedPlayers;
    
    public:
        void start() {
            stats["Wins"] = 0;
            stats["Losses"] = 0;
            stats["Ties"] = 0;
    
            while (true) {
                playRound();
                char choice;
                cout << "\nPlay another round? (y/n): ";
                cin >> choice;
                if (tolower(choice) != 'y') break;
                player.clear();
                dealer.clear();
            }
    
            cout << "\nFinal Stats:\n";
            for (const auto& [key, val] : stats)
                cout << key << ": " << val << "\n";
        }
    
        void playRound() {
            turnOrder.push("Player");
            turnOrder.push("Dealer");
    
            // Initial deal
            for (int i = 0; i < 2; ++i) {
                player.addCard(deck.draw());
                dealer.addCard(deck.draw());
            }
    
            // Player's turn
            player.printHand();
            dealer.printHand(true);
    
            while (true) {
                if (player.get_total() >= 21) break;
                cout << "Hit or Stay? (h/s): ";
                char move;
                cin >> move;
                if (tolower(move) == 'h') {
                    Card drawn = deck.draw();
                    cout << "You drew: " << drawn.toString() << "\n";
                    player.addCard(drawn);
                    player.printHand();
                } else break;
            }
    
            // Bust check
            if (player.get_total() > 21) {
                bustedPlayers.insert("Player");
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
    
            // Determine result
            int pt = player.get_total();
            int dt = dealer.get_total();
    
            if (dt > 21 || pt > dt) {
                cout << "You win!\n";
                stats["Wins"]++;
            } else if (pt == dt) {
                cout << "It's a tie.\n";
                stats["Ties"]++;
            } else {
                cout << "Dealer wins.\n";
                stats["Losses"]++;
            }
    
            bustedPlayers.clear();
        }
    };
    

//MAIN
int main() {
    BlackjackGame game;
    game.start();
    return 0;
}