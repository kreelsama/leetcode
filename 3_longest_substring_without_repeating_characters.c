#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int alpha[256] = {0};
    for (int i = 0; i < 256; i++){
        alpha[i] = -1;
    }
    int len = 0, maxlen = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if( alpha[s[i]] != -1 && i - alpha[s[i]] <= len ){
            maxlen = len > maxlen ? len : maxlen;
            len = i - alpha[s[i]];
        }
        else{
            ++ len;
        }
        alpha[s[i]] = i;
        printf("%c:%d:%d\n", s[i], i, len);
    }
    maxlen = len > maxlen ? len : maxlen;
    return maxlen;
}

int main(int argc, char* argv[]){
    printf("%d", lengthOfLongestSubstring(argv[1]));
    return 0;
}
