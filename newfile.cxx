#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Flashcard
{
    string question;
    string answer;
};

int main()
{
    vector<Flashcard> cards;
    int current = 0, choice;

    // Sample flashcards
    cards.push_back({"What is C++?", "A programming language."});
    cards.push_back({"What is OOP?", "Object-Oriented Programming."});

    while (true)
    {
        cout << "\n===== FLASHCARD QUIZ APP =====\n";
        cout << "1. Show Current Flashcard\n";
        cout << "2. Show Answer\n";
        cout << "3. Next Flashcard\n";
        cout << "4. Previous Flashcard\n";
        cout << "5. Add Flashcard\n";
        cout << "6. Edit Flashcard\n";
        cout << "7. Delete Flashcard\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            if (!cards.empty())
                cout << "\nQuestion: " << cards[current].question << endl;
            else
                cout << "No flashcards available.\n";
            break;

        case 2:
            if (!cards.empty())
                cout << "Answer: " << cards[current].answer << endl;
            else
                cout << "No flashcards available.\n";
            break;

        case 3:
            if (!cards.empty())
            {
                current = (current + 1) % cards.size();
                cout << "Question: " << cards[current].question << endl;
            }
            break;

        case 4:
            if (!cards.empty())
            {
                current = (current - 1 + cards.size()) % cards.size();
                cout << "Question: " << cards[current].question << endl;
            }
            break;

        case 5:
        {
            Flashcard f;
            cout << "Enter Question: ";
            getline(cin, f.question);
            cout << "Enter Answer: ";
            getline(cin, f.answer);

            cards.push_back(f);
            cout << "Flashcard Added Successfully!\n";
            break;
        }

        case 6:
            if (!cards.empty())
            {
                cout << "Enter New Question: ";
                getline(cin, cards[current].question);

                cout << "Enter New Answer: ";
                getline(cin, cards[current].answer);

                cout << "Flashcard Updated!\n";
            }
            break;

        case 7:
            if (!cards.empty())
            {
                cards.erase(cards.begin() + current);

                if (cards.empty())
                    current = 0;
                else if (current >= cards.size())
                    current = cards.size() - 1;

                cout << "Flashcard Deleted!\n";
            }
            else
            {
                cout << "No flashcards to delete.\n";
            }
            break;

        case 8:
            cout << "Thank You!\n";
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}
	
