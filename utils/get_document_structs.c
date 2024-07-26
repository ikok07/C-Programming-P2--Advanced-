//
// Created by Kaloyan Petkov on 26.07.24.
//

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

struct document get_document(char* text) {
    int curr_word_length = 1;
    struct word *curr_word = malloc(sizeof(struct word));
    curr_word->data = NULL;

    int curr_sentence_length = 0;
    struct sentence *curr_sentence = malloc(sizeof(struct sentence));
    curr_sentence->data = NULL;

    int curr_paragraph_length = 0;
    struct paragraph *curr_paragraph = malloc(sizeof(struct paragraph));
    curr_paragraph->data = NULL;

    int curr_document_length = 0;
    struct document *curr_document = malloc(sizeof(struct document));
    curr_document->data = NULL;

    for (int i = 0; i < strlen(text); i++) {
        bool end_of_word = text[i] == ' ';
        bool end_of_sentence = text[i] == '.' || text[i] == '?' || text[i] == '!';
        bool end_of_paragraph = text[i] == '\n';
        if (end_of_word || end_of_sentence || end_of_paragraph) {

            // build document
            if (end_of_paragraph) {
                curr_document_length++;
                curr_document->data = realloc(curr_document->data, sizeof(struct paragraph) * curr_document_length);
                curr_document->data[curr_document_length - 1] = *curr_paragraph;
                curr_document->paragraph_count = curr_document_length;

                curr_paragraph_length = 0;
                curr_paragraph->data = NULL;
                continue;
            }

            // build sentence
            curr_word->data[curr_word_length - 1] = '\0';
            curr_sentence_length++;
            curr_sentence->data = realloc(curr_sentence->data, sizeof(struct word) * curr_sentence_length);

            curr_sentence->data[curr_sentence_length - 1] = *curr_word;
            curr_sentence->word_count = curr_sentence_length;
            // build paragraph
            if (end_of_sentence) {
                curr_paragraph_length++;
                curr_paragraph->data = realloc(curr_paragraph->data, sizeof(struct sentence) * curr_paragraph_length);
                curr_paragraph->data[curr_paragraph_length - 1] = *curr_sentence;
                curr_paragraph->sentence_count = curr_paragraph_length;

                curr_sentence_length = 0;
                curr_sentence->data = NULL;
            }

            curr_word_length = 1;
            curr_word->data = malloc(1);
            continue;
        }

        // Build word
        curr_word_length++;
        curr_word->data = realloc(curr_word->data, curr_word_length);
        curr_word->data[curr_word_length - 2] = text[i];
    }

    curr_document_length++;
    curr_document->data = realloc(curr_document->data, sizeof(struct paragraph) * curr_document_length);
    curr_document->data[curr_document_length - 1] = *curr_paragraph;

//    free(curr_word->data);
    free(curr_word);
//    free(curr_sentence->data);
    free(curr_sentence);
//    free(curr_paragraph->data);
    free(curr_paragraph);

    return *curr_document;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}