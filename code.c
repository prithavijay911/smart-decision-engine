#include <stdio.h>
#include <string.h>
#include "decision_engine.h"
#include "utils.h"

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
    option_count = get_count("Enter number of options: ");

    if (option_count < 2 || option_count > MAX_OPTIONS) {
        printf("Invalid number of options.\n");
        return 0;
    }

    // Input options
    get_strings("Enter options:", options, option_count);

    // Input number of factors
    factor_count = get_count("\nEnter number of factors: ");

    if (factor_count < 1 || factor_count > MAX_FACTORS) {
        printf("Invalid number of factors.\n");
        return 0;
    }

    // Input factors
    get_strings("Enter factors:", factors, factor_count);

    // Input weights
    printf("\nAssign weights (0–10):\n");
    for (int i = 0; i < factor_count; i++) {
        weights[i] = get_float(factors[i]);
    }

    // Calculate scores
    for (int i = 0; i < option_count; i++) {
        printf("\nScoring for %s:\n", options[i]);
        scores[i] = 0;

        for (int j = 0; j < factor_count; j++) {
            float score = get_float(factors[j]);
            scores[i] += score * weights[j];
        }
    }

    // Find best option
    int best_index = find_best_option(scores, option_count);

    // Print results
    print_results(options, scores, option_count, best_index);

    return 0;
}
