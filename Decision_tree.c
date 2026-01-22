#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_ROWS 1000

// Define a structure for a Passenger
typedef struct {
    int survived;
    char name[MAX_NAME_LENGTH];
    int sex;  // Use int to store 1 for male and 0 for female
    int age;  // Use -1 for missing age (instead of 0)
    char embarked[2];
} Passenger;

// Function to read the CSV file and parse the data
int read_csv(const char *filename, Passenger passengers[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    
    char line[1024];
    int i = 0;
    
    // Read the header
    fgets(line, sizeof(line), file);

    // Read each data row
    while (fgets(line, sizeof(line), file)) {
        char *token;
        
        // Tokenize and assign values to passenger struct
        token = strtok(line, ",");
        passengers[i].survived = atoi(token);
        
        token = strtok(NULL, ",");
        strncpy(passengers[i].name, token, MAX_NAME_LENGTH);
        
        token = strtok(NULL, ",");
        // Map 'male' to 1, 'female' to 0
        if (strcmp(token, "male") == 0) {
            passengers[i].sex = 1;
        } else if (strcmp(token, "female") == 0) {
            passengers[i].sex = 0;
        } else {
            passengers[i].sex = -1;  // For unexpected values
        }
        
        token = strtok(NULL, ",");
        passengers[i].age = (strcmp(token, "") == 0) ? -1 : atoi(token);  // Use -1 for missing age
        
        token = strtok(NULL, ",");
        strncpy(passengers[i].embarked, token, 2);
        
        i++;
    }

    fclose(file);
    return i;
}

// Function to replace missing age with the median age
void handle_missing_age(Passenger *passengers, int num_passengers) {
    int sum = 0;
    int count = 0;
    
    // Calculate the sum of all ages and count valid ages
    for (int i = 0; i < num_passengers; i++) {
        if (passengers[i].age != -1) {
            sum += passengers[i].age;
            count++;
        }
    }
    
    if (count == 0) return;  // Avoid division by zero
    
    // Find the median age
    int median = sum / count;
    
    // Replace missing ages with median
    for (int i = 0; i < num_passengers; i++) {
        if (passengers[i].age == -1) {
            passengers[i].age = median;
        }
    }
}

// Function to calculate Gini Impurity
double gini_impurity(int *labels, int num_labels) {
    if (num_labels == 0) return 0;  // Avoid division by zero
    
    int count_pos = 0;
    int count_neg = 0;
    
    // Count positive and negative labels
    for (int i = 0; i < num_labels; i++) {
        if (labels[i] == 1) {
            count_pos++;
        } else {
            count_neg++;
        }
    }
    
    double prob_pos = (double)count_pos / num_labels;
    double prob_neg = (double)count_neg / num_labels;
    
    return 1 - (prob_pos * prob_pos + prob_neg * prob_neg);
}

int main() {
    Passenger train_data[MAX_ROWS];
    int num_train = read_csv("titanic_train_small.csv", train_data);
    
    if (num_train == -1) return 1;
    
    // Preprocess the data
    handle_missing_age(train_data, num_train);  // Handle missing age
    
    // Display first few records (just for checking)
    for (int i = 0; i < 5; i++) {
        printf("Passenger %d: %s, %d, %d, %s\n", i+1, train_data[i].name, train_data[i].sex, train_data[i].age, train_data[i].embarked);
    }
    
    // Decision Tree Example: Prepare the labels
    int labels[MAX_ROWS];
    for (int i = 0; i < num_train; i++) {
        labels[i] = train_data[i].survived;
    }
    
    // Calculate Gini Impurity
    double gini = gini_impurity(labels, num_train);
    printf("Gini Impurity: %f\n", gini);
    
    return 0;
}
