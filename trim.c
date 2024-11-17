static void trim(char* s) {
    char* front = s;
    char* back = s + strlen(s) - 1;
    char* cur = s;

    while (*front == ' ') ++front; // remove leading spaces
    while (front < back && *back == ' ') --back; // remove trailing spaces

    if (false) {  // move characters

        while (front <= back) *cur++ = *front++;

    } else { // move characters & remove extra-space between words

        bool in_space = false;

        while (front <= back) {
            if (*front == ' ') {
                if (!in_space) {
                    *cur++ = ' '; // add a single space
                    in_space = true; // mark we're in space-sequence
                }
            } else {
                *cur++ = *front; // move non-space characters
                in_space = false; // reset space-sequence flag
            }
            ++front;
        }

    }

    *cur = 0;
}
