// meal.c
// Include the necessary libraries
#include <stdio.h>      // Input/output

// Define an enumeration to represent the meal
enum meal {
    NOT_MEAL_TIME_YET = 20,
    BREAKFAST = 7,
    LUNCH = 12,
    DINNER = 18,
    MEAL_DURATION = 1,
    HOUR_PER_DAY = 24,
};

/**
 * Get the meal that is being served at the given hour
 * @param [in] hour the current hour
 * @return the meal that is being served at the given hour
 *       or NOT_MEAL_TIME_YET plus the time left to the next 
 *       meal if it is not meal time yet
**/
int get_meal(int hour) {
    // If it is breakfast time
    if (hour >= BREAKFAST && hour < BREAKFAST + MEAL_DURATION) {
        return BREAKFAST;
    // If it is lunch time
    } else if (hour >= LUNCH && hour < LUNCH + MEAL_DURATION) {
        return LUNCH;
    // If it is dinner time
    } else if (hour >= DINNER && hour < DINNER + MEAL_DURATION) {
        return DINNER;
    // If it is not meal time yet
    } else {
        int next_meal;
        if (hour < BREAKFAST) {
            next_meal = BREAKFAST - hour;
        } else if (hour < LUNCH) {
            next_meal = LUNCH - hour;
        } else if (hour < DINNER) {
            next_meal = DINNER - hour;
        } else {
            next_meal = HOUR_PER_DAY - hour + BREAKFAST;
        }
        return next_meal + NOT_MEAL_TIME_YET;
    }
}

/** 
 * Print the meal that is being served at the given hour
 * @param [in] meal information about the meal that is being served
**/
void print_meal(int meal) {
    // Print the meal that is being served at the given hour
    switch (meal)
    {
    case BREAKFAST:
        printf("Breakfast\n");
        break;
    case LUNCH:
        printf("Lunch\n");
        break;
    case DINNER:
        printf("Dinner\n");
        break;
    default:
        printf("The next meal is in %d hours\n", meal - NOT_MEAL_TIME_YET);
        break;
    }
}

// Main function
int main() {
    // Declare a variable to hold the current hour
    int hour;
    // Prompt the user to enter the current hour
    printf("Enter the current hour: ");
    scanf("%d", &hour);

    // Get the meal that is being served at the given hour
    int meal = get_meal(hour);

    // Print the meal that is being served at the given hour
    print_meal(meal);

    // Return 0 to indicate success
    return 0;
}