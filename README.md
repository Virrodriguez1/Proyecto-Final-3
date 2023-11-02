
# Inventory Management System

## Project Description
This project is an inventory management system built in C++ for a company to manage its daily physical inventory. The application processes a CSV file containing a list of products with QR codes and stock levels across various depots.

## Features
- Read data from a CSV file.
- Display the total number of unique articles.
- Show the total number of articles.
- List articles at minimum stock level.
- List articles at minimum stock by depot.
- Show individual stock level for each article.
- Display individual stock level for each article by depot.
- Identify articles with stock equal to or exceeding a certain amount.

## Prerequisites
- C++ compiler (GCC recommended)
- Make (for building the project)

## Building the Project
Navigate to the project directory and run:
\`\`\`
make
\`\`\`

## Usage
Run the program using the following command:
\`\`\`
./bin/Processor_inventory [arguments] data/inventory_physical.csv
\`\`\`

## Arguments
- `-total_art_dif` - Display the total number of different articles.
- `-total_art` - Display the total number of articles.
- More arguments to be defined...

## Data Structure
The program uses hash tables to store and manage inventory data efficiently.

## License
This project is licensed under the MIT License - see the LICENSE.md file for details.

## Authors
- Virginia Rodriguez

## Acknowledgments
- Thanks to the Programming III course staff for providing the guidelines and requirements for this project.
