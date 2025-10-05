/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1181                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1181                           #+#        #+#      #+#    */
/*   Solved: 2025/10/05 11:00:41 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20000
#define MAX_LENGTH 51

typedef struct {
    char word[MAX_LENGTH];
} Word;

int compare(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    int len1 = strlen(word1->word);
    int len2 = strlen(word2->word);
    if (len1 == len2) {
        return strcmp(word1->word, word2->word);
    }
    return len1 - len2;
}

int main() {
    int n;
    scanf("%d", &n);
    Word words[MAX_WORDS];
    int count = 0;

    for (int i = 0; i < n; i++) {
        char buffer[MAX_LENGTH];
        scanf("%s", buffer);
        int isDuplicate = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(words[j].word, buffer) == 0) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            strcpy(words[count].word, buffer);
            count++;
        }
    }

    qsort(words, count, sizeof(Word), compare);

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i].word);
    }

    return 0;
}