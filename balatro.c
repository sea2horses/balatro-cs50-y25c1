#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
int get_value_from_letter(char c);
bool validate_card(string input);
int calculate_points();
bool is_flush();
bool is_straight();
int count_kind(int count);
int count_pairs();

int main(void)
{
    printf("Play:\n");

    // Ask the user to input its 5 cards
    for (int i = 0; i < HAND_SIZE; i++)
    {
        string input;
        do
        {
            input = get_string("Card #%d: ", i + 1);
        } while (!validate_card(input));

        card new_card;
        new_card.value = get_value_from_letter(input[0]);
        new_card.suit = input[1];

        cards[i] = new_card;
    }

    printf("Points for play: %d\n", calculate_points());
}

// Convert a card letter to its value or return -1 if invalid
int get_value_from_letter(char c)
{
    if (c >= '2' && c <= '9')
        return c - '0';
    else if (toupper(c) == 'T')
        return 10;
    else if (toupper(c) == 'J')
        return 11;
    else if (toupper(c) == 'Q')
        return 12;
    else if (toupper(c) == 'K')
        return 13;
    else if (toupper(c) == 'A')
        return 14;
    else
        return -1;
}

// Check if a card string is valid and not already played
bool validate_card(string input)
{
    if (strlen(input) != 2)
        return false;

    char valchar = toupper(input[0]);
    char suitchar = toupper(input[1]);

    int value = get_value_from_letter(valchar);
    if (value == -1)
        return false;

    if (suitchar != 'S' && suitchar != 'H' && suitchar != 'D' && suitchar != 'C')
        return false;

    // Check for duplicates
    for (int i = 0; i < HAND_SIZE; i++)
    {
        if (cards[i].value == value && cards[i].suit == suitchar)
        {
            return false;
        }
    }

    return true;
}

// Check for flush (all suits equal)
bool is_flush()
{
    char suit = cards[0].suit;
    for (int i = 1; i < HAND_SIZE; i++)
    {
        if (cards[i].suit != suit)
            return false;
    }
    return true;
}

// Check for straight (consecutive values)
bool is_straight()
{
    int values[HAND_SIZE];
    for (int i = 0; i < HAND_SIZE; i++)
        values[i] = cards[i].value;

    // Sort values
    for (int i = 0; i < HAND_SIZE - 1; i++)
    {
        for (int j = i + 1; j < HAND_SIZE; j++)
        {
            if (values[i] > values[j])
            {
                int tmp = values[i];
                values[i] = values[j];
                values[j] = tmp;
            }
        }
    }

    // Special case: A-2-3-4-5 (Ace low)
    if (values[0] == 2 && values[1] == 3 && values[2] == 4 &&
        values[3] == 5 && values[4] == 14)
        return true;

    for (int i = 0; i < HAND_SIZE - 1; i++)
    {
        if (values[i + 1] != values[i] + 1)
            return false;
    }
    return true;
}

// Count how many times a value appears (for kind hands)
int count_kind(int count)
{
    int values[15] = {0};
    for (int i = 0; i < HAND_SIZE; i++)
        values[cards[i].value]++;
    for (int i = 2; i <= 14; i++)
        if (values[i] == count)
            return 1;
    return 0;
}

// Count how many distinct pairs are in hand
int count_pairs()
{
    int values[15] = {0};
    int pairs = 0;
    for (int i = 0; i < HAND_SIZE; i++)
        values[cards[i].value]++;
    for (int i = 2; i <= 14; i++)
        if (values[i] == 2)
            pairs++;
    return pairs;
}

int calculate_points()
{
    bool flush = is_flush();
    bool straight = is_straight();

    if (flush && straight)
    {
        // Check if Royal Flush (T-J-Q-K-A)
        int total = 0;
        for (int i = 0; i < HAND_SIZE; i++)
            total += cards[i].value;
        if (total == (10 + 11 + 12 + 13 + 14))
            return 10000;
        return 5000;
    }

    if (count_kind(4))
        return 3000;

    if (count_kind(3) && count_pairs() == 1)
        return 2000;

    if (flush)
        return 1500;

    if (straight)
        return 1000;

    if (count_kind(3))
        return 500;

    if (count_pairs() == 2)
        return 300;

    if (count_pairs() == 1)
        return 100;

    return 50; // High card
}
