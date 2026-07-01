#ifndef CLANDRO_AUTH_H
#define CLANDRO_AUTH_H

#include <stdbool.h>

#ifdef __ANDROID__
# ifndef CLANDRO_HOME
#  define CLANDRO_HOME "/data/data/com.zk.clandro/files/home"
# endif
# ifndef CLANDRO_PREFIX
#  define CLANDRO_PREFIX "/data/data/com.zk.clandro/files/usr"
# endif
# define AUTH_HASH_FILE_PATH CLANDRO_HOME "/.clandro_authinfo"
#else
# define AUTH_HASH_FILE_PATH "/tmp/access_hash"
#endif

#ifdef  __cplusplus
extern "C" {
#endif

// Hash password using PBKDF function.
// Returns digest (in binary form) or NULL if failed.
unsigned char *clandro_passwd_hash(const char *password);

// Update file that stores password hash
// Return true on success, false otherwise.
bool clandro_change_passwd(const char *new_password);

// Remove file that stores password hash
// Return true on success, false otherwise.
bool clandro_remove_passwd(void);

// Check validity of password (user name is ignored).
// Return true if password is ok, otherwise return false.
bool clandro_auth(const char *user, const char *password);

#ifdef  __cplusplus
}
#endif

#endif
