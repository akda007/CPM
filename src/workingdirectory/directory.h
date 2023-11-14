#ifndef DIRECTORY_H
#define DIRECTORY_H

/**
 * @file directory.h
 * @brief Declarations for functions related to directory operations.
 */

#include <stdbool.h>

/**
 * @brief Gets the current working directory.
 * @param cwd Buffer to store the current working directory.
 * @param size Size of the buffer.
 * @return true if the current working directory is successfully obtained, false otherwise.
 */
bool getDirectory(char* cwd, int size);

/**
 * @brief Creates a new directory.
 * @param cwd The current working directory.
 * @param newname The name of the new directory to be created.
 * @return true if the directory is created successfully, false otherwise.
 */
bool newdirectory(const char* cwd, const char* newname);

/**
 * @brief Initializes a new Git repository in the current working directory.
 * @param cwd The current working directory.
 * @return true if the Git repository is successfully created, false otherwise.
 */
bool gitInit(const char* cwd);

#endif /* DIRECTORY_H */
