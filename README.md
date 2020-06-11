# Keyboard Levenshtein

Compute the misspelled words in a corpus with weighted `substitutes` with respect to Levenshtein distances. These weights are assigned ad hoc, with respect to the distance between keys on a QWERTY keyboard.

Words are compared against words beginning with the same letter and words that begin with the word's second letter, and the 300 most common English words.

## Usage
Given that the necessary files are within the same directory (see *Files* section), can compile with:

    $ g++ main.cc

can execute with:

    $ ./a.out

## Details
Costs are assigned as follows:
* `insert` has a constant cost of 2 (can be changed `INS_COST` variable)
* `delete` has a constant cost of 2 (can be changed `DEL_COST` variable)
* `swap` (two adjacent characters) has a constant cost of 1 (can be changed `SWP_COST` variable)
* `substitute` is dependent on the distance between the character and the character to be substituted. If the key is immediately adjacent, the cost is 1. If the key is adjacent to any of those keys, then the cost is 2. Every other key has cost 3. These values can be modified in the `distMatrix`.

*Note*: The ratio between these operations is important as to favor some operations, but not totally rule out other operations.


## Files

* `corpus.txt` defines the input text. Currently, the program is not reliable when the corpus contains capital letters and punctuation other than periods.
* `dictionary.txt` defines a complete dictionary. Custom words can be added.
* `common.txt` defines the 300 most common English words. More words can be added.

## Future

* Weighted `insert` for quick double taps that aren't accounted for. For example *presed* should have priority to *pressed* over the word *preed*. (In the current model, both have distance 2)
* Weighted `delete` for accidentally pressing unintended keys. For example *tyuple*, where the intended word is *tuple*.
