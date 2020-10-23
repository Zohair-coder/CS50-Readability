#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(int length, string text);
int count_words(int length, string text);
int count_sentences(int length, string text);
int grade_formula(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);

    int letters = count_letters(length, text);
    printf("Letters: %i\n", letters);

    int words = count_words(length, text);
    printf("Words: %i\n", words);

    int sentences = count_sentences(length, text);
    printf("Sentences: %i\n", sentences);

    int grade = grade_formula(letters, words, sentences);
    if (grade < 16 && grade >= 1)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }



}

int count_letters(int length, string text)
{
    int letters = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }
    return letters;
}

int count_words(int length, string text)
{
    int words = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            words ++;
        }
    }

    if (length >= 1)
    {
        words ++;
    }
    return words;

}

int count_sentences(int length, string text)
{
    int sentences = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences ++;
        }
    }
    return sentences;
}

int grade_formula(int letters, int words, int sentences)
{
    float average_letters = (float) letters / (float) words * 100;
    printf("Average Letters per 100 words: %f\n", average_letters);
    float average_sentences = (float) sentences / (float) words * 100;
    printf("Average Sentences per 100 words: %f\n", average_sentences);
    float index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;
    return round(index);

}