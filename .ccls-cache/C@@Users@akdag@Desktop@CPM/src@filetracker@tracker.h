#ifndef TRACKER_H
#define TRACKER_H

#include <stdbool.h>

#define SAVE_FILE "MEMBERS"

/**
 * @brief Prints the name of a directory entry.
 * @param dir The directory entry.
 */
void print_dirent(void *dir);

/**
 * @brief Checks if the given path corresponds to a directory.
 * @param path The path to check.
 * @return 1 if the path is a directory, 0 otherwise.
 */
int is_directory(const char *path);

/**
 * @brief Checks if the given filename has a specific extension.
 * @param filename The name of the file.
 * @param extension The extension to check.
 * @return true if the file has the specified extension, false otherwise.
 */
bool check_extension(char* filename, char* extension);

/**
 * @brief Recursively finds members in the specified directory and its subdirectories.
 * @param origin The starting directory.
 * @param location The relative location of the current directory.
 */
void find_members(char* origin, char* location);

/**
 * @brief Creates a MEMBERS file and writes the header and implementation file lists.
 * @param origin The directory path.
 */
void make_members(char* origin);

/**
 * @brief Calls the tracker functionality to find and list header and implementation files.
 * @param origin_path The path of the directory to start tracking from.
 * @return 0 on success.
 */
int call_tracker(char* origin_path, char* target_name, char* makepath_name, char *ext_extension);

char* retrieve_config(const char* section, const char *setting);

#endif