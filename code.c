#include <stdio.h>

#define MAX_OPTIONS 10
#define MAX_FACTORS 10

int main() {
    char options[MAX_OPTIONS][50];
    char factors[MAX_FACTORS][50];
    float weights[MAX_FACTORS];
    float scores[MAX_OPTIONS];

    int option_count, factor_count;

    printf("\n=====================================\n");
    printf("     LIFE DECISION SIMULATOR\n");
    printf("=====================================\n\n");

    // Input number of options
    printf("Enter number of options: ");
    scanf("%d", &option_count);

    if (option_count < 2 || option_count > MAX_OPTIONS) {
        printf("Invalid number of options.\n");
        return 0;
    }

    // Input options
    printf("\nEnter options:\n");
    for (int i = 0; i < option_count; i++) {
        printf("Option %d: ", i + 1);
        scanf("%s", options[i]);
    }

    // Input number of factors
    printf("\nEnter number of factors: ");
    scanf("%d", &factor_count);

    if (factor_count < 1 || factor_count > MAX_FACTORS) {
        printf("Invalid number of factors.\n");
        return 0;
    }

    // Input factors
    printf("\nEnter factors:\n");
    for (int i = 0; i < factor_count; i++) {
        printf("Factor %d: ", i + 1);
        scanf("%s", factors[i]);
    }

    // Input weights
    printf("\nAssign weights (0–10):\n");
    for (int i = 0; i < factor_count; i++) {
        printf("Weight for %s: ", factors[i]);
        scanf("%f", &weights[i]);
    }

    // Calculate scores
    for (int i = 0; i < option_count; i++) {
        printf("\nScoring for %s:\n", options[i]);
        scores[i] = 0;

        for (int j = 0; j < factor_count; j++) {
            float score;
            printf("Score for %s: ", factors[j]);
            scanf("%f", &score);

            scores[i] += score * weights[j];
        }
    }

    // Find best option
    int best_index = 0;
    for (int i = 1; i < option_count; i++) {
        if (scores[i] > scores[best_index]) {
            best_index = i;
        }
    }

    // Output results
    printf("\n=========== RESULTS ===========\n");
    for (int i = 0; i < option_count; i++) {
        printf("%s : %.2f\n", options[i], scores[i]);
    }

    printf("\nRecommended Decision: %s\n", options[best_index]);
    printf("================================\n");

    return 0;
}
}
