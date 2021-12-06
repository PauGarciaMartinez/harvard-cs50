#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

string encryptText(string, string);

int main(int argc, string argv[])
{
    // Checks to validate the key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic characters\n");
            return 1;
        }
    }

    for (int i = 0, j = strlen(argv[1]); i < j; i++)
    {
      for (int k = i + 1; k < j; k++)
      {
         if (argv[1][i] == argv[1][k])
         {
            printf("Key must contain 26 different letters\n");
            return 1;
         }
      }
    }

    // Once the key is validated, get text from the user and cipher it
    string plaintext = get_string("Plain text: ");

    printf("ciphertext: %s", encryptText(argv[1], plaintext));
    printf("\n");

    return 0;
}

string encryptText(string key, string text)
{
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Loop for every letter in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            bool isUpper = (text[i] >= 65 && text[i] <= 90);

            char letter = tolower(text[i]);

            int index;

            // Find regular alphabet index for each letter
            for (int j = 0, k = strlen(alphabet); j < k; j++)
            {
                if (letter == alphabet[j])
                {
                    index = j;
                }
            }

            // Map current letter to cipher equivalent
            for (int j = 0, k = strlen(alphabet); j < k; j++)
            {
                if (letter == alphabet[j])
                {
                    index = j;
                }
            }

            for (int a = 0, b = strlen(key); a < b; a++)
            {
                key[a] = tolower(key[a]);
            }

            // Map current letter to cipher equivalent
            text[i] = key[index];

            if (isUpper)
            {
                text[i] = toupper(text[i]);
            }
        }
    }

    return text;
}
