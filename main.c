
// importing all the important libraries
#include <stdio.h>
#include <string.h>

// declaring the functions used in the program
int total_charac_by_user(char user_input[]);
int errors(char text[], char user_input[]);
float gross_wpm(int len_text, float total_time);
float net_wpm(int total_charac_by_user, int error, float total_time);
float accuracy(float net_wpm, float gross_wpm);
void display_text(char string[]);
void display_result(int error, float Gross_wpm, float Net_wpm, float Accuracy, int length_user_input);


// main 
int main()
{
    float Gross_wpm, total_time, Net_wpm, Accuracy;
    int length, length_user_input, error, i = 1;
  
    //Text contains the string that the user has to enter  
    // Test string     
    char text[1000] = "A definite article is an article that marks a definite noun phrase. Definite articles such as English the are used to refer to a particular member of a group. It may be something that the speaker has already mentioned or it may be otherwise something uniquely specified."
    "For example, Sentence 1 uses the definite article and thus expresses a request for a particular book. In contrast, Sentence 2 uses an indefinite article and thus conveys that the speaker would be satisfied with any book.";
    
    // user_input contains the user' s response       
    char user_input[1000];
    display_text(text);
    
    gets(user_input);
    length = strlen(user_input);
    
    total_time = 1;
    length_user_input = total_charac_by_user(user_input);
    Gross_wpm = gross_wpm(length_user_input, total_time);
    error = errors(text, user_input);
    Net_wpm = net_wpm(length_user_input, error, total_time);
    Accuracy = accuracy(Net_wpm, Gross_wpm);
    
    display_result(error, Gross_wpm, Net_wpm, Accuracy, length_user_input);
 
}

// Function to calculate and display result of the user
void display_result(int error, float Gross_wpm, float Net_wpm, float Accuracy, int length_user_input)
{
    if (length_user_input < 20)
    {
        printf("Insufficient data to analyze. Please provide sufficient data to get accurate result\n");
    }
    else 
    {
        printf("WPM stands for Word Per Minute");
        printf("Error: %d\n", error);
        if (Gross_wpm < Net_wpm)
        {
            Gross_wpm = Net_wpm;
        }
        printf("Gross WPM : %0.2f\n", Gross_wpm);
        
        printf("Net WPM: %0.2f\n", Net_wpm);
        if (Accuracy > 100)
        {
            Accuracy = 100;
        }
        printf("Accuracy: %0.2f%%\n", Accuracy);           
    }
    

}
// Function to display the text for the user 
void display_text(char text[])
{
    printf("%s\n", text);
}

// Function to calculate the total characters by the user except the spaces 
int total_charac_by_user(char user_input[])
{

    int text_length = strlen(user_input);
    int count = 0;
    for (int x = 0; x < text_length; x++)
    {
        if (user_input[x] == ' ')
        {
            count += 1;
        }
    }
    int len_text = text_length - count;
    return len_text;
}



// Function to calculate the total errors made by the user  
int errors(char text[], char user_input[])
{
    int len = strlen(user_input);
    int error = 0;
    for (int l = 0; l < len; l++)
    {
        if (user_input[l] !=  text[l])
        {
            error += 1;
        }
    }
    return error;
}



// Function to calculate the Gross Word Per minute in other words it means total word per minute 
float gross_wpm(int len_text, float total_time)
// len_text is the total characters entered by the user excluding the spaces
{
    float words = len_text / 5;
    float time = total_time;
    float words_per_min = words / time;
    return words_per_min;
}


/* Function to calculate the Net Word Per minute, it depends on the typing speed as well
as the accuracy of the user */
float net_wpm(int total_charac_by_user, int error, float total_time)
// here total_charac_by_user is the total characters entered by the user excluding the spaces
{
    float correct_char = total_charac_by_user - error; 
    float correct_word =  correct_char  /  5; 
    float net_wpm = correct_word / total_time;
    return net_wpm;    
}



// Function to calculate the accuracy of the user 
float accuracy(float net_wpm, float gross_wpm)
{
    float per_acc = (net_wpm/gross_wpm) * 100;
    return per_acc;  
}
