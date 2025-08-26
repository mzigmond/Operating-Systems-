#include <stdio.h>

struct letter_count{
    char letter;
    int count;
};


int main(){
    struct letter_count list[52];
    for (int i=0; i<52; i++){
        list[i].count = 0;
        if (i<26){
            list[i].letter = 'A' + i;
        } else {
            list[i].letter = 'a' + (i - 26);
        }

    }

    char ch;
    while (!feof(stdin)){
        scanf("%c", &ch);
            if (ch>= 'A' && ch <= 'Z'){
                int index = ch - 'A';
                list[index].count++;

            } else if (ch >= 'a' && ch <= 'z'){
                int index = ch - 'a' + 26;
                list[index].count++;
            }
    }

    for (int i = 0; i < 52; i++){
        printf ("%c: %d\n", list[i].letter, list[i].count);
    }

    return 0;
}