#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Generate Code
    const int CodeA = rand() % Difficulty + Difficulty; //initialized variables are defined by = sign
    const int CodeB = rand() % Difficulty + Difficulty;     //const variables are constant, so they don't get reassigned anywhere without error
    const int CodeC = rand() % Difficulty + Difficulty;          //the compiler will alert you!
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    // Print Quoted messages to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;
    //cout = Character Output, Insertion Operator = <<, cin = Character Input, Extraction Operator = >>, Characters like 'x' get converted to 0 with integers 
    
    
    // Store player guess
    int GuessA, GuessB, GuessC;
    //std::cin >> GuessA >> GuessB >> GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
        
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***";
        return false;
    }
    //
    
}

int main()    //int main() {return 0;} why main?
              //you can have many functions in C++, every C++ program requires this as the starting point 
              //int = integer, means it returns whatever answers within the parentheses
{
    srand(time(NULL)); // create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    #control + C for killing the compiler in case of error looping
    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    //controls the while loop to continue and end at level 5
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}
