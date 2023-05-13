#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // printf("%d\n",'Z');  // A = 65  Z = 90
    // printf("%d\n", 'z'); // a = 97  z= 122
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    // printf("%i\n", score1);
    // printf("%i\n", score2);
    
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    
    // TODO: Compute and return score for string
    
    int score = 0;
    int point = 0;
    // printf("\n");
    
    for (int a = 0; a < strlen(word); a++)
    {
        // printf("%c",word[a]);
        
        if islower(word[a])
        {
            int ch = word[a];
            if (ch >= 97 && ch <= 122)
            {
                ch = ch - 97;
                point = POINTS[ch];
                // printf("%i,", point);
            }
        }
        else if isupper(word[a])
        {
            int ch = word[a];
            if (ch >= 65 && ch <= 90)
            {
                ch = ch - 65;
                point = POINTS[ch];
                // printf("%i,", point);
            }
        }
        else
        {
            point = 0;
        }
        
    
        score = score + point;
        

    }
    
    
    
    return score;
}
