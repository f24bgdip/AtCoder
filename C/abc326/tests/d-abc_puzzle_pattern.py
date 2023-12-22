def generate_patterns(pattern, remaining_chars, patterns):
    # Base case: if there are no remaining characters, add the pattern to the list
    if not remaining_chars:
        if pattern not in patterns:
            patterns.append(pattern)
        return

    # Recursive case: try adding each remaining character to the pattern
    for i, char in enumerate(remaining_chars):
        new_pattern = pattern + char
        new_remaining_chars = remaining_chars[:i] + remaining_chars[i+1:]
        generate_patterns(new_pattern, new_remaining_chars, patterns)

# Initialize an empty list to hold the patterns
patterns = []

# Call the function to generate patterns
generate_patterns("", "ABC  ", patterns)

# Print the number of valid patterns
print(len(patterns))

# Print each pattern on a new line
print(patterns)