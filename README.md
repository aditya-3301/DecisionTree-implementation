# Decision Tree and Random Forest Implementation for Titanic Survival Prediction

This project implements custom Decision Tree and Random Forest algorithms from scratch in Python to predict passenger survival on the Titanic dataset. The implementation includes data preprocessing, feature engineering, and model training.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Data](#data)
- [Model Details](#model-details)
- [Results](#results)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Overview

This project demonstrates the implementation of fundamental machine learning algorithms:
- **Decision Tree Classifier**: A tree-based model that makes decisions by learning simple decision rules inferred from the data features.
- **Random Forest Classifier**: An ensemble method that constructs multiple decision trees and merges their predictions to improve accuracy and reduce overfitting.

The models are applied to the famous Titanic dataset to predict whether passengers survived based on features like age, sex, passenger class, etc.

## Features

- Custom implementation of Decision Tree with Gini impurity splitting
- Random Forest ensemble with bootstrap sampling and random feature selection
- Feature engineering including age categorization and family size calculation
- Handling of categorical and numerical features
- Model evaluation with accuracy metrics
- Visualization of model performance across different tree depths

## Installation

1. Clone this repository:
```bash
git clone https://github.com/yourusername/decision-tree-titanic.git
cd decision-tree-titanic
```

2. Install the required dependencies:
```bash
pip install pandas numpy matplotlib scikit-learn
```

## Usage

### Running the Decision Tree and Random Forest Implementation

1. Open the `Decision_tree.ipynb` notebook in Jupyter:
```bash
jupyter notebook Decision_tree.ipynb
```

2. The notebook includes:
   - Data loading and preprocessing
   - Feature engineering
   - Decision Tree class implementation
   - Random Forest class implementation
   - Model training and evaluation
   - Hyperparameter tuning

### Demo

For a quick demonstration, run the `Demo.ipynb` notebook which loads and displays the Titanic dataset.

## Data

The project uses the Titanic dataset from Kaggle:
- **train.csv**: Training data with 891 passengers and 11 features
- **test.csv**: Test data with 418 passengers

### Key Features:
- `PassengerId`: Unique passenger identifier
- `Survived`: Survival status (0 = No, 1 = Yes) - Target variable
- `Pclass`: Ticket class (1 = 1st, 2 = 2nd, 3 = 3rd)
- `Name`: Passenger name
- `Sex`: Gender
- `Age`: Age in years
- `SibSp`: Number of siblings/spouses aboard
- `Parch`: Number of parents/children aboard
- `Ticket`: Ticket number
- `Fare`: Passenger fare
- `Cabin`: Cabin number
- `Embarked`: Port of embarkation (C = Cherbourg, Q = Queenstown, S = Southampton)

## Model Details

### Decision Tree Implementation
- Uses Gini impurity as the splitting criterion
- Supports both numerical and categorical features
- Implements depth limiting to prevent overfitting
- Includes min_samples_split parameter for controlling tree growth

### Random Forest Implementation
- Constructs multiple decision trees using bootstrap sampling
- Implements random feature selection at each split
- Uses majority voting for final predictions
- Configurable number of trees, max depth, and feature subset size

### Feature Engineering
- Age categorization into groups (Child, Teen, YoungAdult, Adult, Senior)
- Family size calculation (SibSp + Parch + 1)
- IsAlone feature (whether passenger traveled alone)
- Title extraction from passenger names

## Results

The best-performing Random Forest model achieved **81.56% validation accuracy** with the following hyperparameters:
- Number of trees: 50
- Maximum depth: 4
- Minimum samples split: 5
- Max features: sqrt

### Performance Analysis
- Accuracy improves with increasing tree depth up to 4, then plateaus or slightly declines
- Increasing the number of trees improves performance, with diminishing returns after 50 trees
- The optimal depth of 4 balances bias and variance

For detailed results and analysis, see `Report on the RandomForest Implementation.pdf`.

## Project Structure

```
decision-tree-titanic/
│
├── Decision_tree.ipynb          # Main implementation notebook
├── Demo.ipynb                   # Data demonstration notebook
├── train.csv                    # Training dataset
├── test.csv                     # Test dataset
├── Optimum_Depth.png            # Accuracy vs depth visualization
├── Report on the RandomForest Implementation.pdf  # Detailed analysis report
├── .gitignore                   # Git ignore file
└── README.md                    # This file
```
