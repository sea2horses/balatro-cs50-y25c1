#include <cs50.h>
#include <stdio.h>

// Number of cards per hand
#define HAND_SIZE 5

// Cards have value and suit
typedef struct
{
  int value; // (2-14), 10 being T, 11 being J, 12 being Q, 13 being K and 14 being Ace
  char suit; // S for Spades, H for Hearts, C for Clubs and D for Diamonds
} card;

// Array of cards played
card cards[HAND_SIZE];

// Function prototypes
bool get_value_from_letter(char c);
bool validate_card(string card);
int calculate_points();

int main(void)
{
  printf("Play: \n");

  // Ask the user to input its 5 cards
  for (int i = 0; i < HAND_SIZE; i++)
  {
    // Record each card, unless its invalid
    string card_input;
    do
    {
      card_input = get_string("Card #%d: ", i + 1);
    } while (!validate_card(card_input));

    // Create new card and save to array
    card new_card;
    new_card.value = get_value_from_letter(card_input[0]);
    new_card.suit = card_input[1];

    cards[i] = new_card;
  }

  // Print the points the play got
  printf("Points for play: %d\n", calculate_points());
}

// TODO
// This function must return the number corresponding to each possible letter value
// in the case of any invalid value, return -1
// '2' -> 2
// 'Q' -> 12
// 'A' -> 14
// '0' -> -1
// 'Z' -> -1
bool get_value_from_letter(char c)
{
  return -1;
}

// This function must:
// - Verify the card is only 2 letters long
// - Verify the first letter is either a number or T, J, Q, K or A
// - Verify the number is on an acceptable range (2-10)
// - Verify the second letter is a valid suit (S, H, C, D)
// - Verify the card hasn't already been played (no duplicates)
bool validate_card(string card)
{
  // TODO
  return true;
}

// Return the point value of the card combination in cards[]
int calculate_points()
{
  // Count occurrences per value
  int values[15] = {0}; // 2 - 14
  for (int i = 0; i < HAND_SIZE; i++)
    values[cards[i].value]++;

  // Count occurrences per suit
  int suits[4] = {0}; // 0:S, 1:H, 2:D, 3:C
  for (int i = 0; i < HAND_SIZE; i++)
  {
    switch (cards[i].suit)
    {
    case 'S':
      suits[0]++;
      break;
    case 'H':
      suits[1]++;
      break;
    case 'D':
      suits[2]++;
      break;
    case 'C':
      suits[3]++;
      break;
    }
  }

  // TODO: Calculate best combination
  return 0;
}