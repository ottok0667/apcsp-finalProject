#include <stdio.h>
#include <string.h>

char outputArr[10][50];

char writeFile()
{
  FILE *fp;
  int i;

  fp = fopen (" /home/kelsi/finalProject/websiteProgram/output.txt", "wb");

  if (fp)
  {
    for (i = 0; i < 10; i++)
    {
      fputc(outputArr[i], fp);
    }
    fclose (fp);
  }
}


void recievePhrase()
{
//let user input a phrase to be guessed
  char inputPhrase[250], phrase[250];
  int i = 0;

  printf("Input a word or phrase to be guessed\nNote: Characters that are not letters (e.g. commas, numbers, spaces, etc.) will not need to be guessed\n");

  do {
    fgets(inputPhrase, 250, stdin);
    strcpy(phrase, inputPhrase);
  } while ((inputPhrase[0] == '\n') || (inputPhrase[0] == ' '));

  for (i = 0; i < (strlen(inputPhrase) - 1); i++)
  {
    if (((inputPhrase[i] >= 'a') && (inputPhrase[i] <= 'z')) || ((inputPhrase[i] >= 'A') && (inputPhrase[i] <= 'Z')))
    {
      phrase[i] = '_';
    }
  }
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%s\n\n", phrase);

  strcpy(outputArr[0], inputPhrase);

//allow the user to input the difficulty level/how many characters are allowed to be guessed incorrectly
  char diff[75];
  int numErr;

  diff[0] = diff[1] = diff[2] = 0;

  printf("Input a difficulty level/the number of letters that will be allowed to be entered incorrectly: ");

  while (1)
  {
    fgets(diff, 75, stdin);
    if (sscanf(diff, "%d", &numErr) == 1) break;
      printf("Not a valid difficulty level - try again!\n");
  }

int miss = 0;

//loop until player wins or loses

  while ((!(strcmp(inputPhrase, phrase) == 0)) && (miss < numErr))
  {
  //now allow for user to input letters as guesses
    char alphachar[2], car[2];
    int n = 0;
    int numLett = 0;

    printf("Enter a letter to guess: ");

    while (1)
    {
      fgets(alphachar, 2, stdin);
      if (sscanf(alphachar, "%s", car) == 1) break;
    }


  //check to see if the character entered is in the entered phrase
    for (n = 0; n < (strlen(inputPhrase)); n++)
    {
      if (inputPhrase[n] == car[0])
      {
        phrase[n] = car[0];
        numLett++;
      }
    }

    if (numLett == 0)
    {
      miss++;
      printf("Wrong guess! You have made %d wrong guesses out of %d allowed\n", miss, numErr);
    }
    printf("%s\n", phrase);

  }
  if (strcmp(inputPhrase, phrase) == 0)
  {
    printf("You Win!\n");
  }

  if (miss >= numErr)
  {
    printf("You Lose\n");
  }

}

int restartGame()
{
  char cont[2];

  printf("Do you wish to play again (y/n)? ");
  while (1)
  {
    fgets(cont, 2, stdin);
    printf("\n\n\n\n\n\n\n");
    if (cont[0] == 'y') return 1;
    else if (cont[0] == 'n') return 0;
    else
    {
      printf("Not a valid input - try again!\n");
    }
  }
}

void hangmanMain()
{
  do {
    recievePhrase();
    getchar();
  } while (restartGame());
  writeFile();
}
