#include <iostream>

#include <ctime>

#include <stdlib.h>

using namespace std;

int current = 0;

int getRandom() {

    int timestamp = time(NULL);

    

    if (current != timestamp) {

        current = timestamp;

        srand(current);

    }

    

    return rand();

}

int getCard() {

    return getRandom() % 13;

}

int getSuit() {

    return getRandom() % 4;

}

int takeOneCard(int** cards) {

    int suit, card;

    do {

        suit = getSuit();

        card = getCard();

        cout << "take card: suit " << suit << " card " << card << endl;

    } while (cards[suit][card] == 0);

    cards[suit][card] = 0;

    

    return card == 0 || card >= 9 ? 10 : card + 1;

}

int** createTable() {

    int** table = new int*[4];

    for (int i=0; i<4; i++) {

        table[i] = new int[13];

        for(int j = 0; j < 13; j++) table[i][j] = 1;

    }

    return table;

}

void freeTable(int** table) {

    for(int i = 0; i < 4; i++) {

        if (table[i]) delete[] table[i];

    }

    delete[] table;    

}

void printScore(int user, int computer) {

    cout << "你的點數: " <<  user << " 電腦的點數:" << computer << endl;

}

int main()

{

    int **cards = createTable();

    int scoreUser = takeOneCard(cards);

    int scoreComputer = takeOneCard(cards);

    

    printScore(scoreUser, scoreComputer);

    

    char ans;

    do {

        cout << "是否要牌?(Y/N)";

        ans = cin.get();


        if (ans == 'N') {

            break;

        }

        else if (ans == 'Y') {

            scoreUser += takeOneCard(cards);

            printScore(scoreUser, scoreComputer);

        }

    } while (ans != 'N' && scoreUser <= 21);

    

    printScore(scoreUser, scoreComputer);

    

    while (scoreUser <= 21 && scoreComputer <= scoreUser && scoreComputer <= 21) {

        scoreComputer += takeOneCard(cards);

        printScore(scoreUser, scoreComputer);

    };

    

    if (scoreComputer > 21) cout << "您獲勝了";

    else if (scoreUser > 21) cout << "電腦獲勝了";

    else {

        if (scoreUser > scoreComputer) cout << "您獲勝了";

        else if (scoreUser == scoreComputer) cout << "平手";

        else cout << "電腦獲勝了";

    }

    

    freeTable(cards);

    return 0;

}


