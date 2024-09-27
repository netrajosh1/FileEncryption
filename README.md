# FileEncryption

This project is a simple file encryption and decryption utility. It reads a file, encrypts its contents using a user-provided key, and writes the encrypted data to an output file. The program can also decrypt an encrypted file by using the same key.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Build and Compilation](#build-and-compilation)
- [Key Functions](#key-functions)
- [Limitations](#limitations)

## Overview

The `FileEncryption` program encrypts or decrypts a given file by applying a bitwise XOR operation using an 8-bit secret key. It also validates user input to ensure that the key is valid and the filenames are within appropriate limits.

The encryption process is reversible, which means the same operation can be used to decrypt an encrypted file.

## Features
- **File Encryption**: Encrypts input files and saves the encrypted content to a new output file.
- **File Decryption**: Decrypts files that were encrypted using the same key.
- **Key Validation**: The encryption key must be exactly 8 bits long.
- **Filename Validation**: The filename must be a valid string of up to 20 characters.
- **Dynamic Memory Handling**: Allocates memory as needed to store and process files.
- **Key Conversion**: Converts a binary key (input as a string) into an 8-bit integer for encryption.

## How It Works

1. **Input**: The program takes two command-line arguments:
   - A key: An 8-character binary string (e.g., `10101010`).
   - A filename: A string representing the file to be encrypted or decrypted.
   
2. **Process**:
   - **Key Conversion**: Converts the binary string into an integer using bitwise operations.
   - **File Reading**: Opens the specified file for reading.
   - **Encryption**: Applies the XOR operation between each byte of the file and the key.
   - **File Writing**: Writes the encrypted (or decrypted) bytes to an output file.

3. **Output**: The output file has the same name as the input file, but with a `.enc` extension (if encryption). For decryption, the `.enc` extension is removed.

## Usage

### Command Line
To run the program, use the following command:

```bash
./encryptafile <8-bit_key> <input_filename>
```

## Build and Compilation
The project uses a simple Makefile to manage compilation (view: Makefile file in repository).

Steps to Build:
- Ensure you have a C compiler (like gcc) installed.
- Run the following command to compile the program:
```bash
make
```
This will generate an executable called encryptafile.

## Key Functions
This section outlines the key functions implemented in the FileEncryption Application, along with their descriptions and parameters.

### fileprocess

```c
fileprocess(int key, FILE *in, FILE *out)
```

Description
- Reads each character from the input file.
- XORs the character with the key.
- Writes the result to the output file.

### keyconvert

```c
keyconvert(struct secretkeybits keystr, int *key)
```

Description
- Converts a struct secretkeybits containing the key bits into an integer key.

### outputfilename

```c
outputfilename(char *inputfile)
```

Description
- Sets the output filename based on the input file name.
- Adds or removes the .enc extension depending on the context.

### readspecs

```c
readspecs(userinput_t *datastruct, char *com_key, char *com_filename)
```

Description
- Validates the key and filename from the command line.
- Populates the userinput_t struct with validated data.

## Limitations
- Key Length: The key must be exactly 8 bits long.
- Filename Length: Filenames cannot exceed 20 characters.
- Line Lengths: The code does not handle lines longer than 25 characters when reading files.
- Binary Files: This program should not be used for encrypting binary files, as it may not handle special characters or non-ASCII data well.





