# Pseudocode Breakdown v1

-----
**Note from Julian**: This write-up is not complete guide to Assignment 3. I have included *some* details regarding implementation in C++, but have omitted giving solutions. Instead, this should serve as a conceptual guide on how to approach the requirements given by the assignment. After all, this write-up is only a breakdown of *my* pseudocode for this assignment.

-----

## Prerequisites

- understand `char` type
- understand `string` library
- understand `for` loops
- understand `while` loops
- basic understanding of arrays

Here the pseudocode is written in **python-like** language for readability.

**Note:** Python comments are prefixed with `#` instead of `\\` like in C++.

```python
# initialize important variables
input_chars[3]
chars = 0

# prompt user for input
print(input_prompt)

# begin input loop
while chars < 3:
    # read line inputted by user
    input_line = input(delimiter='\n')

    # get letters from line
    for chr in input_line:
        if chr_is_letter:
            input_chars.add(chr)

            # count letters
            chars += 1

# sort letters
output_string = sorted(input_chars)

# output sorted letters to user
print(output_string)
```

This program will have an *input loop*, where we will continue looping through a procedure until the user gives us all the information we want.

During the input loop, we will take each line of input and filter out the letters. We then count the number of letters given and loop again to get another line if we don't have enough letters.

Once we have all three letters, the loop is terminated and the program sorts the results, which are then output to the user.

## Initial Variables

First, the initial variables must be declared:
```python
input_chars[3]
chars = 0
```
The array `input_chars[3]` will contain our three characters that the user will input, and `chars` will count the number of characters given by the user during the input loop.

## Input Loop

Per the requirements of the assignment, we then prompt the user with instructions on entering the letters.
```python
print(input_prompt)
```
From here, the program enters the input loop.
```python
while chars < 3:
```
We only need to loop until we have three letters, so we use the previously initialized `chars` variable to count those letters and terminate the input loop when we are satisfied with the input.


For each iteration of the input loop, we will read the line input given by the user:
```python
input_line = input(delimeter='\n')
```
**Note:** `delimeter='\n'` reads as "stop reading at newline (or when user presses enter)". By default, C++'s `std::cin` from `iostream` and child methods only read single lines by default. This means we don't have an individual method that can read multiple lines, hence why we are using an input loop.

**Tip:** Reading the input from the user is the hardest part of this assignment. Not only must the program identify if the inputted characters are letters, but it must also handle *potential* whitespaces (i.e. spaces `' '`, tabs `'\t'`, or newlines (enter key) `'\n'`) and multi-character inputs. Therefore, the variable that stores the input line from the user cannot be of type `char`, but rather a data type that can store *multiple* `char`s. Then, this *string* of `char`s could iterated through and checked to see if they're letters. Handling whitespaces on the other hand will involve a "function" from `std::cin`. <!-- The stream extraction operation `std::cin >> foo` (`foo` is an informal stand-in for any variable) will stop reading the input at any whitespace (i.e. spaces `' '`, tabs `'\t'`, or newlines (enter key) `'\n'`). So, the user input `"a b"` to `std::cin` will -->

From here, each line must be filtered for the desired letters. To do this, we need to created another loop that looks through each character in the inputted line and check if each character is a letter. If it is a letter, we add it to our `input_chars` array.
```python
for chr in input_line:
    if chr_is_letter:
        input_chars.add(chr)
        chars += 1
```
Keep in mind that `chars` is incremented for every letter found.

Once each character in the input line has been looked at, the input loop repeats and asks for another input line from the user. As stated before, this input loop will terminate once we have 3 characters from the user.

## Sorting the Letters

```python
output_string = sorted(input_chars)
```

You should implement a similar sorting procedure that was covered in Lab 1, but as specified by the assignment details, it should be non-complex and only involve if-statements.

**Note:** Uppercase letters have different ASCII codes then lowercase letters. For example, `'B'` has an index of 65, whereas `'a'` has an index of 97, so the string `"aB"` will be sorted as `"Ba"`. Therefore, you must convert all letters to the same case before comparing them.
