//
// Created by Kaloyan Petkov on 26.07.24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[k - 1][m - 1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1];
}

char**** get_document(char* text) {
    int curr_word_length = 1;
    char *curr_word = malloc(curr_word_length);

    int curr_sentence_length = 0;
    char **curr_sentence = malloc(curr_sentence_length);

    int curr_paragraph_length = 0;
    char ***curr_paragraph = malloc(curr_paragraph_length * sizeof(char **));

    int curr_document_length = 0;
    char ****curr_document = malloc(curr_document_length * sizeof(char ***));

    for (int i = 0; i < strlen(text); i++) {
        bool end_of_word = text[i] == ' ';
        bool end_of_sentence = text[i] == '.' || text[i] == '?' || text[i] == '!';
        bool end_of_paragraph = text[i] == '\n';
        if (end_of_word || end_of_sentence || end_of_paragraph) {

            // build document
            if (end_of_paragraph) {
                curr_document_length++;
                curr_document = realloc(curr_document, curr_document_length * sizeof(char ***));
                curr_document[curr_document_length - 1] = curr_paragraph;

                curr_paragraph_length = 0;
                curr_paragraph = malloc(curr_paragraph_length);
                continue;
            }

            // build sentence
            curr_word[curr_word_length - 1] = '\0';
            curr_sentence_length++;
            size_t curr_sentence_size = curr_sentence_length * sizeof(char *);
            curr_sentence = realloc(curr_sentence, curr_sentence_size);
            curr_sentence[curr_sentence_length - 1] = malloc(strlen(curr_word));
            strcpy(curr_sentence[curr_sentence_length - 1], curr_word);

            // build paragraph
            if (end_of_sentence) {
                curr_paragraph_length++;
                curr_paragraph = realloc(curr_paragraph, curr_paragraph_length * sizeof(char **));
                curr_paragraph[curr_paragraph_length - 1] = curr_sentence;

                curr_sentence_length = 0;
                curr_sentence = malloc(curr_sentence_length);
            }

            curr_word_length = 1;
            curr_word = malloc(curr_word_length);
            continue;
        }

        // Build word
        curr_word_length++;
        curr_word = realloc(curr_word, curr_word_length);
        curr_word[curr_word_length - 2] = text[i];
    }

    curr_document_length++;
    curr_document = realloc(curr_document, curr_document_length * sizeof(char ***));
    curr_document[curr_document_length - 1] = curr_paragraph;

    free(curr_word);
    free(curr_sentence);
    free(curr_paragraph);

    return curr_document;
}

void print_sentence(char** sentence, int word_count) {
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
}

void print_paragraph(char*** paragraph, int sentence_count, int words_count) {
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i), words_count);
        printf(".");
    }
}
