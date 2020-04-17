#ifndef playingcard_h
#define playingcard_h

#include <string>

class PlayingCard {

    private:
        char suit;
        char value;
        bool isGood(char value, char suit);
    public:
        PlayingCard();
        PlayingCard(char value, char suit);
        bool setCard (char value, char suit);
        char getValue();
        char getSuit();
        std::string getCardCode();
        bool isValid();
};

#endif // playingcard_h
