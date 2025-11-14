/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 20920                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/20920                          #+#        #+#      #+#    */
/*   Solved: 2025/11/14 01:36:07 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 100000
#define MAX_LEN 11

typedef struct {
    char word[MAX_LEN];
    int freq;
    int len;
} Word;

int compare(const void *a, const void *b) {
    Word *wa = (Word*)a;
    Word *wb = (Word*)b;

    if (wa->freq != wb->freq) {
        return wb->freq - wa->freq;
    }

    if (wa->len != wb->len) {
        return wb->len - wa->len;
    }

    return strcmp(wa->word, wb->word);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Word words[MAX_N];
    int word_count = 0;

    for (int i = 0; i < n; i++) {
        char input[MAX_LEN];
        scanf("%s", input);

        int len = strlen(input);

        if (len < m) continue;

        int found = -1;
        for (int j = 0; j < word_count; j++) {
            if (strcmp(words[j].word, input) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            words[found].freq++;
        } else {
            strcpy(words[word_count].word, input);
            words[word_count].freq = 1;
            words[word_count].len = len;
            word_count++;
        }
    }

    qsort(words, word_count, sizeof(Word), compare);

    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i].word);
    }

    return 0;
}