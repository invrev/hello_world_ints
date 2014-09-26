    
int lengthOfLastWord(const char *s) {
    int fwd_length  = 0;
    while (s[fwd_length] != '\0') {
        fwd_length += 1;
    }
    if (fwd_length != 0) {
        int word_length = 0;
        //1.Go untill find the non space character
        while (s[fwd_length - 1] == ' ' && (fwd_length - 1) > -1) {
            fwd_length -= 1;
        }
        //2.Get the size of last word
        while (s[fwd_length - 1] != ' ' && (fwd_length - 1) > -1) {
            fwd_length -= 1;
            word_length += 1;
        }   
        return (word_length);
    }
    return fwd_length;
}
