#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



bool is_key_valid(string key)
{
    bool valid = true;
    /* Checking key has valid characters */
    for (int a = 0; a < strlen(key); a++)
    {
        if (!(key[a] >= 97 && key[a] <= 122))   // key[a] > 65 && key[a] < 90) || 
        {
            
            valid = false;
            return valid;
        }

    }
    
    // Checking for missing letter(double letters):
    int counts[26] = {0};
    for (int i = 0; i < strlen(key); i++)
    {
        int index = key[i] - 97;
        counts[index]++;
        if (counts[index] > 1) 
        {
            valid = false;
            return valid;
        }        
        
    }


    
    return valid;
    
}


string treat_key(string key)
{
    

    
    for (int a = 0; a < strlen(key); a++)
    {
        key[a] = tolower(key[a]);  // send all key text to lower
    }
    return key;
}


string encode_message(string message, string key)
{
    //printf("%s\n", message);
    //printf("%s\n", key);
    
    int ascii_message;
    
    for (int a = 0; a < strlen(message); a++)
    {
        ascii_message = (int)(message[a]);   // converting character in message to ascii code
        
        // printf("%i", ascii_message);  // A = 65, a = 97  // just checking ascii codes
        
        if (islower(message[a]))
        {
            message[a] = key[ascii_message - 97];  // zero'ing alphabet so we can match cypher
        }
        if (isupper(message[a]))
        {
            message[a] = toupper(key[ascii_message - 65]);  // cyphering
        }
        
    }

    return message;
}


int main(int argc, string argv[]) 
{

    
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    

    

    

    string key = treat_key(argv[1]);
    
    if (!is_key_valid(key))
    {
        printf("Invalid Key.\n");
        return 1;
        
    }
    

    
    string message = get_string("plaintext: ");
    
    string encoded = encode_message(message, key);
    
    printf("ciphertext: %s\n", encoded);
    
    return 0;
    
}


