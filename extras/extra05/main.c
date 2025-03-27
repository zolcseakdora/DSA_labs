#include <stdio.h>
#include <string.h>
bool checkValidString(char* s);
int main(void)
{
    
    return 0;
}
bool checkValidString(char* s) {
    int hossz = strlen(s);
    int nyitott[hossz];
    int csillagok[hossz];
    int top_nyitott = -1, top_csillagok=-1;
    for(int i=0; s[i]; ++i ){
        char kurrens= s[i];
        if(kurrens == '('){
            nyitott[++top_nyitott] = i;
            continue;
        }
        if( kurrens == '*'){
            csillagok[++top_csillagok] = i;
            continue;
        }

        if(top_nyitott >= 0){
            --top_nyitott;
            continue;
        }

        if(top_csillagok >= 0){
            --top_csillagok;
            continue;
        }
        return false;

    }
    while (top_nyitott >= 0 && top_csillagok >= 0) {
        if (nyitott[top_nyitott] < csillagok[top_csillagok]) {
            top_nyitott--;
            top_csillagok--;
        } else {
            break;
        }
    }
    return top_nyitott == -1;
}