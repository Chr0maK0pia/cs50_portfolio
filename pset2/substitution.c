#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>



string translate(string text, string cipher);

int main(int argc, string argv[])
{


    string cipher = argv[1];

    if(argc < 2)
    {

        printf("Usage: ./substitution key\n");
        return 1;

    }
    if(strlen(cipher) != 26)
    {


            printf("Key must contain 26 characters.\n");
            return 1;


    }
    if(argc > 2)
    {

        printf("Too many command line arguments\n");
        return 1;

    }

    for (int i = 0, j = strlen(cipher); i < j; i++)
   {
        if(!isalpha(cipher[i]))
        {
            printf("Key must be alphabetical.\n");
            return 1;

        }

      for (int k = i+1; k < j; k++)
      {
         if (toupper(cipher[i]) == toupper(cipher[k]))
         {
            printf("Key must not contain repeating characters.\n");
            return 1;
         }

      }
   }






    string pltxt = get_string("plaintext: ");

    string cphtxt = translate(pltxt, cipher);

    printf("ciphertext: %s\n", cphtxt);









}

string translate(string text, string cipher){




        for(int i = 0;  i < strlen(text); i++)
        {

            if(isalpha(text[i]))
            {

                if(islower(text[i]))
                {

                    text[i] = tolower(cipher[text[i] - 97]);




                }
                else if(isupper(text[i]))
                {

                    text[i] = toupper(cipher[text[i] - 65]);



                }



            }
            else
            {


                    text[i] =  text[i];

            }


        }


        return text;


}



