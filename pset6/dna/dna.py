import csv
import sys


DNA_rows = []
Fieldnames = []
longest_runs = []

def main():

    if len(sys.argv) != 3:
            print("Incorrect arguments. Usage: python DNA.py data.csv sequence.txt")
            return 1

    dataname = sys.argv[1]
    dnaname = sys.argv[2]

    with open(dataname) as datafile:
        reader = csv.DictReader(datafile)
        Fieldnames = reader.fieldnames
        for row in reader:
             DNA_rows.append(row)


    # TODO: Read DNA sequence file into a variable
    with open(dnaname) as dnafile:
        dna_sequence = dnafile.read()

    # TODO: Find longest match of each STR in DNA sequence
    for i in range(1, len(Fieldnames)):
        longest_runs.append(longest_match(dna_sequence, Fieldnames[i]))

    # TODO: Check database for matching profiles
    check = 0

    for row in DNA_rows:
        for person in DNA_rows:
            check = 0
            for i in range(1, len(Fieldnames)):
                if int(person[Fieldnames[i]]) == longest_runs[i - 1]:
                    check += 1
                    if check == len(Fieldnames) - 1:
                        print(person["name"])
                        return


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

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
