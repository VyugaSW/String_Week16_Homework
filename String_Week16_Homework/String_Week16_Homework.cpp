
#include <stdio.h>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
//Task 1

void ReplacementWord(char* arr, const char* word, const char* replacedWord) {
    char* newText = new char[strlen(arr)+strlen(word)+strlen(replacedWord)];
    char* temp;
    temp = strstr(arr, replacedWord);
    strncpy_s(newText, strlen(arr)+ strlen(word) + strlen(replacedWord), arr, strlen(arr) - strlen(temp));
    strcat_s(newText, strlen(arr) + strlen(word) + strlen(replacedWord), word);
    strcat_s(newText, strlen(arr) + strlen(word) + strlen(replacedWord), temp + strlen(replacedWord));
    cout << newText;
}

void UpLitera(char* arr) {
    char* temp = arr;
    //С учётом, что первая буква фразы, высказывания уже заглавная
    while (temp = strstr(temp, ". ")) {
        _strupr_s(temp, strlen(arr));
        temp += 1;
        _strlwr_s(temp+2, strlen(arr));
    };
    //вышло волшебный образом, что массив почему-то изменяется (дело, вероятно, в указателях), но УРА!
    cout << arr;
}

void CountLiters(char* arr) {
    int size = 1;
    char* liters = new char[31];
    int* count = new int[31];
    int a = 0;
    char* temp = new char[strlen(arr)];
    strcpy_s(temp, strlen(arr) + 1, arr);
    while (strlen(temp) != 1) {
        if (isalpha(temp[0])) {
            for (int i = 0; i < size; i++) {
                if (liters[i] == temp[0])
                    a++;
            }

            if (a == 0) {                
                liters[size - 1] = temp[0];
                count[size - 1] = 0;
                count[size - 1]++;
                temp += 1;
                size++;
                a = 0;

            }
            else {
                temp += 1;
                a = 0;
            }
        }
        else 
            temp+= 1;   
        
    }

    for (int i = 0; i < size-1; i++) {
        cout << liters[i] << " " << count[i] << endl;
    }
    delete[] liters;
    delete[] count;
}
int CountNumbs(char* arr) {
    int counter = 0;
    for (int i = 0; i < strlen(arr); i++) {
        if (isdigit(arr[i]))
            counter++;
    }
    return counter;
}





int main()
{
    char* someText = new char[280]{ "Our life is far from being a theatre. This is a complete circus,\
    and we are in the role of the main clowns." };
    const char word[50]{ "There" };
    const char replacedWord[50]{ "This" };
    //ReplacementWord(someText, word, replacedWord);

    char* someText2 = new char[280]{ "Hello. you so silly. oh no. no" };
    UpLitera(someText2);
    //CountLiters(someText2); //l

}


