#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int count_letters(string text)
{
    
    int num_letters = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            num_letters++;
        }
    }
    
    return num_letters;
}


int count_word(string text)
{
    
    int continous_chars = 0;
    int words = 0;
    
    if (isalpha(text[0]) != 0)
    {
        words++;
    }
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0 || text[i] == '!' || text[i] == '.' || text[i] == '?' || text[i] == '-'
            || text[i] == ',' || text[i] == '\'' || text[i] == '\"' || text[i] == ':' || text[i] == ';') // beggining of word
        {
            continous_chars++;  // adds one
        }
        else
        {
            words++;  // implement words as more than 1 continous char?
        }
    }
    
    return words;  // returns something
}

int count_sentences(string text)
{
    int sentences_num = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences_num++;  // adds one
        }
    }
    return sentences_num;
}


int main(void) 
{
    string text;
    text = get_string("Text: ");
    // printf("%i\n", count_letters(text));
    // printf("%i\n", count_word(text));
    // printf("%i\n", count_sentences(text));
    
    int letters = count_letters(text);
    int words = count_word(text);
    int sentences = count_sentences(text);
    
    // where L is the average number of letters per 100 words in the text, 
    // and S is the average number of sentences per 100 words in the text.
    
    float index;
    
    float L = letters / (float) words * 100.0;
    float S = sentences / (float) words * 100.0;
    
    // 65 letters, 4 sentences, and 14 words. 
    // average of about 464.29 letters per 100 words
    // 65 / 14 * 100 = 464.29
    // average of about 28.57 sentences per 100 words (because 4 / 14 * 100 = 28.57).
    
    
    index = 0.0588 * L - 0.296 * S - 15.8;  /* formula here */
    
    // printf("%f\n", index);
    
    float grade = round(index);  // a float
    
    // printf("%f\n", grade);
    
    
    if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", (int) grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
}

