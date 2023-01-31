#include <stdio.h>
#include <string.h>


int main()
{   char[] text = "Hello This is Aryan" ;
    char user_input[];
    user_input = input("");
    int char_per_min = cal_charac_per_min(user_input);       
}


int total_charac_by_user(text)
{

    int text = strlen(text);
    int count = 0;
    for (int x = 0; x < strlen(user_input); x++)
    {
        if (user_input[x] == " ")
        {
            count += 1;
        }
    }
    int len_text = text - count;
    return len_text;
}

int errors(int text, int user_input)
{
    int len = strlen(user_input);
    int error = 0;
    for (int l = 0; l < len; l++)
    {
        if (user_text[l] != text[l])
        {
            error += 1;
        }
    }
    return error;
}



int cal_words_per_min(int len_text, int total_time)
{
    int words = len_text / 5;
    int time = total_time;
    int words_per_min = words / time;
    return words_per_min;
}



int gross_wpm(int total_charac_by_user, int error)
{
    int gross_wpm = (total_charac_by_user - error) / 5;
    return gross_wpm;    
}