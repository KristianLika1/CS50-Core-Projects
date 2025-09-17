import csv
import sys
import os


def main():

    # TODO: Check for command-line usage
    n_of_args = len(sys.argv)
    if not n_of_args == 3:
        print("The number of command-line arguments must be 2")
        exit()
    filename1 = sys.argv[1]
    filename2 = sys.argv[2]
    name, extension1 = os.path.splitext(filename1)
    name, extension2 = os.path.splitext(filename2)

    if not extension1 == '.csv' and not extension2 == '.txt':
        print("The first command-line argument has to be a CSV file, the second a txt file")
        exit()

    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as file:
        csv_reader = csv.DictReader(file)
        list_of_dictionaries = []
        for row in csv_reader:
            list_of_dictionaries.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:
        dna_sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    longest_matches = {}
    for row in list_of_dictionaries:
        for STR in row.keys():
            if STR != "name":
                longest_matches[STR] = longest_match(dna_sequence, STR)

    # TODO: Check database for matching
    found = False
    for row in list_of_dictionaries:
        match = 0
        for STR in longest_matches:
            if int(row[STR]) == int(longest_matches[STR]):
                match += 1
        if match == len(longest_matches):
            found = True
            name = row["name"]
    if found == True:
        print(name)
    else:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
